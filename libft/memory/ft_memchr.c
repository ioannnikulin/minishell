/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/22 20:54:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			res;
	unsigned char	cc;
	unsigned char	*ss;

	if (n == 0)
		return (0);
	cc = (unsigned char)(c % 256);
	res = 0;
	ss = (unsigned char *)s;
	while (res < n - 1 && ss[res] != cc)
		res ++;
	if (ss[res] == cc)
		return ((void *)&ss[res]);
	return (0);
}
