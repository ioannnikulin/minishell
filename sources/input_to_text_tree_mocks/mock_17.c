/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_17.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 12:52:36 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_17_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "echo", 0);
	ft_treenode_insert_child_idx_s_dup(cur->child, "1", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "exit", 2);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(cur, "echo", 4);
	cur = cur->child->sibling_next->sibling_next->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "2", 0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_17(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_17_TEXT) != 0 && ft_strcmp(input, "MOCK_17") != 0)
		return (0);
	mock_17_tree(root);
	return (1);
}
