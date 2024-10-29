/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:30 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/23 20:25:17 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	invalid(char *src)
{
	printf("export: %s: %s\n", src, ERR_EXPORT_INVALID);
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

static int	err_malloc(char *key)
{
	printf("export: %s\n", ERR_MALLOC);
	free(key);
	return (2);
}

// returns 0 on success 1 on error
// check on empty string (aaa=) and multiple = signs in a row and separate
// check nonalphanum
// check path
static int	one(char *src, t_mapss *map, t_dlist **path_head)
{
	char	*key;
	char	*val;
	int		i;

	i = 0;
	if (src[0] == '=')
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
		return (err_malloc(key));
	if (ft_strcmp(key, "PATH") == 0)
		return (path(key, val, path_head));
	return (ft_mapss_add(map, key, val));
}

// return value is ignored
int	option_export(t_control control, t_treenode *node, t_param *param)
{
	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	node = node->child;
	while (node && !one(node->content, &param->envvars,
			&param->envvar_path_head))
		node = node->sibling_next;
	*control.retval = ft_if_i(node == 0, 0, 1);
	return (1);
}
