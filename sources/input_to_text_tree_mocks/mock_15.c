/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/29 14:32:18 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_15_tree(t_treenode *cur)
{
	if (ft_treenode_insert_child_idx_s_dup(cur, "cd", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "pwd", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "&&", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "cd", 4) == -1)
		return (1);
	cur = cur->child->sibling_next->sibling_next->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "nope", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 5) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "pwd", 6) == -1)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_15(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_15_TEXT) != 0 && ft_strcmp(input, "MOCK_15") != 0)
		return (0);
	if (mock_15_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
