/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environ_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:20:33 by taretiuk          #+#    #+#             */
/*   Updated: 2024/08/09 14:25:11 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_envvar // 4. contens of each double-linked list node
{
	char	*key;
	char	*value;
}	t_envvar;

typedef struct s_dlist
{
	struct s_dlist 	*next;
	struct s_dlist	*prev;
	t_envvar 		*content;
} t_dlist;

typedef struct s_ssmap
{
	t_dlist	*head;
	t_dlist *tail; // 3. double-linked list head - for the envvars associative array
	int		size;
}	t_ssmap;

typedef struct s_params // 1. "global" parameter structure
{
	t_ssmap		envvars; // 2. "map" (associative array) of environment variables
}	t_params;

void print_environ_list(t_params *params)
{
    t_dlist *current = params->envvars.head;
    while (current != NULL)
    {
        printf("key: %s, value: %s\n", current->content->key, current->content->value);
        current = current->next;
    }
}

void	create_environ_list(t_params *params, t_dlist *node)
{
	t_dlist	*current;
	t_dlist	*tail;

	current = params->envvars.head;
	tail = params->envvars.tail;

	// Case 1: The list is empty
	if (current == NULL)
	{
		//printf("Case 1: The list is empty\n");
		params->envvars.head = node;
		params->envvars.tail = node;
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	// Case 2: Insert at the beginning (before the current head)
	if (strcmp((node->content)->key, (current->content)->key) < 0)
	{
		//printf("Case 2: Insert at the the beginning\n");
		node->next = current;
		node->prev = NULL;
		current->prev = node;
		params->envvars.head = node;
		//printf("Node Case 2: %s %s\n", node->content->key, node->content->value);
		return ;
		//params->envvars.head = node;
	}
	//Case 3: Insert at the end
	if (strcmp((node->content)->key, (tail->content)->key) > 0)
	{
		//printf("Case 3: Insert at the end\n");
        node->next = NULL;
        node->prev = tail;
        tail->next = node;
        params->envvars.tail = node;
		return ;
       //params->envvars.size++;
    }
	//Case 4: Insert in between
	while (current != NULL)
    {
        // Case 4.1: Overwrite if key already exists
        if (strcmp((node->content)->key, (current->content)->key) == 0)
        {
			//printf("Case 4.1\n");
            free((current->content)->value); // Assuming value was dynamically allocated
            (current->content)->value = (node->content)->value;
            free((node->content)->key); // Free the old key if necessary
            free(node->content); // Free the new entry structure
            free(node); // Free the new node
            return;
        }
        // Case 4.2: Insert before the current node
        else if (strcmp((node->content)->key, (current->content)->key) < 0)
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
				//printf("Case 4.3\n");
                // Inserting at the beginning
                params->envvars.head = node;
            }
            current->prev = node;
            return;
        }
        current = current->next;
    }
	// Safeguard
	// node->next = NULL;
    // node->prev = tail;
    // tail->next = node;
    // params->envvars.tail = node;
    //params->envvars.size++;
}

t_dlist *make_node(t_params *params, const char *key, const char *value)
{
    t_dlist *node;
    t_envvar *entry;

    node = malloc(sizeof(t_dlist));
    if (!node)
        return (NULL);

    entry = malloc(sizeof(t_envvar));
    if (!entry)
    {
        free(node);
        return (NULL);
    }

    entry->key = strdup(key); // Assuming strdup allocates memory for the string
    entry->value = strdup(value); // Same for value
    if (!entry->key || !entry->value)
    {
        free(entry->key);
        free(entry->value);
        free(entry);
        free(node);
        return (NULL);
    }

    node->content = entry;
    node->next = NULL;
    node->prev = NULL;

    return (node);
}

int main()
{
	t_dlist		*node;
	t_params	*params = malloc(sizeof(t_params));
	 // Define arrays of keys and values
    const char *keys[] = {"PATH", "SHELL", "HOME", "USERNAME"};
    const char *values[] = {"/usr/local/sbin", "/bin/bash", "/home/user"};
    int num_entries = sizeof(keys) / sizeof(keys[0]);

    // Loop through keys and values arrays
    for (int i = 0; i < num_entries; i++) 
	{
        node = make_node(params, keys[i], values[i]);
        if (node == NULL) 
		{
            printf("Error creating node for key: %s\n", keys[i]);
            return (1);
        }
       // printf("key: %s, value: %s\n", node->content->key, node->content->value);
        create_environ_list(params, node);
		print_environ_list(params);
		//printf("key: %s, value: %s\n", node->content->key, node->content->value);
    }
   printf("Environment list:\n");
   print_environ_list(params);
}
