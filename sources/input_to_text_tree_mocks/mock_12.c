/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/29 14:23:04 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_12_tree(t_treenode *cur)
{
	if (ft_treenode_insert_child_idx_s_dup(cur, "pwd", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "mkdir", 2) == -1)
		return (1);
	cur = cur->child->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "testf", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "cd", 4) == -1)
		return (1);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "./testf/..", 0);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 5);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "pwd", 6);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_12(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_12_TEXT) != 0 && ft_strcmp(input, "MOCK_12") != 0)
		return (0);
	if (mock_12_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
