/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 20:04:08 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is(char *a, char *b)
{
	return (ft_strcmp(a, b));
}

static	int	nonbrace(t_param *param, t_treenode *node)
{
	t_tree	t;
	int		res;

	t.root = node;
	if (param->opts.debug_output_level & DBG_PRINT_NODE_BEFORE_INSPECTION)
		ft_tree_print_s(&t);
	res = execute_text_tree_node(param, node);
	return (res);
}

static int	exec_rec(t_param *param, t_treenode *node)
{
	int		res;

	if (!node || !param || param->opts.errno || !node->content)
		return (0);
	if (ft_strcmp(node->content, "(") == 0)
		res = exec_rec(param, node->child);
	else
		res = nonbrace(param, node);
	if (param->opts.errno)
	{
		printf("ERROR %i\n", param->opts.errno);
		return (0);
	}
	node = node->sibling_next;
	while (res && node && !is(node->content, "&&") && node->sibling_next)
		node = node->sibling_next->sibling_next;
	while (!res && node && !is(node->content, "||") && node->sibling_next)
		node = node->sibling_next->sibling_next;
	if (param->opts.exiting || !node || !node->sibling_next)
		return (ft_if_i(param->opts.exiting, 0, res));
	return (exec_rec(param, node->sibling_next));
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
	res = exec_rec(param, param->text_tree->root->child);
	return (res);
}
