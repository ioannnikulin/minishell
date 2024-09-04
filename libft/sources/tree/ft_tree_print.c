/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:11:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/04 19:34:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static int	node(t_treenode *n, char *(*f)(void*), char *pad, int lvl)
{
	int	child;
	int	cur_pad;

	cur_pad = -1;
	while (++cur_pad < lvl)
		ft_printf("%s", pad);
	ft_printf("[%s]\n", f(n->content));
	child = -1;
	while (++ child < n->children_sz)
		node(n->children[child], f, pad, lvl + 1);
	return (0);
}

int	ft_tree_print(t_tree *tree, char *(*f)(void*), char *pad)
{
	if (!tree || !f)
		return (1);
	return (node(tree->root, f, pad, 0));
}

static char	*s(void *content)
{
	return ((char *)content);
}

int	ft_tree_print_s(t_tree *tree)
{
	return (ft_tree_print(tree, &s, "\t"));
}

static char	*c(void *content)
{
	return (&content);
}

int	ft_tree_print_c(t_tree *tree)
{
	return (ft_tree_print(tree, &c, "\t"));
}

