/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 23:53:00 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/05 20:10:19 by inikulin         ###   ########.fr       */
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
	t_treenode *exp_node = ft_treenode_make(TEXT_TREE_ROOT, 0, ft_free_nop);
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
	assert(a_test(param, MOCK_00_TEXT, mock_00_tree, 0) == 0);
	assert(a_test(param, MOCK_01_TEXT, mock_01_tree, 1) == 0);
	assert(a_test(param, MOCK_02_TEXT, mock_02_tree, 2) == 0);
	assert(a_test(param, MOCK_03_TEXT, mock_03_tree, 3) == 0);
	assert(a_test(param, MOCK_04_TEXT, mock_04_tree, 4) == 0);
	assert(a_test(param, MOCK_05_TEXT, mock_05_tree, 5) == 0);
	assert(a_test(param, MOCK_06_TEXT, mock_06_tree, 6) == 0);
	assert(a_test(param, MOCK_07_TEXT, mock_07_tree, 7) == 0);
	assert(a_test(param, MOCK_08_TEXT, mock_08_tree, 8) == 0);
	assert(a_test(param, MOCK_09_TEXT, mock_09_tree, 9) == 0);
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
	assert(a_test(param, MOCK_27_TEXT, mock_27_tree, 27) == 0);
	assert(a_test(param, MOCK_28_TEXT, mock_28_tree, 28) == 0);
	assert(a_test(param, MOCK_30_TEXT, mock_30_tree, 30) == 0);
  assert(a_test(param, MOCK_31_TEXT, mock_31_tree, 31) == 0);
  assert(a_test(param, MOCK_32_TEXT, mock_32_tree, 32) == 0);
  assert(a_test(param, MOCK_33_TEXT, mock_33_tree, 33) == 0);
	ft_tree_free(&param->text_tree);
	free(param);
	return (0);
}
