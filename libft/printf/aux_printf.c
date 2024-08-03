/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/28 19:44:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "aux_printf.h"

static int	single_char_param(char **c, char orig, unsigned char *set)
{
	if (**c && **c == orig)
	{
		(*set) = 1;
		(*c)++;
		return (1);
	}
	return (0);
}

static int	numeric_param(char **c, int *set)
{
	int	neg;

	neg = 0;
	if (!ft_isdigit(**c) && !(**c == '-' && ft_isdigit(*(*c + 1))))
		return (0);
	*set = 0;
	if (**c == '-')
	{
		neg = 1;
		(*c)++;
	}
	while (ft_isdigit(**c))
		*set = *set * 10 + (*((*c)++)) - '0';
	if (neg)
		*set = 0;
	return (1);
}

static int	parse_prec(char **c, int *set)
{
	(*c)++;
	*set = 0;
	numeric_param(c, set);
	return (1);
}

static t_params	parse_params(char **c)
{
	t_params	r;

	r = (t_params){0, 0, 0, 0, 0, 0, -1, 0};
	while (1)
	{
		if (single_char_param(c, '-', &r.left_space_pad))
			continue ;
		if (single_char_param(c, '0', &r.left_zero_pad))
			continue ;
		if (single_char_param(c, '#', &r.hex_prefix))
			continue ;
		if (single_char_param(c, ' ', &r.space_before_positive))
			continue ;
		if (single_char_param(c, '+', &r.sign_mandatory))
			continue ;
		if (**c != '0' && numeric_param(c, &r.min_width))
			continue ;
		if (**c == '.' && parse_prec(c, &r.precision))
			continue ;
		break ;
	}
	return (r);
}

int	parse_conversion(char **c, va_list *argv, int fd)
{
	t_params	params;

	(*c)++;
	params = parse_params(c);
	if (**c == 'c')
		return (put_c(c, argv, fd, params));
	else if (**c == 's')
		return (put_s(c, argv, fd, params));
	else if (**c == 'p')
		return (put_p(c, argv, fd, params));
	else if (**c == 'i' || **c == 'd')
		return (put_d(c, argv, fd, params));
	else if (**c == 'u')
		return (put_u(c, argv, fd, params));
	else if (**c == 'x' || **c == 'X')
		return (put_x(c, argv, fd, params));
	else if (**c == '%')
		return (put_percent(c, argv, fd, params));
	write(fd, "!!ERROR!!", 9);
	return (9);
}
