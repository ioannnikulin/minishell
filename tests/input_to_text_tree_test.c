/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:53:00 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 21:30:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#include "../sources/input_to_text_tree_mocks/input_to_text_tree_mock.h"
//#define DEBUG

static int	a_test(t_param *param, char *input, void (*treegen)(t_treenode *), int i)
{
	#ifdef DEBUG
	ft_printf("%i\n", i);
	#endif
	(void)i;
	t_tree *exp_tree = ft_tree_make();
	assert(exp_tree);
	t_treenode *exp_node = ft_treenode_make(TEXT_TREE_ROOT, 0, 0, ft_free_nop);
	assert(exp_node);
	exp_tree->root = exp_node;
	treegen(exp_node);
	param->history.last->text = input;
	assert(input_to_text_tree(param) == 0);
	assert(ft_tree_cmp_s(exp_tree, param->text_tree) == 0);
	ft_tree_free(&exp_tree);
	return (0);
}

int	input_to_text_tree_test(void)
{
	t_param	*param = ft_calloc_if(sizeof(t_param), 1);
	param->history.last = ft_calloc_if(sizeof(t_history_entry), 1);
	param->text_tree = ft_tree_make();
	assert(a_test(param, MOCK_0_TEXT, mock_0_tree, 0) == 0);
	assert(a_test(param, MOCK_1_TEXT, mock_1_tree, 1) == 0);
	assert(a_test(param, MOCK_2_TEXT, mock_2_tree, 2) == 0);
	assert(a_test(param, MOCK_3_TEXT, mock_3_tree, 3) == 0);
	assert(a_test(param, MOCK_4_TEXT, mock_4_tree, 4) == 0);
	assert(a_test(param, MOCK_5_TEXT, mock_5_tree, 5) == 0);
	assert(a_test(param, MOCK_6_TEXT, mock_6_tree, 6) == 0);
	ft_tree_free(&param->text_tree);
	free(param->history.last);
	free(param);
	return (0);
}