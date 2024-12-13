/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:20 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/13 11:17:00 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

static void	calc_tokens_2(const char *p, t_delims arr, int *token_q,
			size_t *len)
{
	size_t	sz;

	sz = 0;
	*len = 0;
	if (*p == '\'')
	{
		locate_single_quotes(p, len);
		(*token_q)++;
		return ;
	}
	else if (find_delimiter(p, arr, &sz))
	{
		*len = sz;
		(*token_q)++;
		return ;
	}
	else
	{
		while (*p && !find_delimiter(p, arr, &sz) && *p != '\'')
		{
			p++;
			(*len)++;
		}
		(*token_q)++;
	}
}

static void	calc_tokens(const char *p, t_delims arr, int *token_q)
{
	size_t	len;

	len = 0;
	*token_q = 0;
	while (*p)
	{
		while (*p == ' ' || *p == '\t')
			p++;
		calc_tokens_2(p, arr, token_q, &len);
		p += len;
	}
}

static int	extract_token(char **res, const char **s, t_delims arr)
{
	size_t		len;

	len = 0;
	while (**s == ' ' || **s == '\t')
		(*s)++;
	if (**s == '\'')
	{
		handle_single_quotes(res, *s, &len);
		*s += len;
	}
	else if (find_delimiter(*s, arr, &len))
	{
		copy_token(res, *s, len);
		*s += len;
	}
	else if (locate_plain_token(*s, arr, &len))
	{
		copy_token(res, *s, len);
		*s += len;
	}
	return (0);
}

static char	**allocate_res(int token_q)
{
	char	**res;

	res = (char **)ft_calloc_if((token_q + 1) * sizeof(char *), 1);
	if (!res)
		return (NULL);
	res[token_q] = 0;
	return (res);
}

char	**ft_split_str(const char *s, t_delims arr, int *sz)
{
	char		**res;
	int			cwi;
	int			token_q;
	const char	*p;

	cwi = -1;
	p = s;
	calc_tokens(p, arr, &token_q);
	res = allocate_res(token_q);
	if (!res)
		return (NULL);
	if (token_q == 0)
		return (res);
	while (*p && ++cwi < token_q)
	{
		extract_token(&res[cwi], &p, arr);
		if (check_edges(res, &cwi))
			return (0);
	}
	if (sz)
		*sz = token_q;
	return (res);
}
