/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 12:16:56 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	exec_chain(t_executor *e)
{
	int			i;
	t_treenode	*node;

	free(e->pids);
	e->pids = ft_calloc_if(sizeof(pid_t) * e->chain_length, 1);
	if (!e->pids)
		return (ft_assign_i(&e->errno, 2, 2));
	i = -1;
	node = e->node;
	while (++i < e->chain_length)
	{
		if (!from_file(node))
		{
			e->pids[i] = fork();
			if (e->pids[i] == -1)
				return (ft_assign_i(&e->errno, 1, 1));
			if (e->pids[i] == 0 && child(e, i))
				return (ft_assign_i(&e->errno, 1, 2));
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
	*fds = ft_calloc_if(sizeof(int [2]) * (*sz + 1), 1);
	if (!*fds)
		return (1);
	i = -1;
	while (++i < *sz + 1)
	{
		(*fds)[i] = ft_calloc_if(sizeof(int) * 2, 1);
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
		if (to_pipe(node))
		{
			if (setup_pipe(e, i) != 0)
				return (ft_assign_i(&e->errno, 2, 2));
		}
		if (to_file(node) && setup_file(e, node, i) != 0)
			return (ft_assign_i(&e->errno, 3, 3));
		if (node->sibling_next)
			node = node->sibling_next->sibling_next;
	}
	if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
		ft_print_arr_i_2(e->fds, e->chain_length, 2);
	return (exec_chain(e));
}
