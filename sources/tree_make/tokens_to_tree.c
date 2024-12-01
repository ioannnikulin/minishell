/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:22:57 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/01 20:43:15 by taretiuk         ###   ########.fr       */
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
	t_treenode *tmp;

	tmp = NULL;
	if (is_operator(token) || is_redirection(token))
	{
		ft_treenode_insert_child_idx_s_dup(*cur_1, token,
			(*cur_1)->children_qtty);
		*num = 1;
	}
	else if (is_opening_parenthesis(token))
	{
		ft_treenode_insert_child_idx_s_dup(*cur_1, token,
			(*cur_1)->children_qtty);
		tmp = *cur_2;
		while (tmp && tmp->sibling_next)
			tmp = tmp->sibling_next;
		if (tmp)
			*cur_1 = tmp; 
		*num = 2;
	}
	else if (is_closing_parenthesis(token))
	{
		*cur_1 = (*cur_1)->parent;
		*cur_2 = (*cur_1)->child;
		*num = 0;
	}
	else
	{
		/*command after paranthesis*/
		if ((ft_strcmp((*cur_1)->content, "(") == 0) && *num == 2)
		{
			ft_treenode_insert_child_idx_s_dup(*cur_1, token,
				(*cur_1)->children_qtty);
			*cur_2 = (*cur_1)->child;
			*num = 0;
		}
		/*command normal*/
		else if ((*cur_2)->parent == *cur_1 && *num == 1)
		{
			ft_treenode_insert_child_idx_s_dup(*cur_1, token,
					(*cur_1)->children_qtty);
			while ((*cur_2)->sibling_next)
				*cur_2 = (*cur_2)->sibling_next;
			*num = 0;
		}
		/*flag*/
		else
		{
			ft_treenode_insert_child_idx_s_dup(*cur_2, token,
				(*cur_2)->children_qtty);
		}
	}
	return (0);
}

/*where handle errors of root node, on this step or in execution*/
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
		process_tree(tokens[i], &cur_1, &cur_2, &num);
		i++;
	}
	return (0);
}
