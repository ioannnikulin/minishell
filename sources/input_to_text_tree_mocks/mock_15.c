/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 23:45:35 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_15_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "cd", 0);
	ft_treenode_insert_child_idx_s_dup(cur->child, "nope", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "pwd", 2);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_15(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_15_TEXT) != 0 && ft_strcmp(input, "MOCK_15") != 0)
		return (0);
	mock_15_tree(root);
	return (1);
}
