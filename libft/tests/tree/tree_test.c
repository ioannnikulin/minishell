/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:27:04 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/12 22:54:23 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tree_test.h"

int	tree_test(void)
{
	FT_PRINTF("tree: ft_treenode_insert_child_idx in testing\n");
	ft_treenode_insert_child_idx_test();
	FT_PRINTF("tree: ft_treenode_insert_child_before_first in testing\n");
	ft_treenode_insert_child_before_first_test();
	FT_PRINTF("tree: ft_treenode_cut in testing\n");
	ft_treenode_cut_test();
	return (0);
}
