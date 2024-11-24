/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:22:57 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/24 11:10:33 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing.h"

void	ft_tree_free_wrapper(void **tree)
{
	ft_tree_free((t_tree **)tree);
}

static void	insert_first_node(char *token, t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, token, 0);
	return ;
}

/*where handle errors of root node, on this step or in execution*/
int	tokens_to_tree(t_tree *tree, char **tokens)
{
	int			i;
	int			num;
	t_treenode	*cur;

	i = 0;
	tree->root = ft_treenode_make(TEXT_TREE_ROOT, 0, 0, ft_free_nop);
	if (!tree->root)
		return (2);
	insert_first_node(tokens[i++], tree->root);
	cur = tree->root->child;
	num = 0;
	while (tokens[i] != NULL)
	{
		if (is_operator(tokens[i]) || is_redirection(tokens[i]))
		{
			ft_treenode_insert_child_idx_s_dup(tree->root, tokens[i], tree->root->children_qtty);
			num = 1;
		}
		else 
		{
			if (cur->parent == tree->root && num == 1)
			{
				ft_treenode_insert_child_idx_s_dup(tree->root, tokens[i], tree->root->children_qtty);
				while (cur->sibling_next)
					cur = cur->sibling_next;
				num = 0;
			}
			else
			{
				ft_treenode_insert_child_idx_s_dup(cur, tokens[i], cur->children_qtty);
			}
		}
		i++;
	}
	return (0);
}
