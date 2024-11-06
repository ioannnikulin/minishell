/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:22:57 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/06 19:11:29 by taretiuk         ###   ########.fr       */
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
	int	chld_idx;
	int	sib_idx;
	t_treenode	*cur;

	i = 0;
	chld_idx = 0;
	sib_idx = 0;
	chld_idx = insert_first_child(tree, tokens, &i);
	cur = tree->root->child;
	while (tokens[i++] != NULL)
	{
		if (is_operator(tokens[i]) || is_redirection(tokens[i]))
		{
			sib_idx++;
			sib_idx = ft_treenode_insert_child_idx_s_dup(tree->root, tokens[i], sib_idx);
		}
		else
		{
			insert_child(tree, tokens[i], cur, &chld_idx);
		}
	}
	return (0);
}
