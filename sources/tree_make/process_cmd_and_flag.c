/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd_and_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:57:16 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/02 19:58:34 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing_internal.h"

int	cmd_low_level(char *token, t_treenode **cur_1,
			t_treenode **cur_2, int *num)
{
	if (ft_treenode_insert_child_idx_s_dup(*cur_1, token,
			(*cur_1)->children_qtty) == -1)
	{
		return (1);
	}
	*cur_2 = (*cur_1)->child;
	*num = 0;
	return (0);
}

int	cmd_top_level(char *token, t_treenode **cur_1,
			t_treenode **cur_2, int *num)
{
	if (ft_treenode_insert_child_idx_s_dup(*cur_1, token,
			(*cur_1)->children_qtty) == -1)
	{
		return (1);
	}
	while ((*cur_2)->sibling_next)
		*cur_2 = (*cur_2)->sibling_next;
	*num = 0;
	return (0);
}

int	process_cmd_and_flag(char *token, t_treenode **cur_1,
			t_treenode **cur_2, int *num)
{
	if ((ft_strcmp((*cur_1)->content, "(") == 0) && *num == 2)
	{
		if (cmd_low_level(token, cur_1, cur_2, num) != 0)
			return (1);
		return (0);
	}
	else if ((*cur_2)->parent == *cur_1 && *num == 1)
	{
		if (cmd_top_level(token, cur_1, cur_2, num) != 0)
			return (1);
		return (0);
	}
	else
	{
		if (ft_treenode_insert_child_idx_s_dup(*cur_2, token,
				(*cur_2)->children_qtty) == -1)
		{
			return (1);
		}
	}
	return (0);
}
