/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:20 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/06 19:45:21 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

static int	calc_tokens(const char *p, int *token_q, t_delims arr)
{
	size_t		op_len;

	*token_q = 0;
	if (!*p)
		return (ft_assign_i(token_q, 1, 0));
	while (*p)
	{
		while (*p == ' ')
			p++;
		if (*p == '\0')
			break ;
		if (find_delimiter(p, arr, &op_len))
		{
			(*token_q)++;
			p += op_len;
		}
		else
		{
			while (*p && !find_delimiter(p, arr, &op_len))
				p++;
			(*token_q)++;
		}
	}
	return (0);
}

static int	extract_token(char **res, const char **s, int token_q, t_delims arr)
{
	int			cwi;
	size_t		op_len;

	cwi = 0;
	op_len = 0;
	while (*s && cwi < token_q)
	{
		while (**s == ' ')
			(*s)++;
		if (find_delimiter(*s, arr, &op_len))
		{
			if (extract_delimiter(res, s, op_len, cwi) != 0)
				return (1);
		}
		else
		{
			if (extract_plain_token(res, s, arr, cwi) != 0)
				return (1);
		}
		if (check_edges(res, &cwi))
			return (1);
		cwi++;
	}
	return (0);
}

char	**ft_split_str(const char *s, t_delims arr, int *sz)
{
	char		**res;
	int			token_q;

	res = NULL;
	calc_tokens(s, &token_q, arr);
	if (sz)
		*sz = -1;
	res = (char **) ft_calloc_if((token_q + 1) * sizeof(char *), 1);
	if (!res)
		return (NULL);
	res[token_q] = 0;
	if (token_q == 0)
		return (res);
	if (extract_token(res, &s, token_q, arr) != 0)
	{
		ft_free_ss_uptonull((void **)res);
		return (NULL);
	}
	if (sz)
		*sz = token_q;
	return (res);
}
