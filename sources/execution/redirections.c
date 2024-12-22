/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/22 18:21:55 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static void	child(t_executor *e, int tgt)
{
	if (tgt != 0)
		dup2(e->fds[tgt][IN], STDIN_FILENO);
	if (tgt != e->chain_length - 1)
		dup2(e->fds[tgt][OUT], STDOUT_FILENO);
	close_pipes(e);
	execute_text_tree_node(e);
	exit(1);
}

static int	chain_parent(t_executor *e)
{
	int	i;
	int	res;

	close_pipes(e);
	i = -1;
	while (++i < e->chain_length)
	{
		res = parent(e->pids[i], &e->errno);
		if (e->errno != 0)
			return (1);
	}
	return (res);
}

static int	exec_chain(t_executor *e)
{
	int	i;

	free(e->pids);
	e->pids = ft_calloc_if(sizeof(pid_t) * e->chain_length, 1);
	if (!e->pids)
		return (ft_assign_i(&e->errno, 2, 2));
	i = -1;
	while (++i < e->chain_length)
	{
		if (takes_part_in_pipe(e->node))
		{
			e->pids[i] = fork();
			if (e->pids[i] == -1)
				return (ft_assign_i(&e->errno, 1, 1));
			if (e->pids[i] == 0)
				child(e, i);
		}
		if (e->node->sibling_next)
			e->node = e->node->sibling_next->sibling_next;
	}
	return (chain_parent(e));
}

static int	alloc(t_treenode *node, int ***fds, int *sz)
{
	int	i;

	*sz = 1;
	while (node && node->sibling_next
		&& is_pipe_or_redir(node->sibling_next->content))
	{
		(*sz)++;
		node = node->sibling_next->sibling_next;
	}
	*fds = ft_calloc_if(sizeof(int [2]) * (*sz), 1);
	if (!*fds)
		return (1);
	i = -1;
	while (++i < *sz)
	{
		(*fds)[i] = ft_calloc_if(sizeof(int) * 2, 1);
		if (!(*fds)[i])
		{
			while (--i >= 0)
				free((*fds)[i]);
			free(*fds);
			return (2);
		}
	}
	return (0);
}

/*
* not clear yet what to do with the first command of a chain,
* where is its input coming from... later
* */
int	redirections(t_executor *e)
{
	t_treenode	*node;
	int			i;

	if (alloc(e->node, &e->fds, &e->chain_length) != 0)
		return (ft_assign_i(&e->errno, 1, 1));
	node = e->node;
	i = -1;
	e->fds[0][IN] = IN;
	while (++i < e->chain_length)
	{
		e->fds[i][OUT] = OUT;
		if (i + 1 != e->chain_length)
			e->fds[i + 1][IN] = IN;
		if (node->sibling_next && is_pipe(node->sibling_next->content)
			&& setup_pipe(e, i) != 0)
			return (ft_assign_i(&e->errno, 2, 2));
		else if (node->sibling_next && setup_file(e, node, i) != 0)
			return (ft_assign_i(&e->errno, 3, 3));
		if (node->sibling_next)
			node = node->sibling_next->sibling_next;
	}
	if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FDS)
		ft_print_arr_i_2(e->fds, e->chain_length, 2);
	return (exec_chain(e));
}
