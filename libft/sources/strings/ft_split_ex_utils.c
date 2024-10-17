/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ex_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:58:31 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/17 19:32:52 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

bool	is_in_quotes(char **p, const char ex, int *in_quotes)
{
	if (**p == ex)
	{
		*in_quotes = !(*in_quotes);
		return (true);
	}
	return (false);
}

void	copy_word(char **res, char **from, const char *charset,
				const char ex)
{
	int	cwlen;
	int	in_quotes;

	cwlen = 0;
	in_quotes = 0;
	while (**from && (in_quotes || !ft_is_in(**from, charset)))
	{
		if (is_in_quotes(from, ex, &in_quotes))
		{
			(*res)[cwlen++] = ex;
			(*from)++;
			continue ;
		}
		(*res)[cwlen++] = **from;
		(*from)++;
	}
	(*res)[cwlen] = '\0';
}
