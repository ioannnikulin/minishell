/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/23 12:18:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l;

	if (len == 0)
		return (ft_empty_string());
	l = ft_strlen((char *)s);
	if (l < start)
		return (ft_empty_string());
	if (start + len > l)
		l = l - start;
	else
		l = len;
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_memcpy(res, &s[start], l);
	res[l] = 0;
	return (res);
}
