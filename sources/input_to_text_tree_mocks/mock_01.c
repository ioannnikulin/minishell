/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/10 16:33:23 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_01_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "hello\\n", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "my", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(
			root->child, "openworld", 2) == -1)
		return (1);
	return (0);
}

int	mock_01_tree_expanded(t_treenode *root)
{
	return (mock_01_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_01(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_01_TEXT) != 0 && ft_strcmp(input, "MOCK_01") != 0)
		return (0);
	if (mock_01_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
