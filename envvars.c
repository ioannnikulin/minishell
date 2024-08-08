/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/08 13:43:57 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

// creates a new node for a doubly linked list (t_dlist) that will store environment variables
t_dlist	*make_node(t_params *params, char *key, char *value)
{
	t_dlist		*node;
	t_envvar	*entry;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return ((t_dlist*) finalize(0, 0, "Error allocating memory for envvar double-linked list node\n", 0));
	//to set node as the head of the linked list
	params->envvars->head = node;
	node->next = 0;
	node->prev = 0;
	entry = malloc(sizeof(t_envvar));
	if (!entry)
		return ((t_dlist*) finalize(params, FREE_ENVVARS_DLISTS, "Error allocating memory for envvar entry\n", 0));
	node->content = entry;
	entry->key = ft_strdup(key, &params->errno);
	if (params->errno)
		return ((t_dlist*) finalize(params, FREE_ENVVARS_DLISTS | FREE_ENVVARS_ENTRIES, "Error allocating memory for envvar entry key\n", 1));
	entry->value = ft_strdup(value, &params->errno);
	if (params->errno)
		return ((t_dlist*) finalize(params, FREE_ENVVARS_DLISTS | FREE_ENVVARS_ENTRIES | FREE_ENVVARS_KEYS, "Error allocating memory for envvar entry value\n", 0));
	return (node);
}

int	insert_envvar(t_params *params, char *key, char *value)
{
	t_dlist *node;

	node = make_node(params, key, value);
	// TODO: insert into params->envvars
	params->envvars.size ++;
	return (0);
}
