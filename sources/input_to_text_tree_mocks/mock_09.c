/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/10 17:19:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_09_tree(t_treenode *cur)
{
	if (ft_treenode_insert_child_idx_s_dup(cur, "export", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->child, "foo=bar", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "export", 2) == -1)
		return (1);
	cur = cur->child->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "foo=zah", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "nope=uhoh", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "unset", 4) == -1)
		return (1);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "nope", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 5) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent,
			"./tests/tool_print_environment", 6) == -1)
		return (1);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "one", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "two   three", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "four", 2) == -1)
		return (1);
	return (0);
}

int	mock_09_tree_expanded(t_treenode *root)
{
	return (mock_09_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_09(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_09_TEXT) != 0 && ft_strcmp(input, "MOCK_09") != 0)
		return (0);
	if (mock_09_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
