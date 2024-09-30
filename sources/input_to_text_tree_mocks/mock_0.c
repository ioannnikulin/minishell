/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 14:19:19 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_0_tree(t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, "echo", 0);
	ft_treenode_insert_child_idx_s_dup(root->child, "hello", 0);
	ft_treenode_insert_child_idx_s_dup(root->child, "world", 1);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_0(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_0_TEXT) != 0)
		return (0);
	mock_0_tree(root);
	return (1);
}
