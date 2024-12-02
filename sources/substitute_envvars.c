/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_envvars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:01:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 12:29:50 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	skip_single_quote_block(char *content, int *from)
{
	(*from) ++;
	while (content[*from] && content[*from] != '\'')
		(*from) ++;
	if (!content[*from])
	{
		*from = -1;
		ft_printf("%s: %s\n", TXT_MINISHELL, ERR_UNTERMINATED_SINGLE_QUOTE);
	}
	else
		(*from) ++;
	return (1);
}

static char	*grab_name(char *content, int start)
{
	char	*res;
	int		len;
	char	c;

	len = 0;
	c = content[start + len];
	while (c && ((len == 0 && c == '$') || ft_isalnum(c) || c == '_'))
	{
		len ++;
		c = content[start + len];
	}
	res = ft_substr(content, start + 1, len - 1);
	return (res);
}

static char	*next_var(char *content, int *start)
{
	char	*res;
	int		from;

	from = -1;
	res = 0;
	while (content[++ from])
	{
		if (content[from] == '\'' && skip_single_quote_block(content, &from)
			&& from == -1)
			return (0);
		if (content[from] == '$' && content[from + 1]
			&& (ft_isalnum(content[from + 1]) || content[from + 1] == '_'))
		{
			res = grab_name(content, from);
			*start = from;
			return (res);
		}
	}
	return (0);
}

static char	*get_value(char *key, t_param *param)
{
	char	*value;

	if (ft_strcmp(key, "PATH") == 0)
	{
		if (collect_path(param->envvar_path_head, &value))
			return (0);
	}
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

int	substitute_envvars(t_treenode *node, t_param *param)
{
	char	*key;
	int		start;
	char	*content;
	char	*value;

	while (1)
	{
		key = next_var(node->content, &start);
		if (!key)
			break ;
		content = node->content;
		value = get_value(key, param);
		ft_replace_idx(&content, start, ft_strlen(key) + start + 1, value);
		if (!content)
			return (ft_printf("%s: %s\n", TXT_MINISHELL, ERR_MALLOC) + 1);
		node->content = content;
	}
	node = node->child;
	while (node)
	{
		if (substitute_envvars(node, param))
			return (1);
		node = node->sibling_next;
	}
	return (0);
}
