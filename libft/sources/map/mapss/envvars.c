/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 19:21:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	*null(int ignore)
{
	(void)ignore;
	return (0);
}

t_dlist	*ft_mapss_node(char *key, char *value, int *errno)
{
	t_dlist			*node;
	t_mapss_entry	*entry;

	assign(errno, 0, 0);
	node = malloc(sizeof(t_dlist));
	if (!node)
		return (null(assign(errno, 1, 0)));
	node->next = 0;
	node->prev = 0;
	entry = malloc(sizeof(t_mapss_entry));
	if (!entry)
		return (null(assign(errno, 2, 0)));
	node->content = entry;
	entry->key = ft_strdup(key);
	if (!entry->key)
		return (null(assign(errno, 3, 0)));
	entry->value = ft_strdup(value);
	if (!entry->value)
		return (null(assign(errno, 4, 0)));
	return (node);
}

static void	err_option(int choice, int *whereint, int whatint, char **wherechar, char *whatchar)
{
	if (choice)
	{
		assign(whereint, whatint, 0);
		if (wherechar && *wherechar && whatchar)
			*wherechar = whatchar;
		return (retchar);
	}
	return (MAPSS_NOERR);
}

char	*ft_mapss_error_decoder(int errno, int *finalize_mode)
{
	char	*res;

	res = 0;
	err_option(errno == 1, finalize_mode, 0, &res, "Couldn't allocate memory for a node\n");
	err_option(errno == 2, finalize_mode, FREE_ENVVARS_DLISTS, &res, "Couldn't allocate memory for an entry\n");
	err_option(errno == 3, finalize_mode, FREE_ENVVARS_DLISTS | FREE_ENVVARS_ENTRIES, &res, "Couldn't allocate memory for a key\n");
	err_option(errno == 4, finalize_mode, FREE_ENVVARS_DLISTS | FREE_ENVVARS_ENTRIES | FREE_ENVVARS_KEYS, &res, "Couldn't allocate memory for a value\n");
	return (res);
}

int	ft_mapss_add(t_mapss *map, char *key, char *value)
{
	t_dlist	*node;
	int		errno;
	int		finalize_mode;
	char	*error_msg;


	node = ft_mapss_node(key, value, &errno);
	if (!node)
	{
		error_msg = ft_mapss_error_decoder(errno, &finalize_mode);
		return (ft_mapss_finalize(map, finalize_mode, error_msg, -1));	
	}
	if (ft_mapss_insert(map, node))
		return (ft_mapss_finalize(map, MAPSS_FULL, "Couldn't insert node\n", 1));
	map->size ++;
	return (0);
}
