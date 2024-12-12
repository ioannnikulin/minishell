/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:02:37 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/12 14:57:56 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

int	copy_token(char **res, const char *s, size_t len)
{
	*res = (char *)ft_calloc_if((len + 1) * sizeof(char), 1);
	if (res == 0)
		return (1);
	ft_strlcpy(*res, s, len + 1);
	(*res)[len] = '\0';
	return (0);
}
