/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:20 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/09 16:11:40 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

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

static void	calc_tokens(const char *pp, int *token_q, t_delims *ar)
{
	size_t		op_len;
	const char	*p;

	*token_q = 0;
	p = pp;
	while (*p)
	{
		while (*p == ' ')
			p++;
		if (find_delimiter(p, ar, &op_len))
		{
			(*token_q)++;
			p += op_len;
		}
		else
		{
			while (*p && !find_delimiter(p, ar, &op_len))
				p++;
			(*token_q)++;
		}
	}
}

static int	extract_token(char **res, const char **s, int token_q, t_delims *ar)
{
	int			cwi;
	size_t		op_len;

	cwi = 0;
	op_len = 0;
	while (*s && cwi < token_q)
	{
		while (**s == ' ')
			(*s)++;
		if (find_delimiter(*s, ar, &op_len))
		{
			extract_delimiter(res, s, op_len, cwi);
		}
		else
		{
			extract_plain_token(res, s, ar, cwi);
		}
		if (check_edges(res, &cwi))
			return (1);
		cwi++;
	}
	return (0);
}

char	**ft_split_buf(const char *s, const void *delim_ar, int *sz)
{
	char		**res;
	int			token_q;
	t_delims	*ar;

	res = NULL;
	ar = (t_delims *)delim_ar;
	calc_tokens(s, &token_q, ar);
	if (sz)
		*sz = -1;
	res = (char **) ft_calloc_if((token_q + 1) * sizeof(char *), 1);
	if (!res)
		return (NULL);
	res[token_q] = 0;
	if (token_q == 0)
		return (res);
	extract_token(res, &s, token_q, ar);
	if (sz)
		*sz = token_q;
	return (res);
}
