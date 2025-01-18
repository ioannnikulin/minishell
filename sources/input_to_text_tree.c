/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 19:45:13 by taretiuk         ###   ########.fr       */
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

int	check_tokens(t_param *param, char ***tokens, int val)
{
	if (val != 0)
	{
		if (val == 1)
			return (ret(param, *tokens, 0, MEMORY_ERROR));
		else if (val == 2)
			return (ret(param, *tokens, 0, EMPTY_LINE));
		else if (val == 3)
			return (ret(param, *tokens, 0, SPACES_ONLY));
	}
	return (0);
}

int	input_to_text_tree(t_param *param)
{
	int		val;
	char	**tokens;
	t_tree	*tree;

	tokens = NULL;
	val = tokenize_cmd(param->cur_command, &tokens);
	if (check_tokens(param, &tokens, val) != 0)
		return (param->opts.errno);
	if (validate_input(tokens) == 0)
		return (ret(param, tokens, 0, MALFORMED_INPUT));
	ft_tree_free(&param->text_tree);
	tree = ft_tree_make();
	if (tree == NULL)
		return (ret(param, tokens, 0, 1));
	if (tokens_to_tree(tree, tokens) != 0)
		return (ret(param, tokens, tree, 1));
	param->text_tree = tree;
	return (ret(param, tokens, 0, 0));
}
