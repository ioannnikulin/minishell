/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_cut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:23:32 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/13 12:31:07 by inikulin         ###   ########.fr       */
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
	while (++i < toExcl && next)
		next = next->sibling_next;
	if (next)
	{
		next->sibling_prev->sibling_next = 0;
		next->sibling_prev = 0;
	}
	parent->child = next;
	return (ret);
}

t_treenode	*ft_treenode_cut(t_treenode *parent, int fromIncl, int toExcl)
{
	int			i;
	t_treenode	*prev;
	t_treenode	*next;
	t_treenode	*ret;

	if (!parent || toExcl <= fromIncl || ft_assign_i(&i, 0, 0))
		return (0);
	if (fromIncl == 0)
		return (top(parent, toExcl));
	prev = parent->child;
	while (++ i < fromIncl && prev->sibling_next)
		prev = prev->sibling_next;
	if (i != fromIncl)
		return (0);
	ret = prev->sibling_next;
	next = ret;
	while (++i <= toExcl && next)
		next = next->sibling_next;
	prev->sibling_next = next;
	if (next)
	{
		next->sibling_prev->sibling_next = 0;
		next->sibling_prev = prev;
	}
	return (ret);
}
