/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_delim_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:58:31 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/09 16:46:57 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

bool	ft_is_quote(const char p, t_skip_chars ex_arr)
{
	size_t	i;

	i = 0;
	while (i < ex_arr.count)
	{
		if (p == ex_arr.exs[i].ex)
			return (true);
		i++;
	}
	return (false);
}

bool	is_in_quotes(const char p, t_skip_chars ex_arr, int *in_quotes)
{
	size_t	i;

	i = 0;
	while (i < ex_arr.count)
	{
		if (p == ex_arr.exs[i].ex)
		{
			*in_quotes = !(*in_quotes);
			return (true);
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
