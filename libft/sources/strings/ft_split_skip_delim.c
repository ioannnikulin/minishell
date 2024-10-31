/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_delim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:50:43 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/31 13:05:23 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

static int	count_words(const char *pp, const char *charset, const char ex)
{
	int			word_qtty;
	const char	*p;
	int			in_quotes;

	word_qtty = 0;
	p = pp;
	in_quotes = 0;
	while (p && charset && *p)
	{
		is_in_quotes(&p, ex, &in_quotes);
		if (!in_quotes && ft_is_in(*p, charset))
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

static void	parse_word(char **res, const char **f,
					const char *charset, const char ex)
{
	int			cwlen;
	const char	*start;
	int			in_quotes;

	in_quotes = 0;
	while (**f && ft_is_in(**f, charset))
		(*f)++;
	start = *f;
	cwlen = 0;
	while ((**f) && (in_quotes || !ft_is_in(**f, charset)))
	{
		is_in_quotes(f, ex, &in_quotes);
		cwlen++;
		(*f)++;
	}
	if (cwlen == 0)
		return ;
	if ((copy_word(res, start, cwlen) != 0))
	{
		*res = NULL;
		ft_printf("copy_word failed\n");	
	}
}

static int	check_edges(char **res, int *cwi)
{
	if (!res[*cwi])
	{
		while (-- (*cwi) > -1)
			free(res[*cwi]);
		free(res);
		return (1);
	}
	if (!res[*cwi][0])
	{
		free(res[*cwi]);
		(*cwi)--;
	}
	return (0);
}

char	**ft_split_set_skip_delim(const char *str, const char *charset,
					const char ex, int *sz)
{
	char		**res;
	const char	*current;
	int			word_qtty;
	int			cwi;

	word_qtty = count_words(str, charset, ex);
	res = (char **) ft_calloc_if((word_qtty + 1) * sizeof(char *), 1);
	if (!res)
		return (0);
	res[word_qtty] = 0;
	if (word_qtty == 0)
		return (res);
	cwi = 0;
	current = str;
	while (*current && cwi < word_qtty)
	{
		parse_word(&res[cwi], &current, charset, ex);
		if (check_edges(res, &cwi))
			return (0);
		cwi ++;
	}
	if (sz)
		*sz = word_qtty;
	return (res);
}

char	**ft_split_skip_delim(const char *str, char c, char ex, int *sz)
{
	char	cc[2];

	cc[0] = c;
	cc[1] = 0;
	if (sz)
		*sz = -1;
	return (ft_split_set_skip_delim(str, cc, ex, sz));
}
