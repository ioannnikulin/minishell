/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/22 21:09:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t			cur;
	size_t			ret;
	unsigned char	cc;

	cur = 0;
	ret = 0;
	cc = (unsigned char)(c % 256);
	while (s[cur])
	{
		if (s[cur] == cc)
			ret = cur;
		cur ++;
	}
	if (cc == 0)
		return ((char *)&s[cur]);
	if (ret != 0 || s[0] == cc)
		return ((char *)&s[ret]);
	return (0);
}
