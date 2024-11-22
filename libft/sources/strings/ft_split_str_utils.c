/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:51:25 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/22 08:00:16 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

int	find_delimiter(const char *s, t_delims *ar, size_t *op_len)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < ar->count)
	{
		len = ft_strlen(ar->delims[i].delim);
		if (ft_strncmp(s, ar->delims[i].delim, len) == 0)
		{
			*op_len = len;
			return (1);
		}
		i++;
	}
	*op_len = 0;
	return (0);
}

int	extract_delimiter(char **res, const char **s, size_t op_len, int cwi)
{
	res[cwi] = (char *)ft_calloc_if((op_len + 1) * sizeof(char), 1);
	if (res[cwi] == 0)
		return (1);
	ft_strlcpy(res[cwi], *s, op_len + 1);
	res[cwi][op_len] = '\0';
	*s += op_len;
	return (0);
}

int	extract_plain_token(char **res, const char **s, t_delims *ar, int cwi)
{
	size_t		token_len;
	const char	*start;
	size_t		op_len;

	token_len = 0;
	start = *s;
	op_len = 0;
	while (**s && !find_delimiter(*s, ar, &op_len))
	{
			(*s)++;
			token_len++;
	}
	if (token_len == 0)
		return (1);
	res[cwi] = (char *)ft_calloc_if((token_len + 1) * sizeof(char), 1);
	if (res[cwi] == 0)
		return (1);
	ft_strlcpy(res[cwi], start, token_len + 1);
	res[cwi][token_len] = '\0';
	return (0);
}
