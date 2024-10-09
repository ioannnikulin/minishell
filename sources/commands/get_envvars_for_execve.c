/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars_for_execve.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:38:22 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/10 01:49:17 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	free_upto(char **res, int upto, int retval)
{
	int	i;

	i = -1;
	while (++i < upto)
		free(res[i]);
	free(res);
	return (retval);
}

static int	collect_map(t_mapss *map, char **res)
{
	char			*text;
	t_dlist			*node;
	t_mapss_entry	*entry;
	int				i;

	node = map->head;
	i = 0;
	while (node)
	{
		entry = node->content;
		text = ft_strjoin_multi_free(ft_s2(entry->key, entry->value), 2, "=");
		if (!text)
			return (free_upto(res, i, 1));
		res[i ++] = text;
		node = node->next;
	}
	return (0);
}

/* also will be used for path printout */
int	collect_path(t_dlist *head, char **where)
{
	char	**subs;
	int		i;
	int		sz;

	i = 0;
	sz = ft_dlist_size(head);
	subs = ft_calloc_if(sizeof(char *) * sz, 1);
	if (!subs)
		return (1);
	while (head)
	{
		subs[i ++] = head->content;
		head = head->next;
	}
	*where = ft_strjoin_multi_free(subs, sz, ":");
	if (!*where)
		return (2);
	return (0);
}

char	**get_envvars_for_execve(t_param *param)
{
	char	**res;
	int		sz;

	sz = ft_dlist_size(param->envvar_path_head) + param->envvars.size + 1;
	res = ft_calloc_if(sizeof(char *) * sz, 1);
	if (!res)
		return (0);
	if (collect_map(&param->envvars, res))
		return (0);
	if (collect_path(param->envvar_path_head, &res[sz - 2]))
	{
		free_upto(res, sz - 2, 0);
		return (0);
	}
	res[sz - 1] = 0;
	return (res);
}
