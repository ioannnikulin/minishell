/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:20 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/13 17:17:21 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

static int	extract_token(char **res, const char **s, t_delims arr)
{
	size_t		len;

	len = 0;
	while (**s == ' ' || **s == '\t')
		(*s)++;
	if (**s == '\'' || **s == '"')
	{
		handle_quotes(res, *s, &len);
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
	ft_printf("Tokens number: %i\n", token_q);
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
