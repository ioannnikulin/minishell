/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/18 11:14:42 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing/input_processing_internal.h"
#ifdef MOCK_TANIA
# include "input_to_text_tree_mocks/input_to_text_tree_mock.h"

int	input_to_text_tree(t_param *param)
{
	t_tree	*tree;
	char	*s;
	int		ret;

	s = param->cur_command;
	tree = ft_tree_make();
	ret = input_to_text_tree_mock(&tree, s);
	ft_tree_free(&param->text_tree);
	param->text_tree = tree;
	return (ret);
}

#else

// to parse cur->command.
// first i parse to array of strings splited by tokens and by spaces second.
// then i allocate space for tree in input_to_text_tree().
// then i pass one by one each token to input_text_tree_mocks to create nodes.
int	input_to_text_tree(t_param *param)
{
	char	**tokens;
	t_tree	*res;

	(void)param;
	tokens = parse_command(param->cur_command);
	if (tokens == NULL)
		return (1);
	if (res = ft_calloc_if(sizeof(t_tree), 1) == 0)
		return (1);
	return (0);
}
#endif
