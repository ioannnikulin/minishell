/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/24 11:53:54 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_16_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "env", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "unset", 2);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(cur, "env", 4);
	cur = cur->child->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "HOME", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "PATH", 1);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "pwd", 5);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_16(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_16_TEXT) != 0 && ft_strcmp(input, "MOCK_16") != 0)
		return (0);
	mock_16_tree(root);
	return (1);
}
