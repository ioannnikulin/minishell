/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_31.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/10 18:43:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_31_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, ">", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "out.a", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 4) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, ">", 5) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "out.a", 6) == -1
	)
		return (1);
	root = root->child->sibling_next->sibling_next->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(root, "1", 0) == -1)
		return (1);
	return (0);
}

int	mock_31_tree_expanded(t_treenode *root)
{
	return (mock_31_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_31(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_31_TEXT) != 0 && ft_strcmp(input, "MOCK_31") != 0)
		return (0);
	if (mock_31_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
