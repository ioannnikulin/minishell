/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_23.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/15 20:21:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static t_treenode	*p1(t_treenode *root)
{
	if (treenode_insert_dup(root, "export", 0) == -1
		|| treenode_insert_dup(root, "&&", 1) == -1
		|| treenode_insert_dup(root, "$say", 2) == -1
	)
		return (0);
	root = root->child;
	if (treenode_insert_dup(root, "foo=bar", 0) == -1
		|| treenode_insert_dup(root, "sea=$foo", 1) == -1
		|| treenode_insert_dup(root, "say=echo", 2) == -1
		|| treenode_insert_dup(root, "_1=$_1", 3) == -1
		|| treenode_insert_dup(root, "_=", 4) == -1
	)
		return (0);
	return (root->sibling_next->sibling_next);
}

int	mock_23_tree(t_treenode *root)
{
	root = p1(root);
	if (!root)
		return (1);
	if (treenode_insert_dup(root, "[$foo]", 0) == -1
		|| treenode_insert_dup(root, "['$sea']", 1) == -1
		|| treenode_insert_dup(root, "[\"$sea\"]", 2) == -1
		|| treenode_insert_dup(root, "[$food]", 3) == -1
		|| treenode_insert_dup(root, "[$_1]", 4) == -1
		|| treenode_insert_dup(root, "[$_]", 5) == -1
		|| treenode_insert_dup(root, "[$]", 6) == -1
		|| treenode_insert_dup(root, "[$PATH]", 7) == -1
		|| treenode_insert_dup(root, "[$some]", 8) == -1
	)
		return (1);
	return (0);
}

int	mock_23_tree_expanded(t_treenode *root)
{
	return (mock_23_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_23(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_23_TEXT) != 0 && ft_strcmp(input, "MOCK_23") != 0)
		return (0);
	if (mock_23_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
