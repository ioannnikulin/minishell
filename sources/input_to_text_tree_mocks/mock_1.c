/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 21:08:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_1_tree(t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, "echo", 0);
	ft_treenode_insert_child_idx_s_dup(root->child, "hello\\n", 0);
	ft_treenode_insert_child_idx_s_dup(root->child, "myn", 1);
	ft_treenode_insert_child_idx_s_dup(root->child, "openworld", 2);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_1(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_1_TEXT) != 0)
		return (0);
	mock_1_tree(root);
	return (1);
}
