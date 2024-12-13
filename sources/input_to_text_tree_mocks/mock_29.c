/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_29.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/13 13:27:09 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_29_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "(", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "|", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "wc", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "|", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "wc", 4) == -1
	)
		return (1);
	root = root->child;
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(root->child
			->sibling_next->sibling_next, "1", 2) == -1
	)
		return (1);
	return (0);
}

int	mock_29_tree_expanded(t_treenode *root)
{
	int			i;
	t_treenode	*new;

	i = mock_29_tree(root);
	if (i)
		return (i);
	ft_treenode_insert_child_idx_s_nop(root, TEXT_TREE_BLOCK, 0);
	new = root->child;
	new->child = ft_treenode_cut(root, 1, 4);
	ft_treenode_insert_child_idx_s_nop(root, TEXT_TREE_BLOCK, 0);
	new = root->child;
	new->child = ft_treenode_cut(root, 1, 4);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_29(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_29_TEXT) != 0 && ft_strcmp(input, "MOCK_29") != 0)
		return (0);
	if (mock_29_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
