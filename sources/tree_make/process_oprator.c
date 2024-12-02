/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_oprator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:47:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/02 19:58:55 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing_internal.h"

int	process_operator(char *token, t_treenode **cur_1, int *num)
{
	if (ft_treenode_insert_child_idx_s_dup(*cur_1, token,
			(*cur_1)->children_qtty) == -1)
		return (1);
	*num = 1;
	return (0);
}
