/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_mock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 13:46:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

static int	ret(int e, char *in)
{
	if (e)
		printf("%s\n", ERR_MALLOC);
	else
		printf("%s: %s\n", in, ERR_COMMAND_NOT_FOUND);
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
	(*tree)->root = ft_treenode_make(TEXT_TREE_ROOT, 0, ft_free_nop);
	if (!((*tree)->root))
		return (2);
	r = (*tree)->root;
	if ((mock_0(in, r, &e) || mock_1(in, r, &e) || mock_2(in, r, &e)
			|| mock_3(in, r, &e) || mock_4(in, r, &e) || mock_5(in, r, &e)
			|| mock_6(in, r, &e) || mock_7(in, r, &e) || mock_8(in, r, &e)
			|| mock_9(in, r, &e) || mock_10(in, r, &e) || mock_11(in, r, &e)
			|| mock_12(in, r, &e) || mock_13(in, r, &e) || mock_14(in, r, &e)
			|| mock_15(in, r, &e) || mock_16(in, r, &e) || mock_17(in, r, &e)
			|| mock_18(in, r, &e) || mock_19(in, r, &e) || mock_20(in, r, &e)
			|| mock_21(in, r, &e) || mock_22(in, r, &e) || mock_23(in, r, &e)
			|| mock_24(in, r, &e) || mock_25(in, r, &e) || mock_26(in, r, &e)
			|| mock_27(in, r, &e)
		) && !e)
		return (0);
	return (ret(e, in));
}
