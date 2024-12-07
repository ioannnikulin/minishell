/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:11:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/07 21:40:38 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tree_make/tree_processing_internal.h"

static int	expand_cmd(t_treenode *node, int i)
{
	char		*nc;
	t_treenode	*new;

	nc = node->sibling_next->content;
	if (!ft_strcmp(nc, "|") || is_redirection(nc))
	{
		ft_tree_insert_child_idx_s_nop(node->parent, TEXT_TEE_BLOCK, i);
		new = node->parent;
		while (i -- > 0)
			new = new->sibling_next;
		node->parent = new;
//TODO
	}
}

int	expand_tree(t_param *param)
{
	t_treenode	*node;
	int			i;

	node = param->text_tree->root;
	
}
