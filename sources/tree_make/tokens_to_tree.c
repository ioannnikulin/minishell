/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:22:57 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/02 19:30:12 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing.h"

static void	insert_first_node(char *token, t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, token, 0);
	return ;
}

int	process_tree(char *token, t_treenode **cur_1,
			t_treenode	**cur_2, int *num)
{
	if (is_operator(token) || is_redirection(token))
	{
		if (process_operator(token, cur_1, num) != 0)
			return (1);
	}
	else if (is_opening_parenthesis(token))
	{
		if (process_open_parentheses(token, cur_1, cur_2, num) != 0)
			return (1);
	}
	else if (is_closing_parenthesis(token))
	{
		if (process_closing_parentheses(cur_1, cur_2, num) != 0)
			return (1);
	}
	else
	{
		if (process_cmd_and_flag(token, cur_1, cur_2, num) != 0)
			return (1);
	}
	return (0);
}

int	tokens_to_tree(t_tree *tree, char **tokens)
{
	int			i;
	int			num;
	t_treenode	*cur_1;
	t_treenode	*cur_2;

	i = 0;
	tree->root = ft_treenode_make(TEXT_TREE_ROOT, 0, 0, ft_free_nop);
	if (!tree->root)
		return (2);
	insert_first_node(tokens[i++], tree->root);
	if (tree->root->child == NULL)
		return (1);
	cur_1 = tree->root;
	cur_2 = tree->root->child;
	num = 0;
	while (tokens[i] != NULL)
	{
		if (process_tree(tokens[i], &cur_1, &cur_2, &num) != 0)
			return (1);
		i++;
	}
	return (0);
}
