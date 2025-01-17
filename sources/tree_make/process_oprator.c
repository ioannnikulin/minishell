/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_oprator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:47:18 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/15 20:23:19 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing_internal.h"

int	process_operator(char *token, t_treenode **cur_1, int *num)
{
	if (treenode_insert_dup(*cur_1, token, (*cur_1)->children_qtty) == -1)
		return (1);
	*num = 1;
	return (0);
}
