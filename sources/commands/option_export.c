/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:30 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 14:43:35 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	invalid(char *src)
{
	FT_FPRINTF(STDERR, "export: %s: %s\n", src, ERR_EXPORT_INVALID);
	return (1);
}

// returns 0 on success
static int	path(char *key, char *val, t_dlist **path_head)
{
	char	**vals;
	char	*v;
	int		sz;

	free(key);
	vals = ft_split(val, ':', &sz);
	free(val);
	if (!vals)
		return (1);
	v = *vals;
	ft_dlist_clear_s(path_head, 0);
	while (v)
	{
		if (!ft_dlist_add_back_s(path_head, v))
		{
			ft_free_ss_sz_null((void ***)&vals, sz);
			return (2);
		}
		v ++;
	}
	ft_free_ss_sz_null((void ***)&vals, sz);
	return (0);
}

static int	err_malloc(char *key, char *val, int *errno)
{
	FT_FPRINTF(STDERR, "export: %s\n", ERR_MALLOC);
	ft_assign_i(errno, 1, 0);
	free(key);
	free(val);
	return (2);
}

// returns 0 on success 1 on error
// check on empty string (aaa=) and multiple = signs in a row and separate
// check nonalphanum
// check path
static int	one(char *src, t_mapss *map, t_dlist **path_head, int *errno)
{
	char	*key;
	char	*val;
	int		i;

	i = 0;
	if (!ft_isalpha(src[0]) && src[0] != '_')
		return (invalid(src));
	while (src[i] && src[i] != '=')
	{
		if (!ft_isalnum(src[i]) && src[i] != '_')
			return (invalid(src));
		i ++;
	}
	if (src[i] == 0)
		return (0);
	key = ft_substr(src, 0, i);
	val = ft_substr(src, i + 1, ft_strlen(src) - i - 1);
	if (!key || !val)
		return (err_malloc(key, val, errno));
	if (ft_strcmp(key, "PATH") == 0)
		return (path(key, val, path_head));
	i = ft_mapss_add(map, key, val);
	free(key);
	free(val);
	return (i);
}

// return value is ignored
int	option_export(t_executor *control, t_treenode *node, t_param *param)
{
	control->found = 1;
	node = node->child;
	while (node && !one(*get_node_txt(node), param->envvars,
			&param->envvar_path_head, &param->opts.errno)
	)
		node = node->sibling_next;
	control->retval = ft_if_i(node == 0, 0, 1);
	return (1);
}
