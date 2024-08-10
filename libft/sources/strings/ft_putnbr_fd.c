/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/23 14:40:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"

static void	go(long long nn, int is_neg, char buf[21], int fd)
{
	size_t	c;

	c = 21;
	while (nn > 0)
	{
		buf[-- c] = '0' + nn % 10;
		nn /= 10;
	}
	if (is_neg)
		write(fd, "-", 1);
	write(fd, &buf[c], 21 - c);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		buf[21];
	int			is_neg;
	long long	nn;

	nn = n;
	is_neg = 0;
	ft_bzero(buf, 21);
	if (n == 0)
	{
		buf[0] = '0';
		write(fd, buf, 1);
	}
	if (nn < 0)
	{
		nn = -nn;
		is_neg = 1;
	}
	return (go(nn, is_neg, buf, fd));
}
