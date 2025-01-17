/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 22:14:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	exec_chain(t_executor *e)
{
	int	i;

	i = 0;
	while (e->node)
	{
		if ((*get_node_type(e->node) & (IN_FILE | OUT_FILE)) == 0)
		{
			*get_node_pid(e->node) = fork();
			if (*get_node_pid(e->node) == -1)
				return (ft_assign_i(&e->errno, 1, 1));
			if (*get_node_pid(e->node) == 0 && child(e, i))
				return (ft_assign_i(&e->errno, 1, 2));
		}
		if (*get_node_type(e->node) & CHAIN_END)
			break ;
		e->node = next_node(e->node);
		i ++;
	}
	return (chain_parent(e));
}

/*
* not clear yet what to do with the first command of a chain,
* where is its input coming from... later
* */
int	redirections(t_executor *e)
{
	t_treenode	*node;
	int			i;

	node = e->node;
	i = -1;
	while (1)
	{
		if (setup_dev_null(e, node) != 0)
			return (ft_assign_i(&e->errno, 1, 1));
		if (setup_pipe(e, node, ++i) != 0)
			return (ft_assign_i(&e->errno, 2, 2));
		if (setup_out_file(e, node) != 0)
			return (ft_assign_i(&e->errno, 3, 3));
		if (setup_in_file(e, node) != 0)
			return (ft_assign_i(&e->errno, NO_IN_FILE, NO_IN_FILE));
		if (rollback_input_files_fds(e, node))
			return (ft_assign_i(&e->errno, 5, 5));
		if (*get_node_type(node) & CHAIN_END)
			break ;
		if (node->sibling_next)
			node = node->sibling_next->sibling_next;
	}
	fd_info(e);
	return (exec_chain(e));
}
