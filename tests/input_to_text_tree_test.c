/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:53:00 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/29 20:34:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#include "../sources/input_to_text_tree_mocks/input_to_text_tree_mock.h"
//#define DEBUG

static int	a_test(t_param *param, char *input, int (*treegen)(t_treenode *), int i)
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
	param->cur_command = input;
	assert(input_to_text_tree(param) == 0);
	#ifdef DEBUG
	ft_tree_print_s(exp_tree);
	ft_tree_print_s(param->text_tree);
	#endif
	assert(ft_tree_cmp_s(exp_tree, param->text_tree) == 0);
	ft_tree_free(&exp_tree);
	return (0);
}

int	input_to_text_tree_test(void)
{
	t_param	*param = ft_calloc(sizeof(t_param), 1);
	param->text_tree = ft_tree_make();
	assert(a_test(param, MOCK_0_TEXT, mock_0_tree, 0) == 0);
	assert(a_test(param, MOCK_1_TEXT, mock_1_tree, 1) == 0);
	assert(a_test(param, MOCK_2_TEXT, mock_2_tree, 2) == 0);
	assert(a_test(param, MOCK_3_TEXT, mock_3_tree, 3) == 0);
	assert(a_test(param, MOCK_4_TEXT, mock_4_tree, 4) == 0);
	assert(a_test(param, MOCK_5_TEXT, mock_5_tree, 5) == 0);
	assert(a_test(param, MOCK_6_TEXT, mock_6_tree, 6) == 0);
	assert(a_test(param, MOCK_7_TEXT, mock_7_tree, 7) == 0);
	assert(a_test(param, MOCK_8_TEXT, mock_8_tree, 8) == 0);
	assert(a_test(param, MOCK_9_TEXT, mock_9_tree, 9) == 0);
	assert(a_test(param, MOCK_10_TEXT, mock_10_tree, 10) == 0);
	assert(a_test(param, MOCK_11_TEXT, mock_11_tree, 11) == 0);
	assert(a_test(param, MOCK_12_TEXT, mock_12_tree, 12) == 0);
	assert(a_test(param, MOCK_13_TEXT, mock_13_tree, 13) == 0);
	assert(a_test(param, MOCK_14_TEXT, mock_14_tree, 14) == 0);
	assert(a_test(param, MOCK_15_TEXT, mock_15_tree, 15) == 0);
	assert(a_test(param, MOCK_16_TEXT, mock_16_tree, 16) == 0);
	assert(a_test(param, MOCK_17_TEXT, mock_17_tree, 17) == 0);
	assert(a_test(param, MOCK_18_TEXT, mock_18_tree, 18) == 0);
	assert(a_test(param, MOCK_19_TEXT, mock_19_tree, 19) == 0);
	assert(a_test(param, MOCK_20_TEXT, mock_20_tree, 20) == 0);
	assert(a_test(param, MOCK_21_TEXT, mock_21_tree, 21) == 0);
	assert(a_test(param, MOCK_22_TEXT, mock_22_tree, 22) == 0);
	assert(a_test(param, MOCK_23_TEXT, mock_23_tree, 23) == 0);
	assert(a_test(param, MOCK_24_TEXT, mock_24_tree, 24) == 0);
	assert(a_test(param, MOCK_25_TEXT, mock_25_tree, 25) == 0);
	assert(a_test(param, MOCK_26_TEXT, mock_26_tree, 26) == 0);
	ft_tree_free(&param->text_tree);
	free(param);
	return (0);
}
