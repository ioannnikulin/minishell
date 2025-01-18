/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/15 20:21:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_15_tree(t_treenode *cur)
{
	if (treenode_insert_dup(cur, "cd", 0) == -1
		|| treenode_insert_dup(cur, "&&", 1) == -1
		|| treenode_insert_dup(cur, "pwd", 2) == -1
		|| treenode_insert_dup(cur, "&&", 3) == -1
		|| treenode_insert_dup(cur, "cd", 4) == -1)
		return (1);
	cur = cur->child->sibling_next->sibling_next->sibling_next->sibling_next;
	if (treenode_insert_dup(cur, "nope", 0) == -1
		|| treenode_insert_dup(cur->parent, "&&", 5) == -1
		|| treenode_insert_dup(cur->parent, "pwd", 6) == -1)
		return (1);
	return (0);
}

int	mock_15_tree_expanded(t_treenode *root)
{
	return (mock_15_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_15(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_15_TEXT) != 0 && ft_strcmp(input, "MOCK_15") != 0)
		return (0);
	if (mock_15_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
