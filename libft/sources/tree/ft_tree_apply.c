/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:47:29 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 22:34:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

static int	deep(t_treenode *n, int (*check)(t_treenode*),
				int (*apply)(t_treenode*), t_tree_traversal_mode mode)
{
	t_treenode	*child;
	int			applied;
	int			applied_total;

	child = n->child;
	applied_total = 0;
	while (child && mode.max_applications > 0)
	{
		if (mode.max_applications > 0)
		{
			applied = deep(child, check, apply, mode);
			mode.max_applications -= applied;
			applied_total += applied;
		}
	}
	if (mode.max_applications > 0 && check(n))
	{
		apply(n);
		applied_total ++;
	}
	return (applied_total);
}

int	ft_tree_apply(t_tree *tgt, int (*check)(t_treenode*),
				int (*apply)(t_treenode*), t_tree_traversal_mode mode)
{
	int	applied;

	if (mode.mode == TREE_DEPTH_FIRST)
		applied = deep(tgt->root, check, apply, mode);
	else
		return (-1);
	return (applied);
}
