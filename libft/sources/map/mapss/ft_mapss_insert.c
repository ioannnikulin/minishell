/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:20:33 by taretiuk          #+#    #+#             */
/*   Updated: 2024/09/20 12:53:14 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"
#include <stdlib.h>

static int	insert_before_node(t_mapss *map, t_dlist *cur, t_dlist *node)
{
	node->next = cur;
	node->prev = cur->prev;
	if (cur->prev != NULL)
	{
		cur->prev->next = node;
	}
	else
	{
		map->head = node;
	}
	cur->prev = node;
	map->size++;
	return (0);
}

static int	update_node_value(t_dlist *node, t_mapss_entry *cur_entry,
								t_mapss_entry *node_entry)
{
	if (node_entry != NULL && cur_entry != NULL)
	{
		free(node_entry->key);
		free(node_entry->value);
		node_entry->key = ft_strdup(cur_entry->key);
		node_entry->value = ft_strdup(cur_entry->value);
	}
	free(cur_entry->value);
	cur_entry->value = node_entry->value;
	free(node_entry->key);
	free(node->content);
	free(node);
	return (0);
}

static int	insert_in_between(t_mapss *map, t_dlist *node,
					t_mapss_entry *node_entry)
{
	t_dlist			*cur;
	t_mapss_entry	*cur_entry;

	cur = map->head;
	while (cur != NULL)
	{
		cur_entry = cur->content;
		if (ft_strcmp(node_entry->key, cur_entry->key) == 0)
		{
			update_node_value(node, cur_entry, node_entry);
			return (0);
		}
		if (ft_strcmp(node_entry->key, cur_entry->key) < 0)
		{
			insert_before_node(map, cur, node);
			return (0);
		}
		cur = cur->next;
	}
	node->next = NULL;
	node->prev = map->tail;
	map->tail->next = node;
	map->tail = node;
	map->size++;
	return (0);
}

static int	insert_new_head(t_mapss *map, t_dlist *node)
{
	if (map->head == NULL)
	{
		map->head = node;
		map->tail = node;
		node->next = NULL;
		node->prev = NULL;
		map->size++;
		return (0);
	}
	return (1);
}

int	ft_mapss_insert(t_mapss *map, t_dlist *node)
{
	t_mapss_entry	*node_entry;

	node_entry = node->content;
	if (insert_new_head(map, node) == 0)
	{
		return (0);
	}
	if (insert_in_between(map, node, node_entry) == 0)
	{
		return (0);
	}
	return (1);
}
