/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:22:57 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/13 13:06:28 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing.h"

void	ft_tree_free_wrapper(void **tree)
{
	ft_tree_free((t_tree **)tree);
}

int	insert_first_child(t_tree *tree, char **tokens, int *i)
{
	int	chld_idx;

	chld_idx = 0;
	chld_idx = ft_treenode_insert_child_idx_s_dup(tree->root, tokens[(*i)++], chld_idx);
	return (chld_idx);
}

void	insert_child(t_tree *tree, char *tokens, t_treenode	*cur, int *idx)
{
	char	*cmp;

	cmp = NULL;
	
	cmp = ft_strdup(cur->content);
	if (ft_strcmp(cur, cmp) == 0)
		*idx++;
	else
		*idx = 0;
	ft_treenode_insert_child_idx_s_dup(cur,  tokens, *idx);
}

/*where handle errors of root node, on this step or in execution*/
int	tokens_to_tree(t_tree *tree, char **tokens)
{
	int	i;
	int	c_idx;
	int	s_idx;
	t_treenode	*cur;

	i = 0;
	c_idx = 0;
	s_idx = 0;
	tree->root = ft_treenode_make(TEXT_TREE_ROOT, 0, 0, ft_free_nop);
	if (!tree->root)
		return (2);
	c_idx = insert_first_child(tree, tokens, &i);
	cur = tree->root->child;
	while (tokens[i++] != NULL)
	{
		if (is_operator(tokens[i]) || is_redirection(tokens[i]))
		{
			s_idx++;
			s_idx = ft_treenode_insert_child_idx_s_dup(tree->root, tokens[i], s_idx);
		}
		else
		{
			insert_child(tree, tokens[i], cur, &c_idx);
		}
	}
	return (0);
}
