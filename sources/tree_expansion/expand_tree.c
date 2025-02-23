/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:11:36 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 17:38:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tree_make/tree_processing_internal.h"

//whole file unused currently, keeping logic just in case
static int	expand_cmd(t_treenode *node, int *i)
{
	char		*nc;
	t_treenode	*new;
	int			j;

	j = 0;
	if (node && ft_strcmp(TEXT_TREE_BLOCK, *get_node_txt(node)) == 0)
		expand_cmd(node->child, &j);
	if (!node || !node->sibling_next)
		return (0);
	nc = *get_node_txt(node->sibling_next);
	if (ft_strcmp(nc, "|") && !is_redirection(nc))
	{
		*i += 2;
		return (expand_cmd(next_node(node), i));
	}
	if (treenode_insert_nop(node->parent,
			TEXT_TREE_BLOCK_REDIR, *i) != *i)
		return (1);
	new = node->parent->child;
	j = -1;
	while (++j < *i)
		new = new->sibling_next;
	new->child = ft_treenode_cut(new->parent, *i + 1, *i + 4);
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
