/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:07:09 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/02 21:04:17 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_to_text_tree_mock_internal.h"

void	mock_7_tree(t_treenode *root)
{
	ft_treenode_insert_child_idx_s_dup(root, "uname", 0);
}

/* returns 1 on success - to allow condition usage outside */
int	mock_7(char *input, t_treenode *root)
{
	if (ft_strcmp(input, MOCK_7_TEXT) != 0)
		return (0);
	mock_7_tree(root);
	return (1);
}
