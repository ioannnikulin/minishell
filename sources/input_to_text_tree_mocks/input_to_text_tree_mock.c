/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_text_tree_mock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 20:47:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

/* returns error code */
int	input_to_text_tree_mock(t_tree **tree, char *input)
{
	*tree = ft_tree_make();
	(*tree)->root = ft_treenode_make(TEXT_TREE_ROOT, 0, 0, ft_free_nop);
	if (!((*tree)->root))
		return (2);
	if (mock_0(input, (*tree)->root)
		|| mock_1(input, (*tree)->root)
		|| mock_2(input, (*tree)->root)
		|| mock_3(input, (*tree)->root)
		|| mock_4(input, (*tree)->root)
		|| mock_5(input, (*tree)->root)
		|| mock_6(input, (*tree)->root)
		|| mock_7(input, (*tree)->root)
		|| mock_8(input, (*tree)->root)
		|| mock_9(input, (*tree)->root)
		|| mock_10(input, (*tree)->root)
	)
		return (0);
	printf("%s: %s\n", input, ERR_COMMAND_NOT_FOUND);
	return (3);
}
