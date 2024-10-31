/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_delim_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:58:31 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/31 13:07:43 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

bool	is_in_quotes(const char **p, const char ex, int *in_quotes)
{
	if (**p == ex)
	{
		*in_quotes = !(*in_quotes);
		return (true);
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
