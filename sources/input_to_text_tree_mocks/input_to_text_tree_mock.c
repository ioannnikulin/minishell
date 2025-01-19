/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_mock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/19 10:53:38 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static int	ret(int e, char *in)
{
	if (e)
		ERR("%s\n", ERR_MALLOC);
	else
		ERR("%s: %s\n", in, ERR_COMMAND_NOT_FOUND);
	return (3);
}

/* returns error code */
int	input_to_text_tree_mock(t_tree **tree, char *in)
{
	int			e;
	t_treenode	*r;

	e = 0;
	*tree = ft_tree_make();
	if (!*tree)
		return (4);
	(*tree)->root = treenode_make(TEXT_TREE_ROOT, 0, ft_free_nop);
	if (!((*tree)->root))
		return (2);
	r = (*tree)->root;
	if ((mock_00(in, r, &e) || mock_01(in, r, &e) || mock_02(in, r, &e)
			|| mock_03(in, r, &e) || mock_04(in, r, &e) || mock_05(in, r, &e)
			|| mock_06(in, r, &e) || mock_07(in, r, &e) || mock_08(in, r, &e)
			|| mock_09(in, r, &e) || mock_10(in, r, &e) || mock_11(in, r, &e)
			|| mock_12(in, r, &e) || mock_13(in, r, &e) || mock_14(in, r, &e)
			|| mock_15(in, r, &e) || mock_16(in, r, &e) || mock_17(in, r, &e)
			|| mock_18(in, r, &e) || mock_19(in, r, &e) || mock_20(in, r, &e)
			|| mock_21(in, r, &e) || mock_22(in, r, &e) || mock_23(in, r, &e)
			|| mock_24(in, r, &e) || mock_25(in, r, &e) || mock_26(in, r, &e)
			|| mock_27(in, r, &e) || mock_28(in, r, &e) || mock_29(in, r, &e)
			|| mock_30(in, r, &e) || mock_31(in, r, &e) || mock_32(in, r, &e)
		) && !e)
		return (0);
	return (ret(e, in));
}
