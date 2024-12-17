/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_28.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/13 15:46:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_28_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child
			->sibling_next->sibling_next, "1", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "|", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "wc", 4) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "|", 5) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "wc", 6) == -1
	)
		return (1);
	return (0);
}

int	mock_28_tree_expanded(t_treenode *root)
{
	int		i;

	i = mock_28_tree(root);
	if (i)
		return (i);
	ft_treenode_insert_child_idx_s_nop(root, TEXT_TREE_BLOCK_REDIR, 2);
	root = root->child->sibling_next->sibling_next;
	root->child = ft_treenode_cut(root->parent, 3, 6);
	root = root->sibling_prev;
	ft_treenode_insert_child_idx_s_nop(root->parent, TEXT_TREE_BLOCK_REDIR, 2);
	root = root->sibling_next;
	root->child = ft_treenode_cut(root->parent, 3, 6);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_28(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_28_TEXT) != 0 && ft_strcmp(input, "MOCK_28") != 0)
		return (0);
	if (mock_28_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
