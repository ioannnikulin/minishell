/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:11:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 20:24:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static int	node(t_treenode *n, char *(*f)(void*), char *pad, int lvl)
{
	t_treenode	*child;
	int			cur_pad;

	cur_pad = -1;
	while (++cur_pad < lvl)
		FT_PRINTF("%s", pad);
	FT_PRINTF("[%s]\n", f(n->content));
	child = n->child;
	while (child)
	{
		node(child, f, pad, lvl + 1);
		child = child->sibling_next;
	}
	return (0);
}

int	ft_tree_print(t_tree *tree, char *(*f)(void*), char *pad)
{
	if (!tree || !f)
		return (1);
	return (node(tree->root, f, pad, 0));
}
