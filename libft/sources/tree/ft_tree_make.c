/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_make.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 21:49:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

t_tree	*ft_tree_make()
{
	t_tree	*res;

	res = ft_calloc_if(sizeof(t_tree), 1);
	return (res);
}

t_treenode	*ft_treenode_make(void *c, t_treenode *p, int d, void (*freecontent)(void **))
{
	t_treenode *res;

	res = ft_calloc_if(sizeof(t_treenode), 1);
	if (!res)
		return (0);
	res->content = c;
	res->parent = p;
	res->depth = d;
	res->sibling_next = 0;
	res->sibling_prev = 0;
	res->child = 0;
	res->children_qtty = 0;
	res->freecontent = freecontent;
	return (res);
}
