/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 21:42:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	l;
	size_t	r;

	l = ft_strlen((char *)s1);
	r = ft_strlen((char *)s2);
	res = ft_calloc_if((l + r + 1) * sizeof(char), 1);
	if (!res)
		return (0);
	ft_strlcpy(res, s1, l + 1);
	ft_strlcpy(&res[l], s2, r + 1);
	res[l + r] = 0;
	return (res);
}
