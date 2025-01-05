/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:19:12 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/02 15:21:34 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	c;

	c = 0;
	while (src[c])
	{
		dst[c] = src[c];
		c ++;
	}
	dst[c] = 0;
	while (src[c])
		c ++;
	return (dst);
}
