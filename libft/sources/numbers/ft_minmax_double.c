/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:28:56 by inikulin          #+#    #+#             */
/*   Updated: 2024/05/01 15:02:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

double	*ft_min_dbl(double *a, double *b)
{
	if (*a < *b)
		return (a);
	return (b);
}

double	*ft_max_dbl(double *a, double *b)
{
	if (*a > *b)
		return (a);
	return (b);
}

double	*ft_min_dbl_va(int sz, ...)
{
	double	*res;
	double	*cur;
	va_list	args;

	va_start(args, sz);
	res = va_arg(args, double *);
	while (-- sz)
	{
		cur = va_arg(args, double *);
		if (*cur < *res)
			res = cur;
	}
	return (res);
}

double	*ft_max_dbl_va(int sz, ...)
{
	double	*res;
	double	*cur;
	va_list	args;

	va_start(args, sz);
	res = va_arg(args, double *);
	while (-- sz)
	{
		cur = va_arg(args, double *);
		if (*cur > *res)
			res = cur;
	}
	return (res);
}
