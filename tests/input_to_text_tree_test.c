/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:53:00 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 00:38:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_common.h"

static int	test1(t_param *param)
{
	param->history.last->text = "   echo hello\n  world ";
	assert(input_to_text_tree(param) == 0);
	ft_tree_print_s(param->text_tree);
	return (0);
}

int	input_to_text_tree_test(void)
{
	t_param	*param = ft_calloc_if(sizeof(t_param), 1);
	param->history.last = ft_calloc_if(sizeof(t_history_entry), 1);
	param->text_tree = ft_tree_make();
	assert(test1(param) == 0);
	return (0);
}
