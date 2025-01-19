/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tree_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:21:08 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 14:17:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#include "../sources/input_to_text_tree_mocks/input_to_text_tree_mock.h"
#define SZ 33
#define START 0
//#define DEBUG

typedef struct s_testcase
{
	t_tree	*src;
	t_tree	*exp;
}	t_testcase;

static int	populate_tests(t_testcase t[]);

int	expand_tree_test(void)
{
	t_testcase	t[SZ];
	populate_tests(t);
	t_param	param;

	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		FT_PRINTF("%i\n", i);
		#endif
		param.text_tree = t[i].src;
		assert(expand_tree(&param) == 0);
		int cmpres = ft_tree_cmp(t[i].exp, param.text_tree, cmd_cmp);
		#ifdef DEBUG
		if (cmpres != 0)
		{
			ft_tree_print(t[i].exp, cmd_txt, "\t");
			ft_tree_print(param.text_tree, cmd_txt, "\t");
		}
		#endif
		assert(cmpres == 0);
		ft_tree_free(&t[i].src);
		ft_tree_free(&t[i].exp);
	}
	return (0);
}

static int	populate_tests(t_testcase t[])
{
	for (int i = 0; i < 33; i ++)
	{
		t[i].src = ft_tree_make();
		t[i].src->root = treenode_make(TEXT_TREE_ROOT, 0, ft_free_nop);
		t[i].exp = ft_tree_make();
		t[i].exp->root = treenode_make(TEXT_TREE_ROOT, 0, ft_free_nop);
	}
	mock_00_tree(t[0].src->root);
	mock_00_tree_expanded(t[0].exp->root);
	mock_01_tree(t[1].src->root);
	mock_01_tree_expanded(t[1].exp->root);
	mock_02_tree(t[2].src->root);
	mock_02_tree_expanded(t[2].exp->root);
	mock_03_tree(t[3].src->root);
	mock_03_tree_expanded(t[3].exp->root);
	mock_04_tree(t[4].src->root);
	mock_04_tree_expanded(t[4].exp->root);
	mock_05_tree(t[5].src->root);
	mock_05_tree_expanded(t[5].exp->root);
	mock_06_tree(t[6].src->root);
	mock_06_tree_expanded(t[6].exp->root);
	mock_07_tree(t[7].src->root);
	mock_07_tree_expanded(t[7].exp->root);
	mock_08_tree(t[8].src->root);
	mock_08_tree_expanded(t[8].exp->root);
	mock_09_tree(t[9].src->root);
	mock_09_tree_expanded(t[9].exp->root);
	mock_10_tree(t[10].src->root);
	mock_10_tree_expanded(t[10].exp->root);
	mock_11_tree(t[11].src->root);
	mock_11_tree_expanded(t[11].exp->root);
	mock_12_tree(t[12].src->root);
	mock_12_tree_expanded(t[12].exp->root);
	mock_13_tree(t[13].src->root);
	mock_13_tree_expanded(t[13].exp->root);
	mock_14_tree(t[14].src->root);
	mock_14_tree_expanded(t[14].exp->root);
	mock_15_tree(t[15].src->root);
	mock_15_tree_expanded(t[15].exp->root);
	mock_16_tree(t[16].src->root);
	mock_16_tree_expanded(t[16].exp->root);
	mock_17_tree(t[17].src->root);
	mock_17_tree_expanded(t[17].exp->root);
	mock_18_tree(t[18].src->root);
	mock_18_tree_expanded(t[18].exp->root);
	mock_19_tree(t[19].src->root);
	mock_19_tree_expanded(t[19].exp->root);
	mock_20_tree(t[20].src->root);
	mock_20_tree_expanded(t[20].exp->root);
	mock_21_tree(t[21].src->root);
	mock_21_tree_expanded(t[21].exp->root);
	mock_22_tree(t[22].src->root);
	mock_22_tree_expanded(t[22].exp->root);
	mock_23_tree(t[23].src->root);
	mock_23_tree_expanded(t[23].exp->root);
	mock_24_tree(t[24].src->root);
	mock_24_tree_expanded(t[24].exp->root);
	mock_25_tree(t[25].src->root);
	mock_25_tree_expanded(t[25].exp->root);
	mock_26_tree(t[26].src->root);
	mock_26_tree_expanded(t[26].exp->root);
	mock_27_tree(t[27].src->root);
	mock_27_tree_expanded(t[27].exp->root);
	mock_28_tree(t[28].src->root);
	mock_28_tree_expanded(t[28].exp->root);
	mock_29_tree(t[29].src->root);
	mock_29_tree_expanded(t[29].exp->root);
	mock_30_tree(t[30].src->root);
	mock_30_tree_expanded(t[30].exp->root);
	mock_31_tree(t[31].src->root);
	mock_31_tree_expanded(t[31].exp->root);
	mock_32_tree(t[32].src->root);
	mock_32_tree_expanded(t[32].exp->root);
	return (0);
}
