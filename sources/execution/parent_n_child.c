/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_n_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:53:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 23:47:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	child(t_executor *e, int tgt)
{

	if (*get_node_in_fd(e->node) != STDIN)
	{
		if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
			FT_FPRINTF(STDERR, "%i: in %i\n", tgt, *get_node_in_fd(e->node));
		if (dup2(*get_node_in_fd(e->node), STDIN) == -1)
		{
			FT_FPRINTF(STDERR, "%i: dup failed\n", tgt);
			exit (ft_assign_i(&e->errno, 1, 1));
		}
	}
	if (*get_node_out_fd(e->node) != STDOUT)
	{
		if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
			FT_FPRINTF(STDERR, "%i: out %i\n", tgt, *get_node_out_fd(e->node));
		if (dup2(*get_node_out_fd(e->node), STDOUT) == -1)
		{
			FT_FPRINTF(STDERR, "%i: dup failed\n", tgt);
			exit (ft_assign_i(&e->errno, 1, 2));
		}
	}
	if (close_fds(e, tgt))
		return (ft_assign_i(&e->errno, 1, 3));
	execute_text_tree_node(e);
	exit(0);
}


int	chain_parent(t_executor *e)
{
	while ((*get_node_type(e->node) & CHAIN_START) == 0)
		e->node = prev_node(e->node);
	if (close_fds(e, -1) || e->errno)
		return (ft_assign_i(&e->errno, 1, 1));
	while (1)
	{
		if (!is_out_file(e->node) && !is_in_file(e->node))
		{
			e->retval = parent(*get_node_pid(e->node), &e->errno);
			if (e->errno != 0)
				return (1);
		}
		if (*get_node_type(e->node) & CHAIN_END)
			break ;
		e->node = next_node(e->node);
	}
	e->param->opts.retval = e->retval;
	return (e->retval);
}
