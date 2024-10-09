/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/10 00:34:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"

static char	sign(const char *nptr, size_t *cur)
{
	char	res;

	res = 1;
	while (ft_isspace(nptr[*cur]) || nptr[*cur] == '-' || nptr[*cur] == '+')
	{
		if (nptr[*cur] == '-')
			res *= -1;
		(*cur)++;
	}
	if (!ft_isdigit(nptr[*cur]))
		return (0);
	return (res);
}

int	ft_atoi(const char *nptr, int *errno)
{
	long	res;
	char	sgn;
	size_t	cur;

	ft_assign_i(errno, 0, 0);
	res = 0;
	cur = 0;
	sgn = sign(nptr, &cur);
	if (!sgn)
		return (ft_assign_i(errno, 1, 0));
	while (nptr[cur] && ft_isdigit(nptr[cur]))
	{
		res = res * 10 + nptr[cur ++] - '0';
		if ((sgn == 1 && res > INT_MAX) || - res < INT_MIN)
			return (ft_assign_i(errno, 2, 0));
	}
	return ((int)(sgn * res));
}
