/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 22:17:35 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

int	ft_treenode_insert_child_idx(t_treenode *parent, t_treenode *child, int before_idx)
{
	int			i;
	t_treenode	*after;

	child->parent = parent;
	parent->children_qtty ++;
	after = parent->child;
	if (!after || before_idx <= 0)
	{
		if (before_idx <= 0)
		{
			child->sibling_next = parent->child;
			parent->child->sibling_prev = child;
		}
		parent->child = child;
		return (0);
	}
	i = 0;
	while (++ i < before_idx && after->sibling_next)
		after = after->sibling_next;
	child->sibling_prev = after;
	child->sibling_next = after->sibling_next;
	if (child->sibling_next)
		child->sibling_next->sibling_prev = child;
	after->sibling_next = child;
	return (i);
}

int	ft_treenode_insert_child_before_first(t_treenode *parent, t_treenode *child, int (*cmp)(void *, void *))
{
	int			i;
	t_treenode	*cur;
	t_treenode	*prev;

	child->parent = parent;
	parent->children_qtty ++;
	cur = parent->child;
	if (*(int*)child->content == 4)
		i = 0;
	if (!cur || cmp(child->content, cur->content))
	{
		if (cur && cmp(child->content, cur->content))
		{
			child->sibling_next = cur;
			cur->sibling_prev = child;
		}
		parent->child = child;
		return (0);
	}
	i = 0;
	while (cur && !cmp(child->content, cur->content))
	{
		prev = cur;
		cur = cur->sibling_next;
		i ++;
	}
	child->sibling_next = cur;
	prev->sibling_next = child;
	if (cur)
	{
		child->sibling_prev = cur->sibling_prev;
		child->sibling_prev->sibling_next = child;
		cur->sibling_prev = child;
	}
	return (i);
}
