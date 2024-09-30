/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenode_insert_wrappers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:47:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 21:22:25 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "../../libft.h"

int	ft_treenode_insert_child_idx_s_free(t_treenode *parent, char *s,
		int before_idx)
{
	return (ft_treenode_insert_child_idx(parent, \
		ft_treenode_make(s, 0, 1, ft_free_s), before_idx));
}

int	ft_treenode_insert_child_idx_s_nop(t_treenode *parent, char *s,
		int before_idx)
{
	return (ft_treenode_insert_child_idx(parent, \
		ft_treenode_make(s, 0, 1, ft_free_nop), before_idx));
}

int	ft_treenode_insert_child_idx_s_dup(t_treenode *parent, char *s,
		int before_idx)
{
	return (ft_treenode_insert_child_idx(parent, \
		ft_treenode_make(ft_strdup(s), 0, 1, ft_free_s), before_idx));
}
