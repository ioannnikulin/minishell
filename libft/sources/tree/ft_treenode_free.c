/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/23 23:36:01 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

int	ft_treenode_free(t_treenode **n)
{
	if (!n || !*n)
		return (1);
	(*n)->parent = 0;
	(*n)->sibling_next = 0;
	(*n)->sibling_prev = 0;
	(*n)->child = 0;
	(*n)->freecontent(&(*n)->content);
	(*n)->content = 0;
	free(*n);
	*n = 0;
	return (0);
}

int	ft_treenode_free_rec(t_treenode **n)
{
	if (!n || !*n)
		return (1);
	if ((*n)->sibling_next)
		ft_treenode_free_rec(&(*n)->sibling_next);
	if ((*n)->child)
		ft_treenode_free_rec(&(*n)->child);
	ft_treenode_free(n);
	return (0);
}

int	ft_tree_free(t_tree **t)
{
	int	ret;

	ret = ft_treenode_free_rec(&(*t)->root);
	free(*t);
	return (ret);
}
