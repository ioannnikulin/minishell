/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_text_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:39:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/12 02:07:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_rec(t_param *param, t_treenode *node)
{
	int		res;
	t_tree	t;

	if (!node)
		return (0);
	if (!ft_strcmp(node->content, "("))
		return (exec_rec(param, node->child));
	t.root = node;
	if (!(param->debug_output_level & DBG_PRINT_NODE_BEFORE_EXEC))
		ft_tree_print_s(&t);
	res = execute_text_tree_node(param, node);
	node = node->sibling_next;
	while (!res && node && !ft_strcmp(node->content, "&&") && node->sibling_next)
		node = node->sibling_next->sibling_next;
	while (res && node && !ft_strcmp(node->content, "||") && node->sibling_next)
		node = node->sibling_next->sibling_next;
	if (!node || !node->sibling_next)
		return (res);
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
	if (!(param->debug_output_level & DBG_PRINT_TREE_BEFORE_EXEC))
		ft_tree_print_s(param->text_tree);
	res = exec_rec(param, param->text_tree->root->child);
	return (res);
}
