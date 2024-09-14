/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:27:04 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/12 19:32:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tree_test.h"

int	tree_test(void)
{
	printf("tree: ft_treenode_insert_child_idx in testing\n");
	ft_treenode_insert_child_idx_test();
	printf("tree: ft_treenode_insert_child_before_first in testing\n");
	ft_treenode_insert_child_before_first_test();
	return (0);
}
