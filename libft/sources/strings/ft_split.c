/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:24:25 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 21:29:11 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "strings_internal.h"

static int	count_words(const char *pp, const char *charset)
{
	int		word_qtty;
	char	*p;

	word_qtty = 0;
	p = (char *)pp;
	while (p && charset && *p)
	{
		if (ft_is_in(*p, charset))
		{
			if (word_qtty > 0)
				word_qtty = -word_qtty;
		}
		else
		{
			if (word_qtty <= 0)
				word_qtty = -word_qtty + 1;
		}
		p ++;
	}
	if (word_qtty < 0)
		return (-word_qtty);
	return (word_qtty);
}

static void	parse_word(char **res, const char **f, const char *charset)
{
	int		cwlen;
	char	**from;

	from = (char **)f;
	while (**from && ft_is_in(**from, charset))
		(*from)++;
	cwlen = 0;
	while ((*from)[cwlen] && !ft_is_in((*from)[cwlen], charset))
		cwlen ++;
	if (cwlen == 0)
		return ;
	(*res) = (char *) ft_calloc_if((cwlen + 1) * sizeof(char), 1);
	if (*res == 0)
		return ;
	cwlen = 0;
	while (**from && !ft_is_in(**from, charset))
	{
		(*res)[cwlen ++] = **from;
		(*from)++;
	}
	(*res)[cwlen] = 0;
}

char	**ft_split_set(const char *str, const char *charset, int *sz)
{
	char	**res;
	int		word_qtty;
	int		cwi;

	word_qtty = count_words(str, charset);
	if (sz)
		*sz = -1;
	res = (char **) ft_calloc_if((word_qtty + 1) * sizeof(char *), 1);
	if (!res)
		return (0);
	res[word_qtty] = 0;
	if (word_qtty == 0)
		return (res);
	cwi = 0;
	while (*str && cwi < word_qtty)
	{
		parse_word(&res[cwi], &str, charset);
		if (check_edges(res, &cwi))
			return (0);
		cwi ++;
	}
	if (sz)
		*sz = word_qtty;
	return (res);
}

char	**ft_split(const char *str, char c, int *sz)
{
	char	cc[2];

	cc[0] = c;
	cc[1] = 0;
	return (ft_split_set(str, cc, sz));
}
