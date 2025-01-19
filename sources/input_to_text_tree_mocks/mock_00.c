/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/15 20:21:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_00_tree(t_treenode *root)
{
	if (treenode_insert_dup(root, "echo", 0) == -1
		|| treenode_insert_dup(root->child, "hello", 0) == -1
		|| treenode_insert_dup(root->child, "world", 1) == -1)
		return (1);
	return (0);
}

int	mock_00_tree_expanded(t_treenode *root)
{
	return (mock_00_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_00(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_00_TEXT) != 0 && ft_strcmp(input, "MOCK_00") != 0)
		return (0);
	if (mock_00_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
