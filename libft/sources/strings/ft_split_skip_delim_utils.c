/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_delim_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:58:31 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/15 20:41:47 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

/*if not in quotes and delimeter - we check if flag is positive
(mean its first delimeter), we change flag to negative and
shift pointer to the next symbol.
everything else: in quotes, or not quotes but not delimeter -
we look if flag negative (mean previous symbols were delimeters)
we change the flag to positive, increment word count, and shift
pointer to the next symbol*/

bool	is_in_quotes(const char p, t_skip_chars ex_arr, int *in_quotes,
				int *quote_type)
{
	size_t	i;

	i = 0;
	while (i < ex_arr.count)
	{
		if (p == ex_arr.exs[i].ex)
		{
			if (*in_quotes)
			{
				if (*quote_type == p)
				{
					*in_quotes = 0;
					*quote_type = 0;
					return (true);
				}
			}
			else
			{
				*quote_type = p;
				*in_quotes = 1;
			}
		}
		i++;
	}
	return (false);
}

int	copy_word(char **res, const char *from, int length)
{
	int	i;

	*res = (char *) ft_calloc_if((length + 1) * sizeof(char), 1);
	if (*res == NULL)
		return (1);
	i = 0;
	while (i < length)
	{
		(*res)[i] = from[i];
		i++;
	}
	(*res)[length] = '\0';
	return (0);
}
