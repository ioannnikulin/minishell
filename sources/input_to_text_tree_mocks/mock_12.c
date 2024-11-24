/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/24 11:25:07 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_12_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "pwd", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "mkdir", 2);
	cur = cur->child->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "testf", 0);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "cd", 4);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "./testf/..", 0);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 5);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "pwd", 6);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_12(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_12_TEXT) != 0 && ft_strcmp(input, "MOCK_12") != 0)
		return (0);
	mock_12_tree(root);
	return (1);
}
