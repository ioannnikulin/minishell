/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 18:08:41 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizing/tokenizing.h"
#include "command_validation/command_validation.h"

static int	ret(t_param *param, char **tokens, t_tree *tree, int ret)
{
	ft_free_ss_uptonull((void **)tokens);
	ft_tree_free(&tree);
	ft_assign_i(&param->opts.errno, ret, 0);
	return (ret);
}

int	input_to_text_tree(t_param *param)
{
	int		val;
	char	**tokens;
	t_tree	*tree;

	tokens = NULL;
	val = tokenize_cmd(param->cur_command, &tokens);
	if (val != 0)
		return (ret(param, tokens, 0, val));
	ft_tree_free(&param->text_tree);
	tree = ft_tree_make();
	if (tree == NULL)
		return (ret(param, tokens, 0, 2));
	if (tokens_to_tree(tree, tokens) != 0)
		return (ret(param, tokens, tree, 3));
	param->text_tree = tree;
	return (ret(param, tokens, 0, 0));
}
