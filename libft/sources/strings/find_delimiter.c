/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_delimiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:25:29 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/12 13:29:36 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

int	find_delimiter(const char *s, t_delims arr, size_t *len)
{
	size_t	i;
	size_t	del_len;

	i = 0;
	del_len = 0;
	while (i < arr.count)
	{
		del_len = ft_strlen(arr.delims[i].delim);
		if (ft_strncmp(s, arr.delims[i].delim, del_len) == 0)
		{
			*len = del_len;
			return (1);
		}
		i++;
	}
	return (0);
}
