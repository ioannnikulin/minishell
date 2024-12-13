/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_plain_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:25 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/13 17:39:12 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

/*return 1 if its not a plain token*/
// int	locate_plain_token(const char *s, t_delims arr, size_t *len)
// {
// 	size_t	sz;

// 	sz = 0;
// 	while (*s && !find_delimiter(s, arr, &sz) && *s != '\'' && *s != '"')
// 	{
// 		s++;
// 		(*len)++;
// 	}
// 	if (*len == 0)
// 		return (0);
// 	return (1);
// }

void	process_plain_token(const char *p, t_delims arr, size_t *len)
{
	size_t		sz;
	int			in_quotes;
	size_t		len_in_quotes;

	sz = 0;
	in_quotes = 0;
	len_in_quotes = 0;
	while (*p && !in_quotes && *p != ' ' && *p != '\t'
		&& !find_delimiter(p, arr, &sz))
	{
		if (*p == '\'' || *p == '"')
		{
			in_quotes = !in_quotes;
			process_quotes(p, &len_in_quotes);
			in_quotes = !in_quotes;
			if (*(p + len_in_quotes) != ' ' && *(p + len_in_quotes) != '\t')
				*len += len_in_quotes;
			else
				break ;
		}
		p++;
		(*len)++;
	}
	return ;
}

int	locate_plain_token(const char *s, t_delims arr, size_t *len)
{
	process_plain_token(s, arr, len);
	return (1);
}
