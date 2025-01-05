/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_finalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:12:55 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/27 00:34:13 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss.h"

int	ft_mapss_finalize_i(t_mapss *map, char *msg, int retval)
{
	t_dlist			*node;
	t_dlist			*prev;
	t_mapss_entry	*entry;

	if (map)
	{
		node = map->head;
		while (node)
		{
			entry = node->content;
			ft_free_s_null((void **)&entry->key);
			ft_free_s_null((void **)&entry->value);
			free(entry);
			prev = node;
			node = node->next;
			free(prev);
		}
		free(map);
	}
	if (msg)
		FT_PRINTF("%s\n", msg);
	return (retval);
}

t_mapss	*ft_mapss_finalize_nullptr(t_mapss *map, char *msg)
{
	ft_mapss_finalize_i(map, msg, 0);
	return (0);
}
