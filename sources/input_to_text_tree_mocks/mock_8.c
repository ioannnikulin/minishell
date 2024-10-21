/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/21 02:48:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_8_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur,
		"./tests/tool_print_environment", 0);
	cur = cur->child;
	ft_treenode_insert_child_idx_s_dup(cur, "one", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "two   three", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "four", 2);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_8(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_8_TEXT) != 0)
		return (0);
	mock_8_tree(root);
	return (1);
}
