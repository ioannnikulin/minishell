/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa_base_strdup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:36:51 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/19 18:58:21 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MX 65
#define MAXBASE 256

char	*ft_ulltoa_base_strdup(unsigned long long nbr, char *base)
{
	char	buf[MX];
	char	*res;
	size_t	sz;
	size_t	i;

	res = 0;
	sz = ft_ulltoa_base(nbr, base, buf);
	if (sz == 0)
		return (res);
	res = ft_calloc_if(sizeof(char) * (sz + 1), 1);
	if (!res)
		return (res);
	i = 0;
	while (i < sz)
	{
		res[i] = buf[i + MX - sz];
		i ++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_ulltoa_strdup(unsigned long long nbr)
{
	return (ft_ulltoa_base_strdup(nbr, "0123456789"));
}

char	*ft_lltoa_base_strdup(long long nbr, char *base)
{
	char	buf[MX];
	char	*res;
	size_t	sz;
	size_t	i;

	res = 0;
	sz = ft_lltoa_base(nbr, base, buf);
	if (sz == 0)
		return (res);
	res = ft_calloc_if(sizeof(char) * (sz + 1), 1);
	if (!res)
		return (res);
	i = 0;
	while (i < sz)
	{
		res[i] = buf[i + MX - sz];
		i ++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_lltoa_strdup(long long nbr)
{
	return (ft_lltoa_base_strdup(nbr, "0123456789"));
}
