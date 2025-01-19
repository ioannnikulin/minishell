/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_custom_only.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 20:19:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"

#ifndef PRINTF_ALLOWED

int	ft_printf(const char *s, ...)
{
	va_list	argv;
	int		res;

	va_start(argv, s);
	res = printf_impl(1, s, &argv);
	va_end(argv);
	return (res);
}

int	ft_fprintf(int fd, const char *s, ...)
{
	va_list	argv;
	int		res;

	va_start(argv, s);
	res = printf_impl(fd, s, &argv);
	va_end(argv);
	return (res);
}

int	ft_errprintf(const char *s, ...)
{
	va_list	argv;
	int		res;

	va_start(argv, s);
	res = printf_impl(2, s, &argv);
	va_end(argv);
	return (res);
}
//should have added ft_fprintf_s and ss, but later
#endif
