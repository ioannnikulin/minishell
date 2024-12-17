/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_cut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:23:32 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 18:37:12 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

static t_treenode	*top(t_treenode *parent, int to_excl)
{
	t_treenode	*next;
	t_treenode	*ret;
	int			i;

	ret = parent->child;
	next = ret;
	i = -1;
	while (++i < to_excl && next)
		next = next->sibling_next;
	if (next)
	{
		next->sibling_prev->sibling_next = 0;
		next->sibling_prev = 0;
	}
	parent->child = next;
	return (ret);
}

t_treenode	*ft_treenode_cut(t_treenode *parent, int from_incl, int to_excl)
{
	int			i;
	t_treenode	*prev;
	t_treenode	*next;
	t_treenode	*ret;

	if (!parent || to_excl <= from_incl || ft_assign_i(&i, 0, 0))
		return (0);
	if (from_incl == 0)
		return (top(parent, to_excl));
	prev = parent->child;
	while (++ i < from_incl && prev->sibling_next)
		prev = prev->sibling_next;
	if (i != from_incl)
		return (0);
	ret = prev->sibling_next;
	next = ret;
	while (++i <= to_excl && next)
		next = next->sibling_next;
	prev->sibling_next = next;
	if (next)
	{
		next->sibling_prev->sibling_next = 0;
		next->sibling_prev = prev;
	}
	return (ret);
}
