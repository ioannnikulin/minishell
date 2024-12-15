/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_plain_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:25 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/15 21:00:48 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

void	process_plain_token(const char *p, t_delims arr, size_t *len)
{
	size_t		sz;
	size_t		len_in_quotes;

	sz = 0;
	len_in_quotes = 0;
	while (*p && *p != ' ' && *p != '\t'
		&& !find_delimiter(p, arr, &sz))
	{
		if (*p == '\'' || *p == '"')
		{
			process_quotes(p, &len_in_quotes);
			*len += len_in_quotes;
			p += len_in_quotes;
			if (*p == ' ' || *p == '\t' || *p == '\0')
				break ;
		}
		else
		{
			(*len)++;
			p++;
		}
	}
	return ;
}

int	locate_plain_token(const char *s, t_delims arr, size_t *len)
{
	process_plain_token(s, arr, len);
	return (1);
}
