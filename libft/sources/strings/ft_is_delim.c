/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:43:25 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/03 12:52:20 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "strings_internal.h"

int	ft_is_delim(const char *s, t_delim *delims, int count, size_t *match_len)
{
	size_t	len;
	int		i;

	i = 0;
	while (i < count)
	{
		len = ft_strlen(delims[i].delim);
		if (ft_strncmp(s, delims[i].delim, len) == 0)
		{
			if (match_len)
				*match_len = len;
			return (1);
		}
		i++;
	}
	return (0);
}
