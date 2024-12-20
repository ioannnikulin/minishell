/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_20.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/27 22:46:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static t_treenode	*p1(t_treenode *cur, t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "echo", 0) == -1)
		return (0);
	cur = root->child;
	if (ft_treenode_insert_child_idx_s_dup(cur, "1", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "||", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 2) == -1
	)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "2", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "(", 4) == -1
	)
		return (0);
	return (cur->sibling_next->sibling_next);
}

static t_treenode	*p2(t_treenode *cur)
{
	if (ft_treenode_insert_child_idx_s_dup(cur, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->child, "3", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "&&", 1) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "(", 2) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "||", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "echo", 4) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "&&", 5) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur, "echo", 6) == -1
	)
		return (0);
	cur = cur->child->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "echo", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(cur->child, "4", 0) == -1
	)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "5", 0) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "6", 0) == -1)
		return (0);
	return (cur);
}

int	mock_20_tree(t_treenode *root)
{
	t_treenode	*cur;

	cur = 0;
	cur = p1(cur, root);
	if (!cur)
		return (1);
	cur = p2(cur);
	if (!cur)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_20(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_20_TEXT) != 0 && ft_strcmp(input, "MOCK_20") != 0)
		return (0);
	if (mock_20_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
