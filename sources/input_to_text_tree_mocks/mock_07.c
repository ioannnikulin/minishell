/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/10 17:18:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

int	mock_07_tree(t_treenode *root)
{
	if (ft_treenode_insert_child_idx_s_dup(root, "uname", 0) == -1)
		return (1);
	return (0);
}

int	mock_07_tree_expanded(t_treenode *root)
{
	return (mock_07_tree(root));
}

/* returns 1 on success - to allow condition usage outside */
int	mock_07(char *input, t_treenode *root, int *errno)
{
	if (ft_strcmp(input, MOCK_07_TEXT) != 0 && ft_strcmp(input, "MOCK_07") != 0)
		return (0);
	if (mock_07_tree(root))
		return (ft_assign_i(errno, 1, 1));
	return (1);
}
