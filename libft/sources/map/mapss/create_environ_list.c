/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environ_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:20:33 by taretiuk          #+#    #+#             */
/*   Updated: 2024/08/10 19:10:18 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_mapss_print(t_mapss *map)
{
	t_dlist *current = map->head;
	while (current != NULL)
	{
		ft_printf("key: %s, value: %s\n", current->content->key, current->content->value);
		current = current->next;
	}
}

int	ft_mapss_insert(t_mapss *map, t_dlist *node)
{
	t_dlist	*current;
	t_dlist	*tail;

	current = map->head;
	tail = map->tail;
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
	if (ft_strcmp((node->content)->key, (current->content)->key) < 0)
	{
		node->next = current;
		node->prev = NULL;
		current->prev = node;
		map->head = node;
		return (0);
	}
	//Case 3: Insert at the end
	if (ft_strcmp((node->content)->key, (tail->content)->key) > 0)
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
		if (ft_strcmp((node->content)->key, (current->content)->key) == 0)
		{
			//printf("Case 4.1\n");
			free((current->content)->value); // Assuming value was dynamically allocated
			(current->content)->value = (node->content)->value;
			free((node->content)->key); // Free the old key if necessary
			free(node->content); // Free the new entry structure
			free(node); // Free the new node
			return (0);
		}
		// Case 4.2: Insert before the current node
		else if (ft_strcmp((node->content)->key, (current->content)->key) < 0)
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
	}
	return (0);
}

int main()
{
	int		result;
	t_mapss	*map;

	 // Define arrays of keys and values
	const char *keys[] = {"PATH", "SHELL", "HOME", "USERNAME", "PATH", "SHLVL", "OLDPWD", "DISPLAY", ""};
	const char *values[] = {"/usr/local/sbin", "/bin/bash", "/home/user", "/usr/local/sbin", "1", "/home/taretiuk/42/student",
							":0", "X Window", "Error"};
	int num_entries = sizeof(keys) / sizeof(keys[0]);
	result = 0;

	// Loop through keys and values arrays
	for (int i = 0; i < num_entries; i++)
		ft_mapss_add(map, keys[i], values[i]);
	printf("Environment list:\n");
	ft_mapss_print(map);
}
