/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:22:57 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/04 17:37:57 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing.h"

void	ft_tree_free_wrapper(void **tree)
{
	ft_tree_free((t_tree **)tree);
}

int	tokens_to_tree(t_tree *tree, char **tokens)
{
	if (tokens == NULL || tokens[0] == NULL)
		return (1);
	tree->root = ft_treenode_make(tokens[0], NULL, 0, ft_tree_free_wrapper);
	if (!tree->root)
		return (1);
	return (0);
}
