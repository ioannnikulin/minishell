/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_cut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:23:32 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/12 23:12:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

static t_treenode	*top(t_treenode *parent, int toExcl)
{
	t_treenode	*next;
	t_treenode	*ret;
	int			i;

	ret = parent->child;
	next = ret;
	i = -1;
	while (++i < toExcl)
		next = next->sibling_next;
	if (i != toExcl)
		return (0);
	parent->child = next;
	return (ret);
}

t_treenode	*ft_treenode_cut(t_treenode *parent, int fromIncl, int toExcl)
{
	int			i;
	t_treenode	*prev;
	t_treenode	*next;
	t_treenode	*ret;

	if (!parent || toExcl <= fromIncl)
		return (0);
	if (fromIncl == 0)
		return (top(parent, toExcl));
	i = 0;
	prev = parent->child;
	while (++ i < fromIncl && prev->sibling_next)
		prev = prev->sibling_next;
	if (i != fromIncl)
		return (0);
	ret = prev->sibling_next;
	next = ret;
	while (++i < toExcl - 1 && next->sibling_next)
		next = next->sibling_next;
	prev->sibling_next = next;
	next->sibling_prev = prev;
	return (ret);
}
