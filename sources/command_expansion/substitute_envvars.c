/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_envvars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:01:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/28 17:29:38 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander_internal.h"

/*extract alphanum/underscore string after $*/
static char	*grab_name(char *content, int start)
{
	char	*res;
	int		len;
	char	c;

	len = 0;
	c = content[start + len];
	while (c
		&& ((len == 0 && c == '$')
			|| (len == 1 && c == '?')
			|| ft_isalnum(c) || c == '_')
	)
	{
		len ++;
		if (len == 2 && c == '?')
			break ;
		c = content[start + len];
	}
	res = ft_substr(content, start + 1, len - 1);
	return (res);
}

static char	*get_value(char *key, t_param *param)
{
	char	*value;

	if (ft_strcmp(key, "PATH") == 0)
	{
		if (collect_path(param->envvar_path_head, &value))
			return (0);
	}
	else if (ft_strcmp(key, "?") == 0)
		return (ft_lltoa_strdup(param->opts.retval));
	else
	{
		value = ft_mapss_get(param->envvars, key);
		if (value)
			value = ft_strdup(value);
	}
	if (!value)
		value = ft_empty_string();
	return (value);
}

static int	ret(char *s1, char *s2, int *errno, int retval)
{
	free(s1);
	free(s2);
	ft_assign_i(errno, retval, 0);
	return (retval);
}

static int	not_an_envvar(t_crawler *c, char *key)
{
	free(key);
	if (ft_sbuf_append(c->sbuf, "$") == 0)
		return (ft_assign_i(&c->errno, 5, 5));
	c->i ++;
	return (0);
}

/*extracts the variable name
handle cases when key is empty
if key is inside single quotes it appends the key name without extension
else - extract the value corresponding to the key
move index of command line to process the rest of it*/
int	expand_envvar(t_crawler *c)
{
	char	*key;
	char	*value;

	key = grab_name(c->src, c->i);
	if (!key)
		return (ret(0, 0, &c->errno, 1));
	if (!*key)
		return (not_an_envvar(c, key));
	if (c->squote != -1)
	{
		value = 0;
		if (ft_sbuf_append(ft_sbuf_append(c->sbuf, "$"), key) == 0)
			return (ret(key, 0, &c->errno, 2));
	}
	else
	{
		value = get_value(key, c->param);
		if (!value)
			return (ret(key, value, &c->errno, 3));
		if (ft_sbuf_append(c->sbuf, value) == 0)
			return (ret(key, value, &c->errno, 4));
	}
	c->i += ft_strlen(key) + 1;
	return (ret(key, value, 0, 0));
}
