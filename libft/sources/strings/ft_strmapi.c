/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 21:43:12 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	l;

	if (!s || !s[0])
		return (ft_empty_string());
	l = ft_strlen((char *)s);
	res = ft_calloc_if((l + 1) * sizeof(char), 1);
	if (!res)
		return (0);
	res[l --] = 0;
	while (1)
	{
		if (!f)
			res[l] = s[l];
		else
			res[l] = f(l, s[l]);
		if (l -- == 0)
			return (res);
	}
}
