/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_23.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/29 20:10:38 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_23_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "export", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "foo=bar", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "sea=shell", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 2) == -1
	)
		return (1);
	root = root->child->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(root, "$foo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "'$sea'", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "\"$sea\"", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "$no", 3) == -1
	)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_23(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_23_TEXT) != 0 && ft_strcmp(input, "MOCK_23") != 0)
		return (0);
	if (mock_23_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
