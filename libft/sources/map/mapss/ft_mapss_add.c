/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/26 22:41:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mapss.h"
#include "mapss_internal.h"

static t_dlist	*null(t_dlist *node, t_mapss_entry *entry, char *key)
{
	free(key);
	free(entry);
	free(node);
	return (0);
}

/* not sure whether it should be static
 * nullptr as result - allocation error
*/
static t_dlist	*ft_mapss_node(const char *key, const char *value)
{
	t_dlist			*node;
	t_mapss_entry	*entry;

	node = ft_calloc_if(sizeof(t_dlist), 1);
	if (!node)
		return (0);
	node->next = 0;
	node->prev = 0;
	entry = ft_calloc_if(sizeof(t_mapss_entry), 1);
	if (!entry)
		return (null(node, 0, 0));
	node->content = entry;
	entry->key = ft_strdup(key);
	if (!entry->key)
		return (null(node, entry, 0));
	entry->value = ft_strdup(value);
	if (!entry->value)
		return (null(node, entry, entry->key));
	return (node);
}

int	ft_mapss_add(t_mapss *map, const char *key, const char *value)
{
	t_dlist	*node;

	node = ft_mapss_node(key, value);
	if (!node)
		return (1);
	ft_mapss_insert(map, node);
	return (0);
}
