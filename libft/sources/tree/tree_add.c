/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:47:29 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/04 19:05:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

static int	deep(t_treenode *n, int (*check)(t_treenode*), int (*apply)(t_treenode*),
				t_tree_traversal_mode mode)
{
	int	i;
	int	applied;

	i = -1;
	applied = 0;
	while (++ i < n.children_sz && mode.max_applications > 0)
	{
		if (mode.max_applications > 0)
		{
			mode.max_applications -= applied;
			applied += deep(n->children[i], check, apply, mode);
		}
	}
	if (mode.max_applications > 0 && check(n))
	{
		apply(n);
		applied ++;
	}
	return (applied);
}

int	ft_tree_apply(t_tree *tgt, int (*check)(t_treenode*), int (*apply)(t_treenode*),
				t_tree_traversal_mode mode)
{
	int	applied;

	if (mode.mode == TREE_DEPTH_FIRSTH)
		applied = deep(tgt.root, check, apply, mode);
	else
		return (-1);
	return (applied);
}
