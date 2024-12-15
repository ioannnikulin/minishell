/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 21:51:29 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizing/tokenizing.h"

static int	ret(char **tokens, t_tree *tree, int ret)
{
	ft_free_ss_uptonull((void **)tokens);
	ft_tree_free(&tree);
	return (ret);
}

int	input_to_text_tree(t_param *param)
{
	char	**tokens;
	t_tree	*tree;

	tokens = NULL;
	if (tokenize_cmd(param->cur_command, &tokens) != 0)
		return (ret(tokens, 0, 1));
	if (tokens == NULL || tokens[0] == NULL)
		return (ret(tokens, 0, 4));
	ft_tree_free(&param->text_tree);
	tree = ft_tree_make();
	if (tree == NULL)
		return (ret(tokens, 0, 2));
	if (tokens_to_tree(tree, tokens) != 0)
		return (ret(tokens, tree, 3));
	param->text_tree = tree;
	return (ret(tokens, 0, 0));
}

