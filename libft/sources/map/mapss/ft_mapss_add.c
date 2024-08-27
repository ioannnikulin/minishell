/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/14 22:00:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mapss.h"
#include "mapss_internal.h"

static t_dlist	*null(int ignore)
{
	(void)ignore;
	return (0);
}

/* not sure whether it should be static */
static t_dlist	*ft_mapss_node(const char *key, const char *value, int *errno)
{
	t_dlist			*node;
	t_mapss_entry	*entry;

	assign(errno, 0, 0);
	node = ft_calloc_if(sizeof(t_dlist), 1);
	if (!node)
		return (null(assign(errno, 1, 0)));
	node->next = 0;
	node->prev = 0;
	entry = ft_calloc_if(sizeof(t_mapss_entry), 1);
	if (!entry)
		return (null(assign(errno, 2, 0)));
	node->content = entry;
	entry->key = ft_strdup(key);
	if (!entry->key)
		return (null(assign(errno, 3, 0)));
	entry->value = ft_strdup(value);
	if (!entry->value)
		return (null(assign(errno, 4, 0)));
	return (node);
}

int	ft_mapss_add(t_mapss *map, const char *key, const char *value)
{
	t_dlist	*node;
	int		errno;
	int		finalize_mode;
	char	*error_msg;


	node = ft_mapss_node(key, value, &errno);
	if (!node)
	{
		error_msg = ft_mapss_error_decoder(errno, &finalize_mode);
		return (ft_mapss_finalize(map, finalize_mode, error_msg, -1));	// this is all wrong. node constructor should free its memory, and the finalize mode should be the same always
	}
	if (ft_mapss_insert(map, node))
		return (ft_mapss_finalize(map, MAPSS_FULL, "Couldn't insert node\n", 1));
	return (0);
}
