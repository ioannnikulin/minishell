/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 15:46:28 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizing/input_processing.h"

static int	ret(char **tokens, int sz, t_tree *tree, int ret)
{
	ft_free_ss_sz((void **)tokens, sz + 1);
	ft_tree_free(&tree);
	return (ret);
}

int	input_to_text_tree(t_param *param)
{
	int		sz;
	char	**tokens;
	t_tree	*tree;

	sz = 0;
	tokens = NULL;
	if (tokenize_cmd(param->cur_command, &sz, &tokens) != 0)
		return (ret(tokens, sz, 0, 1));
	if (tokens == NULL || tokens[0] == NULL)
		return (ret(tokens, sz, 0, 4));
	ft_tree_free(&param->text_tree);
	tree = ft_tree_make();
	if (tree == NULL)
		return (ret(tokens, sz, 0, 2));
	if (tokens_to_tree(tree, tokens) != 0)
		return (ret(tokens, sz, tree, 3));
	param->text_tree = tree;
	return (ret(tokens, sz, 0, 0));
}
