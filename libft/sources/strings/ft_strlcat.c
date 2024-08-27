/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 13:20:15 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sc;
	size_t	dc;
	size_t	dl;

	sc = 0;
	dc = 0;
	dl = 0;
	if (size > 0)
	{
		while (dst[dc] && dc < size)
			dc ++;
		dl = dc;
		if (dl < size && size != 0)
		{
			while (src[sc] && sc + dl < size - 1)
				dst[dc++] = src[sc++];
			dst[dc] = 0;
		}
	}
	while (src[sc])
		sc ++;
	return (dl + sc);
}
