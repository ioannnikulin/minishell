/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/07 12:09:18 by inikulin         ###   ########.fr       */
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
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 2) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "2", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 3) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 4) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "3", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 5) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 6) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "4", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "||", 7) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 8) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	return (cur);
}

static t_treenode	*p2(t_treenode *cur, t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(cur, "5", 0) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "&&", 9) == -1
		|| ft_treenode_insert_child_idx_s_dup(root, "echo", 10) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (ft_treenode_insert_child_idx_s_dup(cur, "6", 0) == -1)
		return (0);
	return (cur);
}

int	mock_4_tree(t_treenode *root)
{
	t_treenode	*cur;

	cur = 0;
	cur = p1(cur, root);
	if (!cur)
		return (1);
	cur = p2(cur, root);
	if (!cur)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_4(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_4_TEXT) != 0 && ft_strcmp(input, "MOCK_4") != 0)
		return (0);
	if (mock_4_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
