/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_30.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/13 15:46:49 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static t_treenode	*p1(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "(", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "|", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "wc", 4) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 5) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 6) == -1
	)
		return (0);
	root = root->child->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "(", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "|", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "wc", 4) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "|", 5) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "wc", 6) == -1
	)
		return (0);
	return (root->child->sibling_next->sibling_next);
}

int	mock_30_tree(t_treenode *root)
{
	root = p1(root);
	if (!root)
		return (1);
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(
			root->child->sibling_next->sibling_next, "1", 0) == -1
	)
		return (1);
	return (0);
}

int	mock_30_tree_expanded(t_treenode *root)
{
	int			i;
	t_treenode	*cur;

	i = mock_30_tree(root);
	if (i)
		return (i);
	cur = root;
	ft_treenode_insert_child_idx_s_nop(cur, TEXT_TREE_BLOCK_REDIR, 2);
	cur = cur->child->sibling_next->sibling_next;
	cur->child = ft_treenode_cut(cur->parent, 3, 6);
	cur = cur->child->child->sibling_next;
	ft_treenode_insert_child_idx_s_nop(cur->parent, TEXT_TREE_BLOCK_REDIR, 2);
	cur = cur->sibling_next;
	cur->child = ft_treenode_cut(cur->parent, 3, 8);
	ft_treenode_insert_child_idx_s_nop(cur, TEXT_TREE_BLOCK_REDIR, 0);
	cur = cur->child;
	cur->child = ft_treenode_cut(cur->parent, 1, 4);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_30(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_30_TEXT) != 0 && ft_strcmp(input, "MOCK_30") != 0)
		return (0);
	if (mock_30_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
