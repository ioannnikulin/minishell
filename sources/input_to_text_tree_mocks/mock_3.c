/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 14:12:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static t_treenode	*p1(t_treenode *cur, t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, "mkdir", 0);
	cur = root->child;
	ft_treenode_insert_child_idx_s_dup(cur, "testf", 0);
	ft_treenode_insert_child_idx_s_dup(root, "&&", 1);
	ft_treenode_insert_child_idx_s_dup(root, "cd", 2);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "-L", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "testf", 1);
	ft_treenode_insert_child_idx_s_dup(root, "&&", 3);
	ft_treenode_insert_child_idx_s_dup(root, "mkdir", 4);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "f1", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "f2", 1);
	ft_treenode_insert_child_idx_s_dup(root, "&&", 5);
	ft_treenode_insert_child_idx_s_dup(root, "touch", 6);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "1", 0);
	ft_treenode_insert_child_idx_s_dup(root, "&&", 7);
	ft_treenode_insert_child_idx_s_dup(root, "touch", 8);
	cur = cur->sibling_next->sibling_next;
	return (cur);
}

static t_treenode	*p2(t_treenode *cur, t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(cur, "11", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "2", 1);
	ft_treenode_insert_child_idx_s_dup(root, "&&", 9);
	ft_treenode_insert_child_idx_s_dup(root, "ls", 10);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "-a", 0);
	ft_treenode_insert_child_idx_s_dup(cur, "-fh", 1);
	ft_treenode_insert_child_idx_s_dup(cur, "-c", 2);
	ft_treenode_insert_child_idx_s_dup(root, "|", 11);
	ft_treenode_insert_child_idx_s_dup(root, "grep", 12);
	cur = cur->sibling_next->sibling_next;
	ft_treenode_insert_child_idx_s_dup(cur, "1", 0);
	ft_treenode_insert_child_idx_s_dup(root, ">>", 13);
	ft_treenode_insert_child_idx_s_dup(root, "out.txt", 14);
	return (cur);
}

void	mock_3_tree(t_treenode *root)
{
	t_treenode	*cur;

	cur = 0;
	cur = p1(cur, root);
	cur = p2(cur, root);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_3(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_3_TEXT) != 0)
		return (0);
	mock_3_tree(root);
	return (1);
}
