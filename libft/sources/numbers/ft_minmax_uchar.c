/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_uchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:28:56 by inikulin          #+#    #+#             */
/*   Updated: 2024/05/01 15:02:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

unsigned char	*ft_min_uc(unsigned char *a, unsigned char *b)
{
	if (*a < *b)
		return (a);
	return (b);
}

unsigned char	*ft_max_uc(unsigned char *a, unsigned char *b)
{
	if (*a > *b)
		return (a);
	return (b);
}

unsigned char	*ft_min_uc_va(int sz, ...)
{
	unsigned char	*res;
	unsigned char	*cur;
	va_list			args;

	va_start(args, sz);
	res = va_arg(args, unsigned char *);
	while (-- sz)
	{
		cur = va_arg(args, unsigned char *);
		if (*cur < *res)
			res = cur;
	}
	return (res);
}

unsigned char	*ft_max_uc_va(int sz, ...)
{
	unsigned char	*res;
	unsigned char	*cur;
	va_list			args;

	va_start(args, sz);
	res = va_arg(args, unsigned char *);
	while (-- sz)
	{
		cur = va_arg(args, unsigned char *);
		if (*cur > *res)
			res = cur;
	}
	return (res);
}
