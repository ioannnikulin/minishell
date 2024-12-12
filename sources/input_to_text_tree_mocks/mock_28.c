/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_28.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/10 18:46:46 by inikulin         ###   ########.fr       */
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
	int			i;
	t_treenode	*new;

	i = mock_28_tree(root);
	if (i)
		return (i);
	root = root->child->sibling_next;
	ft_treenode_insert_child_idx_s_nop(root, TEXT_TREE_BLOCK, 2);
	new = root->sibling_next;
	root = new->sibling_next;
	i = -1;
	while (++i < 3)
	{
		ft_treenode_insert_child_idx(new, root, i);
		root = root->sibling_next;
	}
	new->sibling_next = root->sibling_next;
	root->sibling_next = 0;
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
