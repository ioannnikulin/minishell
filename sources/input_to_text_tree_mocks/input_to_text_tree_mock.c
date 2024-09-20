/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_mock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 00:29:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

/* returns error code */
int	input_to_text_tree_mock(t_tree **tree, char *input)
{
	(*tree)->root = ft_treenode_make(TEXT_TREE_ROOT, 0, 0, ft_free_nop);
	if (!((*tree)->root))
		return (2);
	if (mock_1(input, (*tree)->root) || mock_2(input, (*tree)->root)
		|| mock_3(input, (*tree)->root) || mock_4(input, (*tree)->root)
		|| mock_5(input, (*tree)->root) || mock_6(input, (*tree)->root))
		return (0);
	return (3);
}
