/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 00:28:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

/* returns 1 on success - to allow condition usage outside */
int	mock_2(char *input, t_treenode *root)
{
	if (ft_strcmp(input, "\echo \"1   2\"   3") != 0)
		return (0);
	ft_treenode_insert_child_idx_s_dup(root, "echo", 0);
	ft_treenode_insert_child_idx_s_dup(root->child, "1   2", 0);
	ft_treenode_insert_child_idx_s_dup(root->child, "3", 1);
	return (1);
}
