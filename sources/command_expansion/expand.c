/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:06:11 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/05 20:32:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander_internal.h"

static t_crawler	crawler_make(char *src, t_param *param)
{
	t_crawler	res;

	res.src = src;
	res.i = 0;
	res.squote = -1;
	res.dquote = -1;
	res.envvar = -1;
	res.sbuf = ft_sbuf_make(0);
	res.errno = 0;
	res.param = param;
	return (res);
}

static int	try(t_crawler *c, char sym, int *field, int *other)
{
	char	*s;

	if (c->src[c->i] != sym)
		return (1);
	if (*other != -1)
	{
		s = ft_calloc_if(2, 1);
		if (!s)
			return (ft_assign_i(&c->errno, 1, 0));
		s[0] = sym;
		if (!ft_sbuf_append(c->sbuf, s))
		{
			free(s);
			return (ft_assign_i(&c->errno, 1, 0));
		}
		free(s);
		c->i ++;
		return (0);
	}
	if (*field == -1)
		*field = c->i;
	else
		*field = -1;
	c->i ++;
	return (0);
}

static int	crawl(t_crawler *c)
{
	int		i;
	char	*subs;
	char	*sym;

	i = 0;
	sym = &c->src[c->i];
	while (*sym && *sym != '\'' && *sym != '\"' && *sym != '$')
	{
		sym ++;
		i ++;
	}
	subs = ft_substr(c->src, c->i, i);
	if (!subs || !ft_sbuf_append(c->sbuf, subs))
	{
		free(subs);
		return (ft_assign_i(&c->errno, 1, 1));
	}
	free(subs);
	c->i += i;
	return (0);
}

static int	go(t_treenode *node, t_param *param)
{
	t_crawler	c;

	c = crawler_make(node->content, param);
	if (!c.sbuf)
		return (1);
	while (1)
	{
		if (try(&c, '\'', &c.squote, &c.dquote) == 0)
			continue ;
		if (try(&c, '\"', &c.dquote, &c.squote) == 0)
			continue ;
		if (c.src[c.i] == '$' && expand_envvar(&c) == 0 && !c.errno)
			continue ;
		if (c.errno && ft_sbuf_finalize(&c.sbuf) == 0)
			break ;
		if ((crawl(&c) && ft_sbuf_finalize(&c.sbuf) == 0) || !c.src[c.i])
			break ;
	}
	if (c.errno)
		return (c.errno);
	free(node->content);
	node->content = ft_sbuf_get(c.sbuf);
	ft_sbuf_finalize(&c.sbuf);
	return (node->content == 0);
}

int	expand(t_treenode *node, t_param *param)
{
	if (param->opts.debug_output_level & DBG_PRINT_TOKEN_BEFORE_EXPANSION)
		FT_PRINTF("%s\n", (char *)node->content);
	if (go(node, param))
		return (1);
	node = node->child;
	while (node)
	{
		if (param->opts.debug_output_level & DBG_PRINT_TOKEN_BEFORE_EXPANSION)
			FT_PRINTF("%s\n", (char *)node->content);
		if (go(node, param))
			return (2);
		node = node->sibling_next;
	}
	return (0);
}
