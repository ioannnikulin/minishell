/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/23 00:19:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_15_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "cd", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "pwd", 2);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(cur, "cd", 4);
	cur = cur->child->sibling_next->sibling_next->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "nope", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(cur, "pwd", 4);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_15(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_15_TEXT) != 0 && ft_strcmp(input, "MOCK_15") != 0)
		return (0);
	mock_15_tree(root);
	return (1);
}
