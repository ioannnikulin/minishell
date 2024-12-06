/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_27.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 11:48:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_27_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "cd", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "a", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "b", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child
			->sibling_next->sibling_next, "1", 2) == -1
	)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_27(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_27_TEXT) != 0 && ft_strcmp(input, "MOCK_27") != 0)
		return (0);
	if (mock_27_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
