/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 14:14:57 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static t_treenode	*p1(t_treenode *cur, t_treenode *root)
{
	if (treenode_insert_dup(root, "mkdir", 0) == -1)
		return (0);
	cur = root->child;
	if (treenode_insert_dup(cur, "testf", 0) == -1
		|| treenode_insert_dup(root, "&&", 1) == -1
		|| treenode_insert_dup(root, "cd", 2) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (treenode_insert_dup(cur, "testf", 0) == -1
		|| treenode_insert_dup(root, "&&", 3) == -1
		|| treenode_insert_dup(root, "mkdir", 4) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (treenode_insert_dup(cur, "f1", 0) == -1
		|| treenode_insert_dup(cur, "f2", 1) == -1
		|| treenode_insert_dup(root, "&&", 5) == -1
		|| treenode_insert_dup(root, "touch", 6) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (treenode_insert_dup(cur, "1", 0) == -1
		|| treenode_insert_dup(root, "&&", 7) == -1
		|| treenode_insert_dup(root, "touch", 8) == -1)
		return (0);
	return (cur->sibling_next->sibling_next);
}

static t_treenode	*p2(t_treenode *cur, t_treenode *root)
{
	if (treenode_insert_dup(cur, "11", 0) == -1
		|| treenode_insert_dup(cur, "2", 1) == -1
		|| treenode_insert_dup(root, "&&", 9) == -1
		|| treenode_insert_dup(root, "ls", 10) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (treenode_insert_dup(cur, "-a", 0) == -1
		|| treenode_insert_dup(cur, "-fh", 1) == -1
		|| treenode_insert_dup(cur, "-c", 2) == -1
		|| treenode_insert_dup(root, "|", 11) == -1
		|| treenode_insert_dup(root, "grep", 12) == -1)
		return (0);
	cur = cur->sibling_next->sibling_next;
	if (treenode_insert_dup(cur, "1", 0) == -1
		|| treenode_insert_dup(root, ">>", 13) == -1
		|| treenode_insert_dup(root, "out.txt", 14) == -1)
		return (0);
	return (cur);
}

int	mock_03_tree(t_treenode *root)
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

int	mock_03_tree_expanded(t_treenode *root)
{
	int	i;

	i = mock_03_tree(root);
	if (i)
		return (i);
	root = root->child;
	while (ft_strcmp(*get_node_txt(root->sibling_next), "ls") != 0)
	{
		root = root->sibling_next;
		i ++;
	}
	if (treenode_insert_nop(root->parent,
			TEXT_TREE_BLOCK_REDIR, 10) == -1)
		return (2);
	root = root->sibling_next;
	root->child = ft_treenode_cut(root->parent, 11, 14);
	if (treenode_insert_nop(root->parent,
			TEXT_TREE_BLOCK_REDIR, 10) == -1)
		return (2);
	root = root->sibling_prev;
	root->child = ft_treenode_cut(root->parent, 11, 14);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_03(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_03_TEXT) != 0 && ft_strcmp(input, "MOCK_03") != 0)
		return (0);
	if (mock_03_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
