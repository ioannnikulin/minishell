/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 20:47:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_10_tree(t_treenode *cur)
{
	ft_treenode_insert_child_idx_s_dup(cur, "pwd", 0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_10(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_10_TEXT) != 0)
		return (0);
	mock_10_tree(root);
	return (1);
}
