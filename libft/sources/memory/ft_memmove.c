/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/24 18:07:23 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		c;
	char		*d;
	const char	*s;

	if (n == 0)
		return (dest);
	d = dest;
	s = src;
	if (d > s)
		while (n --)
			d[n] = s[n];
	else
	{
		c = -1;
		while ((++ c) < n)
			d[c] = s[c];
	}
	return (dest);
}
