/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_28.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:21:46 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/05 17:01:08 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static t_treenode	*p1(t_treenode *cur, t_treenode *root)
{
	t_treenode	*tmp;

	if (ft_treenode_insert_child_idx_s_dup(root, "(", 0) == -1)
		return (0);
	cur = root->child;
	tmp = cur;
	if (ft_treenode_insert_child_idx_s_dup(cur, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->child, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "(", 2) == -1
	)
		return (0);
	cur = cur->child->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->child, "1", 0) == -1
	)
		return (0);
	if (ft_treenode_insert_child_idx_s_dup(tmp, "|", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(tmp, "wc", 4) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "|", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "wc", 2) == -1)
		return (0);
	return (tmp);
}

int	mock_28_tree(t_treenode *root)
{
	t_treenode	*cur;

	cur = 0;
	cur = p1(cur, root);
	if (!cur)
		return (1);
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
