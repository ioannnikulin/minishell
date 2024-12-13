/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:21:25 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/11 14:00:53 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

int	locate_double_quotes(const char *s, size_t *len)
{
	if (*s == '"')
	{
		s++;
		*len = 1;
	}
	while (*s && *s != '"')
	{
		s++;
		(*len)++;
	}
	if (*s == '"')
	{
		s++;
		(*len)++;
	}
	return (0);
}

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

int	handle_quotes(char **res, const char *s, size_t *len)
{
	if (*s == '\'')
	{
		locate_single_quotes(s, len);
		if (copy_token(res, s, *len) != 0)
			return (0);
		return (1);
	}
	if (*s == '"')
	{
		locate_double_quotes(s, len);
		if (copy_token(res, s, *len) != 0)
			return (0);
		return (1);
	}
	return (1);
}

void	process_quotes(const char *p, size_t *len)
{
	if (*p == '\'')
	{
		locate_single_quotes(p, len);
		return ;
	}
	else if (*p == '"')
	{
		locate_double_quotes(p, len);
		return ;
	}
}
