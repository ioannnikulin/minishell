/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/28 15:30:36 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#ifdef MOCK_TANIA
# include "tokenizing/input_processing.h"
# include "input_to_text_tree_mocks/input_to_text_tree_mock.h"

int	input_to_text_tree(t_param *param)
{
	t_tree	*tree;
	char	*s;
	int		ret;

	s = param->cur_command;
	ret = input_to_text_tree_mock(&tree, s);
	ft_tree_free(&param->text_tree);
	param->text_tree = tree;
	return (ret);
}

#else

int	input_to_text_tree(t_param *param)
{
	int		sz;
	char	**tokens;
	t_tree	*tree;

	sz = 0;
	tokenize_cmd(param->cur_command, &sz, &tokens);
	if (tokens == NULL || tokens[0] == NULL)
		return (1);
	tree = ft_tree_make();
	if (tree == NULL)
		return (2);
	if (tokens_to_tree(tree, tokens) != 0)
	{
		ft_tree_free(&param->text_tree);
		ft_free_ss_sz((void **)tokens, sz);
		return (3);
	}
	param->text_tree = tree;
	ft_free_ss_sz_null((void *)&tokens, sz+1);
	return (0);
}
#endif
