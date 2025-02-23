/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/19 13:20:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	nonbrace(t_executor *e)
{
	t_tree	t;
	int		res;

	t.root = e->node;
	if (e->param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_INSPECTION)
		ft_tree_print(&t, cmd_txt, "\t");
	res = execute_text_tree_node(e);
	return (res);
}

static int	skip_logical_siblings(t_executor *e)
{
	if (!e->node || !e->node->sibling_next)
	{
		e->node = 0;
		return (0);
	}
	e->node = e->node->sibling_next;
	while (e->retval != 0 && e->node && e->node->content
		&& ft_strcmp(*get_node_txt(e->node), "&&") == 0 && e->node->sibling_next
		&& !takes_part_in_pipe_or_file(e->node->sibling_next))
		e->node = e->node->sibling_next->sibling_next;
	while (e->retval == 0 && e->node && e->node->content
		&& ft_strcmp(*get_node_txt(e->node), "||") == 0 && e->node->sibling_next
		&& !takes_part_in_pipe_or_file(e->node->sibling_next))
		e->node = e->node->sibling_next->sibling_next;
	if (e->node)
		e->node = e->node->sibling_next;
	return (0);
}

static int	exec_rec_1(t_executor *e)
{
	if (e->errno || e->param->opts.errno)
		return (0 * ERR("Execution error %i\n",
				*ft_max_int(&e->errno, &e->param->opts.errno)) + 3);
	if (skip_logical_siblings(e) != 0)
		return (1);
	if (e->param->opts.exiting || !e->node)
		return (e->retval);
	return (exec_rec(e));
}

int	exec_rec(t_executor *e)
{
	t_treenode	*parent;

	if (e->node && e->node->sibling_next
		&& is_pipe_or_redir(*get_node_txt(e->node->sibling_next)))
	{
		redirections(e);
		if (e->errno && ft_assign_i(&e->retval, 1, 1))
			return (ft_if_i(e->errno == NO_IN_FILE, 1, e->errno));
	}
	else if (ft_strcmp(*get_node_txt(e->node), TEXT_TREE_BLOCK) == 0)
	{
		parent = e->node;
		e->node = e->node->child;
		if (exec_rec(e) != 0)
			return (1);
		e->node = parent;
	}
	else
	{
		nonbrace(e);
		if (e->errno)
			return (2);
	}
	return (exec_rec_1(e));
}

int	exec_text_tree(t_param *param)
{
	t_executor	*executor;

	if (!param || !param->text_tree || !param->text_tree->root
		|| !param->text_tree->root->child)
	{
		ERR("%s\n", ERR_TEXT_TREE_EMPTY);
		return (1);
	}
	if (param->opts.debug_output_level & DBG_PRINT_TREE_BEFORE_EXEC)
		ft_tree_print(param->text_tree, cmd_txt, "\t");
	executor = make_executor(param->text_tree->root->child, param);
	if (!executor)
		return (2);
	if (markup(executor))
		return (3);
	exec_rec(executor);
	param->opts.retval = executor->retval;
	executor_finalize(executor);
	return (param->opts.retval);
}
