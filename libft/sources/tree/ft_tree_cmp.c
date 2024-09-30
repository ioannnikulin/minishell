/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:39:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 13:52:19 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static int	impl(t_treenode *a, t_treenode *b, int (*cmp)(void *, void *))
{
	int	ret;

	if (!a && !b)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	ret = cmp(a->content, b->content);
	if (ret)
		return (ret);
	ret = impl(a->sibling_next, b->sibling_next, cmp);
	if (ret)
		return (ret);
	ret = impl(a->child, b->child, cmp);
	if (ret)
		return (ret);
	return (0);
}

int	ft_tree_cmp(t_tree *a, t_tree *b, int (*cmp)(void *, void *))
{
	return (impl(a->root, b->root, cmp));
}

int	ft_tree_cmp_s(t_tree *a, t_tree *b)
{
	return (ft_tree_cmp(a, b, ft_cmp_pvoid_s));
}
