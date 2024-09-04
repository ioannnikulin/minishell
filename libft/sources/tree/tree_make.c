/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/04 20:19:50 by inikulin         ###   ########.fr       */
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

int	ft_treenode_add_child(t_treenode *parent, t_treenode *child, int before_idx)
{
	int			i;
	t_treenode	*cur;

	i = 0;
	cur = parent->child;
	while (i < before_idx)
	{
		
	}
}
