/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_text_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:20:32 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/20 10:38:00 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing.h"

int	create_text_tree(t_tree **tree, char *input)
{
	*tree = ft_tree_make();
	(*tree)->root = ft_treenode_make(input, 0, 0, ft_free_nop);
	if (!((*tree)->root))
		return (2);
	return (0);
}