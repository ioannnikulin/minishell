/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/28 17:30:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	child(t_executor *e, int tgt)
{
	FT_FPRINTF(STDERR, "starting child %i\n", tgt);
	if (e->fds[tgt][TYPE] & (PIPE | LAST_IN_PIPE))
	{
		FT_FPRINTF(STDERR, "%i: dup2 in %i\n", tgt, e->fds[tgt][IN]);
		if (dup2(e->fds[tgt][IN], STDIN_FILENO) == -1)
		{
			FT_FPRINTF(STDERR, "%i: dup2 failed in %i\n", tgt, e->fds[tgt][IN]);
			return (ft_assign_i(&e->errno, 4, 4));
		}
	}
	if (e->fds[tgt][TYPE] & (PIPE | FIRST_IN_PIPE | TO_FILE))
	{
		FT_FPRINTF(STDERR, "%i: dup2 out %i\n", tgt, e->fds[tgt][OUT]);
		if (dup2(e->fds[tgt][OUT], STDOUT_FILENO) == -1)
		{
			
			FT_FPRINTF(STDERR, "%i: dup2 failed out %i\n", tgt, e->fds[tgt][OUT]);
			return (ft_assign_i(&e->errno, 5, 5));
		}
	}
	if (close_pipes(e, tgt))
		return (ft_assign_i(&e->errno, 6, 6));
	execute_text_tree_node(e);
	exit(0);
}

static int	chain_parent(t_executor *e)
{
	int	i;
	int	res;

	i = -1;
	while (++i < e->chain_length)
	{
		if (!(e->fds[i][TYPE] & ANY_FILE))
		{
			res = parent(e->pids[i], &e->errno);
			if (e->errno != 0)
				return (1);
		}
		if (i < e->chain_length - 1)
			e->node = e->node->sibling_next->sibling_next;
	}
	if (close_pipes(e, -1) || e->errno)
		return (ft_assign_i(&e->errno, 1, 1));
	e->param->opts.retval = res;
	e->retval = res;
	return (res);
}

static int	exec_chain(t_executor *e)
{
	int			i;
	t_treenode	*node;

	free(e->pids);
	e->pids = ft_calloc_if(sizeof(pid_t) * e->chain_length, 1);
	if (!e->pids)
		return (ft_assign_i(&e->errno, 7, 7));
	i = -1;
	node = e->node;
	while (++i < e->chain_length)
	{
		if (!(e->fds[i][TYPE] & ANY_FILE))
		{
			FT_FPRINTF(STDERR, "forking %i\n", i);
			e->pids[i] = fork();
			if (e->pids[i] == -1)
				return (ft_assign_i(&e->errno, 8, 8));
			if (e->pids[i] == 0 && child(e, i))
				return (ft_assign_i(&e->errno, 8, 8));
		}
		if (i != e->chain_length - 1)
			node = node->sibling_next->sibling_next;
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
	*fds = ft_calloc_if(sizeof(int *) * (*sz + 1), 1);
	if (!*fds)
		return (1);
	i = -1;
	while (++i < *sz + 1)
	{
		(*fds)[i] = ft_calloc_if(sizeof(int) * 3, 1);
		if (!(*fds)[i])
			return (2);
	}
	return (ft_assign_i(&(*fds)[0][IN], IN, 0));
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
	while (++i < e->chain_length)
	{
		e->fds[i][OUT] = OUT;
		if (i + 1 != e->chain_length)
			e->fds[i + 1][IN] = IN;
		if (takes_part_in_pipe(node))
		{
			if (setup_pipe(e, node, i) != 0)
				return (ft_assign_i(&e->errno, 2, 2));
		}
		if (takes_part_in_file(node))
		{
			if (setup_file(e, node, i) != 0)
				return (ft_assign_i(&e->errno, 13, 13));
		}
		if (node->sibling_next)
			node = node->sibling_next->sibling_next;
	}
	if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FDS)
		ft_print_arr_i_2(e->fds, e->chain_length, 3);
	return (exec_chain(e));
}
