/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 18:56:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution_internal.h"

static int	nonbrace(t_executor *e)
{
	t_tree	t;
	int		res;

	t.root = e->node;
	if (e->param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_INSPECTION)
		ft_tree_print_s(&t);
	res = execute_text_tree_node(e);
	e->node = e->node->sibling_next;
	return (res);
}

static int	skip_logical_siblings(t_executor *e)
{
	if (!e->node || !e->node->sibling_next)
		return (0);
	e->node = e->node->sibling_next;
	while (e->retval != 0 && e->node && e->node->content
		&& ft_strcmp(e->node->content, "&&") == 0 && e->node->sibling_next)
		e->node = e->node->sibling_next->sibling_next;
	while (e->retval == 0 && e->node && e->node->content
		&& ft_strcmp(e->node->content, "||") == 0 && e->node->sibling_next)
		e->node = e->node->sibling_next->sibling_next;
	if (!e->node->sibling_next)
		e->node = 0;
	return (0);
}

int	exec_rec(t_executor *e)
{
	if (!e)
		return (0);
	if (e->node && e->node->sibling_next && is_pipe_or_redir(e->node->sibling_next->content))
		return (redirections(e));
	if (ft_strcmp(e->node->content, TEXT_TREE_BLOCK) == 0)
	{
		e->node = e->node->child;
		if (exec_rec(e) != 0)
			return (1);
	}
	else if (nonbrace(e) != 0)
		return (2);
	if (e->param->opts.errno)
		return (0 * printf("ERROR %i\n", e->param->opts.errno) + 3);
	if (skip_logical_siblings(e) != 0)
		return (1);
	if (e->param->opts.exiting || !e->node)
		return (ft_if_i(e->param->opts.exiting, 0, 0));
	return (exec_rec(e));
}

int	exec_text_tree(t_param *param)
{
	int			res;
	t_executor	*executor;

	if (!param || !param->text_tree || !param->text_tree->root
		|| !param->text_tree->root->child)
	{
		printf("%s\n", ERR_TEXT_TREE_EMPTY);
		return (1);
	}
	if (param->opts.debug_output_level & DBG_PRINT_TREE_BEFORE_EXEC)
		ft_tree_print_s(param->text_tree);
	executor = make_executor(param->text_tree->root->child, param);
	if (!executor)
		return (2);
	res = exec_rec(executor);
	free(executor);
	return (res);
}