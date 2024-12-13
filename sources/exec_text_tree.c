/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/13 12:43:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tree_make/tree_processing_internal.h"

/*
static t_control	make_control_set_redirs(t_treenode *node)
{
	t_control	res;

	res.retval = 0;
	res.found = 0;
	res.in_fd = -1;
	res.out_fd = -1;
	if (node->sibling_next && (!ft_strcmp(node->sibling_next->content, "|")
		|| is_redirection(node->sibling_next->content)))
	{
		
	}
	return (res);
}*/

static int	nonbrace(t_param *param, t_treenode *node, t_control *ctrl)
{
	t_tree	t;
	int		res;

	t.root = node;
	if (param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_INSPECTION)
		ft_tree_print_s(&t);
	res = execute_text_tree_node(param, node, ctrl);
	return (res);
}

static int	same_cmd(char *op, char *skipop)
{
	if ((skipop && !ft_strcmp(op, skipop))
		|| ft_strcmp(op, "|") == 0 || is_redirection(op))
		return (1);
	return (0);
}

static int	exec_rec(t_param *param, t_treenode *node, t_control *ctrl)
{
	int			res;

	if (!node || !param || param->opts.errno || !node->content)
		return (0);
	if (ft_strcmp(node->content, "(") == 0)
		res = exec_rec(param, node->child, ctrl);
	else
		res = nonbrace(param, node, ctrl);
	if (param->opts.errno)
	{
		printf("ERROR %i\n", param->opts.errno);
		return (0);
	}
	node = node->sibling_next;
	while (res && node && same_cmd(node->content, "&&") && node->sibling_next)
		node = node->sibling_next->sibling_next;
	while (!res && node && same_cmd(node->content, "||") && node->sibling_next)
		node = node->sibling_next->sibling_next;
	if (param->opts.exiting || !node || !node->sibling_next)
		return (ft_if_i(param->opts.exiting, 0, res));
	return (exec_rec(param, node->sibling_next, ctrl));
}

int	exec_text_tree(t_param *param)
{
	int			res;

	if (!param || !param->text_tree || !param->text_tree->root
		|| !param->text_tree->root->child)
	{
		printf("%s\n", ERR_TEXT_TREE_EMPTY);
		return (1);
	}
	if (param->opts.debug_output_level & DBG_PRINT_TREE_BEFORE_EXEC)
		ft_tree_print_s(param->text_tree);
	res = exec_rec(param, param->text_tree->root->child, 0);
	return (res);
}
