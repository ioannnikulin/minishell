/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 18:33:36 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	first;
	size_t	cur;
	size_t	last;

	cur = 0;
	while (ft_is_in(s1[cur], set))
		cur ++;
	if (s1[cur] == 0)
		return (ft_empty_string());
	first = cur;
	last = cur;
	while (s1[cur])
	{
		if (!ft_is_in(s1[cur], set))
			last = cur;
		cur ++;
	}
	res = malloc((last - first + 2) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, &s1[first], last - first + 2);
	res[last - first + 1] = 0;
	return (res);
}
