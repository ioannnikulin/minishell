/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 16:51:28 by inikulin         ###   ########.fr       */
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

// dup2 to self is a fflush
int	ft_printf(const char *s, ...)
{
	va_list	argv;
	int		res;

	va_start(argv, s);
	dup2(STDOUT_FILENO, STDOUT_FILENO);
	res = vprintf(s, argv);
	va_end(argv);
	return (res);
}
#else

int	ft_printf(const char *s, ...)
{
	va_list	argv;
	int		res;

	va_start(argv, s);
	res = printf_impl(1, s, &argv);
	va_end(argv);
	return (res);
}
#endif
