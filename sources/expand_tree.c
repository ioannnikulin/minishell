/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:11:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/12 22:08:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tree_make/tree_processing_internal.h"

static int	expand_cmd(t_treenode *node, int *i)
{
	char		*nc;
	t_treenode	*new;
	int			j;
	t_treenode	*next;

	if (!node || !node->sibling_next)
		return (0);
	nc = node->sibling_next->content;
	if (ft_strcmp(nc, "|") && !is_redirection(nc))
	{
		*i += 2;
		return (expand_cmd(node->sibling_next->sibling_next, i));
	}
	ft_treenode_insert_child_idx_s_nop(node->parent, TEXT_TREE_BLOCK, *i);
	new = node->parent->child;
	j = -1;
	while (++j < *i)
		new = new->sibling_next;
	ft_treenode_insert_child_idx(new, node, 0);
	next = node->sibling_next->sibling_next->sibling_next;
	node->sibling_next->sibling_next->sibling_next = 0;
	new->sibling_next = next;
	if (next)
		next->sibling_prev = new;
	return (expand_cmd(new, i));
}

int	expand_tree(t_param *param)
{
	t_treenode	*node;
	int			i;

	node = param->text_tree->root->child;
	i = 0;
	return (expand_cmd(node, &i));
}
