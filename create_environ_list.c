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
		params->envvars.head = node;
		params->envvars.tail = node;
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	// Case 2: Insert at the beginning (before the current head)
	else if (strcmp((node->content)->key, (current->content)->key) < 0)
	{
		node->next = current;
		node->prev = NULL;
		current->prev = node;
		return ;
		//params->envvars.head = node;
	}
	//Case 3: Insert at the end
	else if (strcmp((node->content)->key, (tail->content)->key) > 0)
	{
        node->next = NULL;
        node->prev = tail;
        tail->next = node;
        params->envvars.tail = node;
		return ;
       //params->envvars.size++;
    }
	//Case 4: Insert in between
	else
		while (current != NULL)
		{
			//Case 4.1: Overwrite if key already exists
			if (strcmp((node->content)->key, (current->content)->key) == 0)
			{
				free((current->content)->value); // Assuming value was dynamically allocated
				(current->content)->value = (node->content)->value;
				free((node->content)->key); // Free the old key if necessary
				free(node->content); // Free the new entry structure
				free(node); // Free the new node
				return ;
			}
			//Case 4.2: Insert before 
			else if (strcmp((node->content)->key, (current->content)->key) < 0)
			{
				node->next = current->next;
            	node->prev = current;
            	current->next->prev = node;
            	current->next = node;
            	//params->envvars.size++;
				return ;
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

t_dlist *make_node(t_params *params, char *key, char *value)
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
	t_dlist	*node;
	t_params	params = {0};
	char	*key;
	char	*value;

	key = "PATH";
	value = "/usr/local/sbin";
	node = make_node(&params, key, value);
	if (node == NULL)
    {
        printf("Error creating node\n");
        return (1);
    }
	printf("key: %s, value: %s\n", node->content->key, node->content->value);
	create_environ_list(&params, node);
	printf("Environment list:\n");
    print_environ_list(&params);
}
