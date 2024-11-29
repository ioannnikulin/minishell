/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:22:57 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/29 15:00:04 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing.h"

static void	insert_first_node(char *token, t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, token, 0);
	return ;
}

int	process_tree(char *token, t_tree *tree, t_treenode	**cur, int *num)
{
	if (is_operator(token) || is_redirection(token))
	{
		ft_treenode_insert_child_idx_s_dup(tree->root, token,
			tree->root->children_qtty);
		*num = 1;
	}
	else
	{
		if ((*cur)->parent == tree->root && *num == 1)
		{
			/*for command*/
			ft_treenode_insert_child_idx_s_dup(tree->root, token,
				tree->root->children_qtty);
			while ((*cur)->sibling_next)
				*cur = (*cur)->sibling_next;
			*num = 0;
		}
		else
		{
			/*flag*/
			if (ft_strcmp(token, ")") == 0)
				return (0);
			ft_treenode_insert_child_idx_s_dup(*cur, token,
				(*cur)->children_qtty);
		}
	}
	return (0);
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
	if (tree->root->child == NULL)
		return (1);
	cur = tree->root->child;
	num = 0;
	while (tokens[i] != NULL)
	{
		process_tree(tokens[i], tree, &cur, &num);
		i++;
	}
	return (0);
}
