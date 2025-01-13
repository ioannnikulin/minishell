/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_n_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:53:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 21:54:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

int	child(t_executor *e, int tgt)
{
	if (e->fds[tgt][IN] != STDIN)
	{
		if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
			FT_FPRINTF(STDERR, "%i: dup in %i\n", tgt, e->fds[tgt][IN]);
		if (dup2(e->fds[tgt][IN], STDIN) == -1)
		{
			FT_FPRINTF(STDERR, "%i: dup failed\n", tgt);
			exit (ft_assign_i(&e->errno, 1, 1));
		}
	}
	if (e->fds[tgt][OUT] != STDOUT)
	{
		if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
			FT_FPRINTF(STDERR, "%i: dup out %i\n", tgt, e->fds[tgt][OUT]);
		if (dup2(e->fds[tgt][OUT], STDOUT) == -1)
		{
			FT_FPRINTF(STDERR, "%i: dup failed\n", tgt);
			exit (ft_assign_i(&e->errno, 1, 2));
		}
	}
	if (close_fds(e, tgt) || scroll_chain(e, tgt))
		return (ft_assign_i(&e->errno, 1, 3));
	execute_text_tree_node(e);
	exit(0);
}

int	chain_parent(t_executor *e)
{
	int	i;

	if (close_fds(e, -1) || e->errno)
		return (ft_assign_i(&e->errno, 1, 1));
	i = -1;
	while (++i < e->chain_length)
	{
		if (!is_out_file(e->node) && !is_in_file(e->node))
		{
			e->retval = parent(e->pids[i], &e->errno);
			if (e->errno != 0)
				return (1);
		}
		if (i != e->chain_length - 1)
			e->node = e->node->sibling_next->sibling_next;
	}
	e->param->opts.retval = e->retval;
	return (e->retval);
}