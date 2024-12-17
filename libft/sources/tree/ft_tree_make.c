/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_make.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 21:48:55 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree	*ft_tree_make(void)
{
	t_tree	*res;

	res = ft_calloc_if(sizeof(t_tree), 1);
	return (res);
}

t_treenode	*ft_treenode_make(void *c, t_treenode *p,
				void (*freecontent)(void **))
{
	t_treenode	*res;

	if (!c)
		return (0);
	res = ft_calloc_if(sizeof(t_treenode), 1);
	if (!res)
		return (0);
	res->content = c;
	res->parent = p;
	res->depth = 0;
	if (p)
		res->depth = p->depth + 1;
	res->sibling_next = 0;
	res->sibling_prev = 0;
	res->child = 0;
	res->children_qtty = 0;
	res->freecontent = freecontent;
	return (res);
}
