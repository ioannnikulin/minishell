/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 23:20:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_11_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "mkdir", 0);
	ft_treenode_insert_child_idx_s_dup(cur->child, "testf", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "cd", 2);
	cur = cur->child->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "testf", 0);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(cur->parent, "pwd", 4);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_11(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_11_TEXT) != 0 && ft_strcmp(input, "MOCK_11") != 0)
		return (0);
	mock_11_tree(root);
	return (1);
}
