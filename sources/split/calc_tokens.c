/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:16:01 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/15 21:01:19 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

void	calc_tokens_2(const char *p, t_delims arr, int *token_q,
			size_t *len)
{
	size_t	sz;

	sz = 0;
	if (!p || !*p)
		return ;
	if (*p == '\'' || *p == '"')
	{
		process_quotes(p, len);
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
		process_plain_token(p, arr, len);
		(*token_q)++;
	}
}

void	calc_tokens(const char *p, t_delims arr, int *token_q)
{
	size_t	len;

	*token_q = 0;
	while (p && *p)
	{
		len = 0;
		while (*p && (*p == ' ' || *p == '\t'))
			p++;
		if (!*p)
			break ;
		calc_tokens_2(p, arr, token_q, &len);
		p += len;
	}
}
