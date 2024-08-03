/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:28:56 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 20:58:19 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	*ft_min_int(int *a, int *b)
{
	if (*a < *b)
		return (a);
	return (b);
}

int	*ft_max_int(int *a, int *b)
{
	if (*a > *b)
		return (a);
	return (b);
}

int	*ft_min_int_va(int sz, ...)
{
	int		*res;
	int		*cur;
	va_list	args;

	va_start(args, sz);
	res = va_arg(args, int *);
	while (-- sz)
	{
		cur = va_arg(args, int *);
		if (*cur < *res)
			res = cur;
	}
	return (res);
}

int	*ft_max_int_va(int sz, ...)
{
	int		*res;
	int		*cur;
	va_list	args;

	va_start(args, sz);
	res = va_arg(args, int *);
	while (-- sz)
	{
		cur = va_arg(args, int *);
		if (*cur > *res)
			res = cur;
	}
	return (res);
}
