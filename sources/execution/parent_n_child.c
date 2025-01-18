/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_n_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:53:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 17:02:18 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

/* there is a chance that notfrom != to (braces?)
* but for now yes, there are two identical arguments
*/
static t_duparg	make_duparg(int from, int notfrom, int to, int msg_src)
{
	t_duparg	arg;

	arg.from = from;
	arg.notfrom = notfrom;
	arg.to = to;
	arg.msg_src = msg_src;
	return (arg);
}

static int	dupit(t_executor *e, t_duparg a)
{
	if (a.to == a.notfrom)
		return (0);
	if (e->param->opts.debug_output_level & DBG_EXEC_CHAIN_PRINT_FD_OPS)
		FT_FPRINTF(STDERR, "%i: %s %i\n", a.msg_src, ft_if_s(
				a.notfrom == STDIN, "in", "out"), a.from);
	if (dup2(a.to, a.from) == -1)
	{
		FT_FPRINTF(STDERR, "%i: dup %s failed\n", a.msg_src, ft_if_s(
				a.notfrom == STDIN, "in", "out"));
		exit (ft_assign_i(&e->errno, 1, 1));
	}
	return (0);
}

int	child(t_executor *e, int tgt)
{
	dupit(e, make_duparg(STDIN, STDIN, *get_node_in_fd(e->node), tgt));
	dupit(e, make_duparg(STDOUT, STDOUT, *get_node_out_fd(e->node), tgt));
	if (close_fds(e, tgt))
		exit (ft_assign_i(&e->errno, 1, 3));
	if ((*get_node_type(e->node) & HEREDOC) && child_heredoc(e, e->node))
		exit (ft_assign_i(&e->errno, 1, 4));
	else
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
