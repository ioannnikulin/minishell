/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:22:57 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/14 12:07:25 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing.h"

void	ft_tree_free_wrapper(void **tree)
{
	ft_tree_free((t_tree **)tree);
}

static void	insert_first_node(char *tokens, t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, tokens, 0);
	return ;
}

/*where handle errors of root node, on this step or in execution*/
int	tokens_to_tree(t_tree *tree, char **tokens)
{
	int	i;
	t_treenode	*cur;
	t_treenode	*root;

	i = 0;
	tree->root = ft_treenode_make(TEXT_TREE_ROOT, 0, 0, ft_free_nop);
	if (!tree->root)
		return (2);
	root = tree->root;
	insert_first_node(tokens[i++], root);
	cur = root->child;
	while (tokens[i] != NULL)
	{
		if (is_operator(tokens[i]) || is_redirection(tokens[i]))
		{
			ft_treenode_insert_child_idx_s_dup(root, tokens[i], root->children_qtty);
		}
		else
		{
			ft_treenode_insert_child_idx_s_dup(cur, tokens[i], cur->children_qtty);
		}
		i++;
	}
	return (0);
}
