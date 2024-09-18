/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:20:33 by taretiuk          #+#    #+#             */
/*   Updated: 2024/09/16 12:54:19 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"
#include <stdlib.h>

static int	insert_in_between(t_mapss *map, t_dlist *node, t_mapss_entry *node_entry)
{
    t_dlist *cur = map->head;
    t_mapss_entry *cur_entry;

    // Traverse the list from the head
    while (cur != NULL)
    {
        cur_entry = cur->content;
        // If the keys are the same, update the current node's value
        if (ft_strcmp(node_entry->key, cur_entry->key) == 0)
        {
            free(cur_entry->value);  // Free old value
            cur_entry->value = node_entry->value;  // Update with new value
            free(node_entry->key);  // Free the key of the new node
            free(node->content);  // Free the structure of the new node
            free(node);  // Free the new node itself
            return (0);
        }
        // If the new node's key is less than the current node's key, insert before the current node
        if (ft_strcmp(node_entry->key, cur_entry->key) < 0)
        {
            node->next = cur;
            node->prev = cur->prev;
            if (cur->prev != NULL)
            {
                cur->prev->next = node;
            }
            else
            {
                // Inserting at the beginning, so update the head
                map->head = node;
            }
            cur->prev = node;
            map->size++;
            return (0);
        }
        // Move to the next node
        cur = cur->next;
    }
    // If we reach the end of the list, insert the new node at the tail
    node->next = NULL;
    node->prev = map->tail;
    map->tail->next = node;
    map->tail = node;
    map->size++;
    return (0);
}

static int insert_new_head(t_mapss *map, t_dlist *node)
{
    // If the list is empty, make the new node both head and tail
    if (map->head == NULL)
    {
        map->head = node;
        map->tail = node;
        node->next = NULL;
        node->prev = NULL;
        map->size++;
        return (0);
    }
    return (1);  // If the list isn't empty, return an error code
}

int	ft_mapss_insert(t_mapss *map, t_dlist *node)
{
    t_mapss_entry *node_entry;
	
	node_entry = node->content;
    // If the list is empty, insert the new node as the head
    if (insert_new_head(map, node) == 0)
    {
        return 0;
    }
    // If the list isn't empty, try to insert the node in the correct position
    if (insert_in_between(map, node, node_entry) == 0)
	{
		return (0);
	}
	return (1);
}