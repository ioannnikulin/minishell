/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_parentheses.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:43:41 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/02 19:43:55 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing_internal.h"

int	process_open_parentheses(char *token, t_treenode **cur_1,
			t_treenode **cur_2, int *num)
{
	t_treenode	*tmp;

	tmp = NULL;
	if (treenode_insert_dup(*cur_1, token, (*cur_1)->children_qtty) == -1)
		return (1);
	tmp = *cur_2;
	while (tmp && tmp->sibling_next)
		tmp = tmp->sibling_next;
	if (tmp)
		*cur_1 = tmp;
	*num = 2;
	return (0);
}

int	process_closing_parentheses(t_treenode **cur_1, t_treenode **cur_2,
			int *num)
{
	if (!cur_1 || !*cur_1)
		return (1);
	*cur_2 = *cur_1;
	*cur_1 = (*cur_1)->parent;
	*num = 0;
	return (0);
}
