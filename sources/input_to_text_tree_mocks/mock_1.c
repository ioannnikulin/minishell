/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/07 12:11:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_1_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "hello\\n", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "my", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(
			root->child, "openworld", 2) == -1)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_1(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_1_TEXT) != 0 && ft_strcmp(input, "MOCK_1") != 0)
		return (0);
	if (mock_1_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
