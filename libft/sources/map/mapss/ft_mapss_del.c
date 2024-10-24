/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/23 18:13:49 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss.h"
#include "mapss_internal.h"

void	ft_mapss_node_del(t_dlist *node)
{
	free(((t_mapss_entry *)node->content)->key);
	free(((t_mapss_entry *)node->content)->value);
	free((t_mapss_entry *)node->content);
	free(node);
}

int	ft_mapss_del(t_mapss *map, const char *key)
{
	t_dlist	*cur_node;
	char	*cur_key;

	cur_node = map->head;
	while (cur_node)
	{
		cur_key = ((t_mapss_entry *)cur_node->content)->key;
		if (ft_strcmp(key, cur_key) == 0)
		{
			if (cur_node == map->head)
				map->head = cur_node->next;
			else
				cur_node->prev->next = cur_node->next;
			if (cur_node->next)
				cur_node->next->prev = cur_node->prev;
			ft_mapss_node_del(cur_node);
			return (0);
		}
		cur_node = cur_node->next;
	}
	return (1);
}
