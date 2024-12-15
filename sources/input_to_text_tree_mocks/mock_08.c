/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_08.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 22:44:01 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_08_tree(t_treenode *cur)
{
	if (ft_treenode_insert_child_idx_s_dup(cur,
			"./tests/tool_print_environment", 0) == -1)
		return (1);
	cur = cur->child;
	if (ft_treenode_insert_child_idx_s_dup(cur, "one", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "\"two   three\"", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "four", 2) == -1)
		return (1);
	return (0);
}

int	mock_08_tree_expanded(t_treenode *root)
{
	return (mock_08_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_08(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_08_TEXT) != 0 && ft_strcmp(input, "MOCK_08") != 0)
		return (0);
	if (mock_08_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
