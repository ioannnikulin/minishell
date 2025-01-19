/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_26.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/15 20:21:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static int	p2(t_treenode *root)
{
	if (treenode_insert_dup(root, "3", 0) == -1)
		return (1);
	root = root->sibling_next->sibling_next;
	if (treenode_insert_dup(root, "4", 0) == -1)
		return (1);
	root = root->sibling_next->sibling_next;
	if (treenode_insert_dup(root, "5", 0) == -1
		|| treenode_insert_dup(root->sibling_next->sibling_next,
			"6", 0) == -1)
		return (1);
	return (0);
}

int	mock_26_tree(t_treenode *root)
{
	if (treenode_insert_dup(root, "echo", 0) == -1
		|| treenode_insert_dup(root->child, "1", 0) == -1
		|| treenode_insert_dup(root->child, "-n", 1) == -1
		|| treenode_insert_dup(root->child, "2", 2) == -1
		|| treenode_insert_dup(root, "&&", 1) == -1
		|| treenode_insert_dup(root, "echo", 2) == -1
		|| treenode_insert_dup(root, "||", 3) == -1
		|| treenode_insert_dup(root, "echo", 4) == -1
		|| treenode_insert_dup(root, "||", 5) == -1
		|| treenode_insert_dup(root, "echo", 6) == -1
		|| treenode_insert_dup(root, "||", 7) == -1
		|| treenode_insert_dup(root, "echo", 8) == -1
	)
		return (1);
	return (p2(root->child->sibling_next->sibling_next));
}

int	mock_26_tree_expanded(t_treenode *root)
{
	return (mock_26_tree(root));
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
