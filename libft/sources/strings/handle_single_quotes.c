/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_single_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:21:25 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/11 14:00:53 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

int	locate_single_quotes(const char *s, size_t *len)
{
	if (*s == '\'')
	{
		s++;
		*len = 1;
	}
	while (*s && *s != '\'')
	{
		s++;
		(*len)++;
	}
	if (*s == '\'')
	{
		s++;
		(*len)++;
	}
	return (0);
}

int	handle_single_quotes(char **res, const char *s, size_t *len)
{
	locate_single_quotes(s, len);
	if (copy_token(res, s, *len) != 0)
		return (0);
	return (1);
}
