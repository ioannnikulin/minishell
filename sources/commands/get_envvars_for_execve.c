/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars_for_execve.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:38:22 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/25 01:11:45 by inikulin         ###   ########.fr       */
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
		text = ft_strjoin_multi_free_outer(
				ft_s2(entry->key, entry->value), 2, "=");
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
	char	*res;

	sz = ft_dlist_size(head) - 1;
	subs = ft_calloc_if(sizeof(char *) * sz, 1);
	if (!subs)
		return (1);
	i = 0;
	head = head->next;
	while (head)
	{
		subs[i ++] = head->content;
		head = head->next;
	}
	res = ft_strjoin_multi_free_outer(subs, sz, ":");
	if (!res)
		return (2);
	*where = ft_strjoin("PATH=", res);
	free(res);
	if (!*where)
		return (3);
	return (0);
}

char	**get_envvars_for_execve(t_param *param)
{
	char	**res;
	int		sz;

	sz = param->envvars.size + 1 + (param->envvar_path_head != 0);
	res = ft_calloc_if(sizeof(char *) * sz, 1);
	if (!res)
	{
		ft_assign_i(&param->errno, 1, 0);
		return (0);
	}
	if (collect_map(&param->envvars, res))
	{
		ft_assign_i(&param->errno, 2, 0);
		return (0);
	}
	res[sz - 1] = 0;
	if (!param->envvar_path_head)
		return (res);
	if (collect_path(param->envvar_path_head->next, &res[sz - 2]))
	{
		free_upto(res, sz - 2, 0);
		ft_assign_i(&param->errno, 3, 0);
		return (0);
	}
	return (res);
}
