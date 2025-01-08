/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_25.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/10 17:43:00 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_25_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "-nn", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "1", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "2", 2) == -1
	)
		return (1);
	return (0);
}

int	mock_25_tree_expanded(t_treenode *root)
{
	return (mock_25_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_25(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_25_TEXT) != 0 && ft_strcmp(input, "MOCK_25") != 0)
		return (0);
	if (mock_25_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
