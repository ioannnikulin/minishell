/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_33.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:21:46 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/15 20:21:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static t_treenode	*p1(t_treenode *cur, t_treenode *root)
{
	t_treenode	*tmp;

	if (treenode_insert_dup(root, "(", 0) == -1)
		return (0);
	cur = root->child;
	tmp = cur;
	if (treenode_insert_dup(cur, "echo", 0) == -1
		|| treenode_insert_dup(cur->child, "1", 0) == -1
		|| treenode_insert_dup(cur, "&&", 1) == -1
		|| treenode_insert_dup(cur, "(", 2) == -1
	)
		return (0);
	cur = cur->child->sibling_next->sibling_next;
	if (treenode_insert_dup(cur, "echo", 0) == -1
		|| treenode_insert_dup(cur->child, "1", 0) == -1
	)
		return (0);
	if (treenode_insert_dup(tmp, "|", 3) == -1
		|| treenode_insert_dup(tmp, "wc", 4) == -1
		|| treenode_insert_dup(root, "|", 1) == -1
		|| treenode_insert_dup(root, "wc", 2) == -1)
		return (0);
	return (tmp);
}

int	mock_33_tree(t_treenode *root)
{
	t_treenode	*cur;

	cur = 0;
	cur = p1(cur, root);
	if (!cur)
		return (1);
	return (0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_33(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_33_TEXT) != 0 && ft_strcmp(input, "MOCK_33") != 0)
		return (0);
	if (mock_33_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
