/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 16:16:31 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	*null(int ignore)
{
	(void)ignore;
	return (0);
}

t_dlist	*make_node(t_param *param, char *key, char *value)
{
	t_dlist		*node;
	t_envvar	*entry;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (null(finalize(0, 0, "Error allocating memory for envvar double-linked list node\n", 0)));
	param->envvars.head = node;
	node->next = 0;
	node->prev = 0;

	entry = malloc(sizeof(t_envvar));
	if (!entry)
		return (null(finalize(param, FREE_ENVVARS_DLISTS, "Error allocating memory for envvar entry\n", 0)));

	node->content = entry;

	entry->key = ft_strdup(key);
	if (!entry->key)
		return (null(finalize(param, FREE_ENVVARS_DLISTS | FREE_ENVVARS_ENTRIES, "Error allocating memory for envvar entry key\n", 0)));
	entry->value = ft_strdup(value);
	if (!entry->value)
		return (null(finalize(param, FREE_ENVVARS_DLISTS | FREE_ENVVARS_ENTRIES | FREE_ENVVARS_KEYS, "Error allocating memory for envvar entry value\n", 0)));
	return (node);
}

int	insert_envvar(t_param *param, char *key, char *value)
{
	t_dlist *node;

	node = make_node(param, key, value);
	// TODO: insert into param->envvars
	(void)node;
	param->envvars.size ++;
	return (0);
}
