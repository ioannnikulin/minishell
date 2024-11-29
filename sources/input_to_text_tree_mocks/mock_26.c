/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_26.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/29 20:31:55 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_26_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "-n", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "2", 2) == -1
	)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_26(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_26_TEXT) != 0 && ft_strcmp(input, "MOCK_26") != 0)
		return (0);
	if (mock_26_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
