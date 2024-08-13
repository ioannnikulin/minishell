/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:20:33 by taretiuk          #+#    #+#             */
/*   Updated: 2024/08/13 23:10:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"
#include <stdlib.h>

int	ft_mapss_insert(t_mapss *map, t_dlist *node)
{
	t_dlist			*current;
	t_dlist			*tail;
	t_mapss_entry	*cur_entry;
	t_mapss_entry	*node_entry;
	t_mapss_entry	*tail_entry;

	current = map->head;
	tail = map->tail;
	cur_entry = current->content;
	node_entry = node->content;
	tail_entry = tail->content;
	// Case 1: The list is empty
	if (current == NULL)
	{
		//printf("Case 1: The list is empty\n");
		map->head = node;
		map->tail = node;
		node->next = NULL;
		node->prev = NULL;
		return (0);
	}
	// Case 2: Insert at the beginning (before the current head)
	if (ft_strcmp(node_entry->key, cur_entry->key) < 0)
	{
		node->next = current;
		node->prev = NULL;
		current->prev = node;
		map->head = node;
		return (0);
	}
	//Case 3: Insert at the end
	if (ft_strcmp(node_entry->key, tail_entry->key) > 0)
	{
		//printf("Case 3: Insert at the end\n");
		node->next = NULL;
		node->prev = tail;
		tail->next = node;
		map->tail = node;
		return (0);
		//params->envvars.size++;
	}
	//Case 4: Insert in between
	while (current != NULL)
    {
		// Case 4.1: Overwrite if key already exists
		if (ft_strcmp(node_entry->key, cur_entry->key) == 0)
		{
			//printf("Case 4.1\n");
			free(cur_entry->value); // Assuming value was dynamically allocated
			cur_entry->value = node_entry->value;
			free(node_entry->key); // Free the old key if necessary
			free(node->content); // Free the new entry structure
			free(node); // Free the new node
			return (0);
		}
		// Case 4.2: Insert before the current node
		else if (ft_strcmp(node_entry->key, cur_entry->key) < 0)
		{
			//printf("Case 4.2\n");
			node->next = current;
			node->prev = current->prev;
			if (current->prev != NULL)
			{
				current->prev->next = node;
			}
			else
			{
				// Inserting at the beginning
				map->head = node;
			}
			current->prev = node;
			return (0);
		}
		current = current->next;
		cur_entry = current->content;
	}
	return (0);
}
