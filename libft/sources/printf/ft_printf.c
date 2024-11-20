/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 12:11:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "aux_printf.h"

int	printf_impl(int fd, const char *s, va_list *argv)
{
	char	*c;
	int		normal;
	int		res;

	c = (char *)s;
	normal = 0;
	res = 0;
	while (*c)
	{
		if (*c == '%')
		{
			write(fd, (c - normal), normal);
			res += normal;
			normal = 0;
			res += parse_conversion(&c, argv, fd);
			continue ;
		}
		normal ++;
		c ++;
	}
	va_end(*argv);
	write(fd, c - normal, normal);
	return (res + normal);
}

int	ft_fprintf(int fd, const char *s, ...)
{
	va_list	argv;

	va_start(argv, s);
	return (printf_impl(fd, s, &argv));
}

#ifdef PRINTF_ALLOWED

int	ft_printf(const char *s, ...)
{
	va_list	argv;

	va_start(argv, s);
	return (vprintf(s, argv));
}
#else

int	ft_printf(const char *s, ...)
{
	va_list	argv;

	va_start(argv, s);
	return (printf_impl(1, s, &argv));
}
#endif
