/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:20:33 by taretiuk          #+#    #+#             */
/*   Updated: 2024/08/17 19:09:56 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"
#include <stdlib.h>

/*
else if (ft_strcmp(node_entry->key, cur_entry->key) < 0)
		{
			node->next = cur;
			node->prev = cur->prev;
			if (cur->prev != NULL)
			{
				cur->prev->next = node;
			}
			else
			{
				// Inserting at the beginning
				map->head = node;
			}
			cur->prev = node;
			map->size ++;
			return (0);
		}
*/

static insert_at_the_end(t_mapss *map, t_dlist *node, t_dlist *cur,  t_dlist *tail)
{
	t_mapss_entry	*node_entry;
	t_mapss_entry	*tail_entry;

	node_entry = node->content;
	tail_entry = tail->content;
	if (ft_strcmp(node_entry->key, tail_entry->key) > 0)
	{
		node->next = NULL;
		node->prev = tail;
		tail->next = node;
		map->tail = node;
		map->size ++;
		return (0);
	}
	return (1);
}

static	insert_at_the_beginning(t_mapss *map, t_dlist *node, t_dlist *cur)
{
	t_mapss_entry	*cur_entry;
	t_mapss_entry	*node_entry;

	cur_entry = cur->content;
	node_entry = node->content;
	if (ft_strcmp(node_entry->key, cur_entry->key) < 0)
	{
		node->next = cur;
		node->prev = NULL;
		cur->prev = node;
		map->head = node;
		map->size ++;
		return (0);
	}
	return (1);
}

static	insert_int_between(t_mapss *map, t_dlist *node, t_dlist *cur, t_dlist *tail)
{
	t_mapss_entry	*cur_entry;
	t_mapss_entry	*node_entry;
	t_mapss_entry	*tail_entry;

	cur_entry = cur->content;
	node_entry = node->content;
	tail_entry = tail->content;
	while (cur != NULL)
	{
		if (ft_strcmp(node_entry->key, cur_entry->key) == 0)
		{
			free(cur_entry->value); // Assuming value was dynamically allocated
			cur_entry->value = node_entry->value;
			free(node_entry->key); // Free the old key if necessary
			free(node->content); // Free the new entry structure
			free(node); // Free the new node
			return (0);
		}
		else if (ft_strcmp(node_entry->key, cur_entry->key) < 0)
		{
			node->next = cur;
			node->prev = cur->prev;
			cur->prev->next = node;
			cur->prev = node;
			map->size ++;
			return (0);
		}
		cur = cur->next;
		cur_entry = cur->content;
	}
}

static	list_is_empty(t_mapss *map, t_dlist *node, t_dlist *cur, t_dlist *tail)
{
	if (cur == NULL)
	{
		map->head = node;
		map->tail = node;
		node->next = NULL;
		node->prev = NULL;
		map->size ++;
		return (0);
	}
	return (1);
}

int	ft_mapss_insert(t_mapss *map, t_dlist *node)
{
	t_dlist			*current;
	t_dlist			*tail;

	current = map->head;
	tail = map->tail;
	if(!list_is_empty(map, node, current, tail))
	{
		return (0);
	}
	if(!insert_at_the_beginning(map, node, current))
	{
		return (0);
	}
	if(!insert_at_the_end(map, node, current, tail))
	{
		return (0);
	}
	insert_in_between(map, node, current, tail);
	return (0);
}
