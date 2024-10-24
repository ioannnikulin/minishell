/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 23:22:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static t_treenode	*p1(t_treenode *cur, t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, "echo", 0);
	cur = root->child;
	ft_treenode_insert_child_idx_s_dup(cur, "1", 0);
	ft_treenode_insert_child_idx_s_dup(root, "||", 1);
	ft_treenode_insert_child_idx_s_dup(root, "echo", 2);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "2", 0);
	ft_treenode_insert_child_idx_s_dup(root, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(root, "(", 4);
	cur = cur->sibling_next->sibling_next;
	return (cur);
}

static t_treenode	*p2(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "echo", 0);
	ft_treenode_insert_child_idx_s_dup(cur->child, "3", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "echo", 2);
	ft_treenode_insert_child_idx_s_dup(cur, "||", 3);
	ft_treenode_insert_child_idx_s_dup(cur, "echo", 4);
	ft_treenode_insert_child_idx_s_dup(cur, "&&", 5);
	ft_treenode_insert_child_idx_s_dup(cur, "echo", 6);
	cur = cur->child->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "4", 0);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "5", 0);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "6", 0);
	return (cur);
}

void	mock_5_tree(t_treenode *root)
{
	t_treenode	*cur;

	cur = 0;
	cur = p1(cur, root);
	cur = p2(cur);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_5(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_5_TEXT) != 0 && ft_strcmp(input, "MOCK_5") != 0)
		return (0);
	mock_5_tree(root);
	return (1);
}
