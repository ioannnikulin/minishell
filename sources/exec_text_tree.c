/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 11:48:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tree_make/tree_processing_internal.h"
#include "execution_internal.h"

static int	nonbrace(t_executor *e)
{
	t_tree	t;
	int		res;

	t.root = e->node;
	if (e->param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_INSPECTION)
		ft_tree_print_s(&t);
	res = execute_text_tree_node(e);
	return (res);
}

static int	same_cmd(char *op, char *skipop)
{
	if ((skipop && !ft_strcmp(op, skipop))
		|| ft_strcmp(op, "|") == 0 || is_redirection(op))
		return (1);
	return (0);
}

static int	exec_rec(t_e *e)
{
	int	res;

	if (!e)
		return (0);
	if (set_redirs(e))
		return (1);
	if (ft_strcmp(e->node->content, "(") == 0)
		res = exec_rec(e);
	else
		res = nonbrace(e);
	if (e->param->opts.errno)
	{
		printf("ERROR %i\n", e->param->opts.errno);
		return (0);
	}
	e->node = e->node->sibling_next;
	while (res && e->node && same_cmd(e->node->content, "&&") && e->node->sibling_next)
		e->node = e->node->sibling_next->sibling_next;
	while (!res && e->node && same_cmd(e->node->content, "||") && e->node->sibling_next)
		e->node = e->node->sibling_next->sibling_next;
	if (e->param->opts.exiting || !e->node || !e->node->sibling_next)
		return (ft_if_i(e->param->opts.exiting, 0, res));
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
	return (res);
}
