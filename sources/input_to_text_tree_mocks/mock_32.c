/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/15 20:21:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_32_tree(t_treenode *root)
{
	if (treenode_insert_dup(root, "echo", 0) == -1
		|| treenode_insert_dup(root->child, "1", 0) == -1
		|| treenode_insert_dup(root, ">>", 1) == -1
		|| treenode_insert_dup(root, "out.a", 2) == -1
		|| treenode_insert_dup(root, "&&", 3) == -1
		|| treenode_insert_dup(root, "echo", 4) == -1
		|| treenode_insert_dup(root, ">>", 5) == -1
		|| treenode_insert_dup(root, "out.a", 6) == -1
	)
		return (1);
	root = root->child->sibling_next->sibling_next->sibling_next->sibling_next;
	if (treenode_insert_dup(root, "2", 0) == -1)
		return (1);
	return (0);
}

int	mock_32_tree_expanded(t_treenode *root)
{
	int	i;

	i = mock_32_tree(root);
	if (i)
		return (i);
	treenode_insert_nop(root, TEXT_TREE_BLOCK_REDIR, 0);
	root = root->child;
	root->child = ft_treenode_cut(root->parent, 1, 4);
	treenode_insert_nop(root->parent, TEXT_TREE_BLOCK_REDIR, 2);
	root = root->sibling_next->sibling_next;
	root->child = ft_treenode_cut(root->parent, 3, 6);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_32(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_32_TEXT) != 0 && ft_strcmp(input, "MOCK_32") != 0)
		return (0);
	if (mock_32_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
