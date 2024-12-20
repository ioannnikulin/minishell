/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/07 12:10:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_11_tree(t_treenode *cur)
{
	if (ft_treenode_insert_child_idx_s_dup(cur, "mkdir", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->child, "testf", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "cd", 2) == -1)
		return (1);
	cur = cur->child->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "testf", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->parent, "pwd", 4) == -1)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_11(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_11_TEXT) != 0 && ft_strcmp(input, "MOCK_11") != 0)
		return (0);
	if (mock_11_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
