/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars_for_execve.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:38:22 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 20:22:10 by inikulin         ###   ########.fr       */
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

int	collect_path_with_header(t_dlist *head, char **where)
{
	int		res;
	char	*noheader;

	res = collect_path(head, &noheader);
	if (res)
		return (res);
	*where = ft_strjoin("PATH=", noheader);
	free(noheader);
	if (!*where)
		return (3);
	return (0);
}

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
	*where = res;
	return (0);
}

char	**get_envvars_for_execve(t_param *param)
{
	char	**res;
	int		sz;

	sz = param->envvars->size + 1 + (param->envvar_path_head != 0);
	res = ft_calloc_if(sizeof(char *) * sz, 1);
	if (!res)
	{
		ft_assign_i(&param->opts.errno, 1, 0);
		return (0);
	}
	if (collect_map(param->envvars, res))
	{
		ft_assign_i(&param->opts.errno, 2, 0);
		return (0);
	}
	res[sz - 1] = 0;
	if (!param->envvar_path_head)
		return (res);
	if (collect_path_with_header(param->envvar_path_head, &res[sz - 2]))
	{
		free_upto(res, sz - 2, 0);
		ft_assign_i(&param->opts.errno, 3, 0);
		return (0);
	}
	return (res);
}
