/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_insert_wrappers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:47:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 13:44:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

int	ft_treenode_insert_child_idx_s_free(t_treenode *parent, char *s,
		int before_idx)
{
	return (ft_treenode_insert_child_idx(parent, \
		ft_treenode_make(s, 0, ft_free_s_null), before_idx));
}

int	ft_treenode_insert_child_idx_s_nop(t_treenode *parent, char *s,
		int before_idx)
{
	return (ft_treenode_insert_child_idx(parent, \
		ft_treenode_make(s, 0, ft_free_nop), before_idx));
}

int	ft_treenode_insert_child_idx_s_dup(t_treenode *parent, char *s,
		int before_idx)
{
	char		*val;
	t_treenode	*node;

	val = ft_strdup(s);
	if (!val)
		return (-1);
	node = ft_treenode_make(val, 0, ft_free_s_null);
	if (!node)
	{
		free(val);
		return (-1);
	}
	return (ft_treenode_insert_child_idx(parent, node, before_idx));
}
