/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:06:11 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 17:48:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_crawler
{
	char	*src;
	int		i;
	int		squote;
	int		dquote;
	int		envvar;
	int		normal;
	char	*out;
	char	*toadd;
	int		errno;
}	t_crawler;

static t_crawler	crawler_make(char *src)
{
	t_crawler	res;

	res.src = src;
	res.i = 0;
	res.squote = -1;
	res.dquote = -1;
	res.envvar = -1;
	res.out = 0;
	res.toadd = 0;
	res.errno = 0;
	return (res);
}

static int	try(t_crawler *c, char sym, int *field)
{
	if (c->src[c->i] != sym)
		return (1);
	if (*field == -1)
		*field = c->i;
	else
		*field = -1;
	c->i ++;
	return (0);
}

static int	envvar(t_crawler *c)
{

}

int	expand(t_treenode *node, t_param *param)
{
	t_crawler	c;

	c = crawler_make(node->content);
	while (1)
	{
		if (try(&c, '\'', &c.squote) == 0)
			continue ;
		if (try(&c, '\"', &c.dquote) == 0)
			continue ;
		if (c.src[c.i] == '$' && envvar(&c) == 0)
			continue ;
		normal(&c);
	}
}
