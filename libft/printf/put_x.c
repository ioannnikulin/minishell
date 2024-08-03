/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/12/20 17:23:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65

static void	set_flags(t_params *params, char **c, int p)
{
	params->capital_hex = 0;
	params->sign_mandatory = 0;
	params->space_before_positive = 0;
	if (**c == 'X')
		params->capital_hex = 1;
	(*c)++;
	if (!p)
		params->hex_prefix = 0;
}

int	put_x(char **c, va_list *argv, int fd, t_params params)
{
	size_t			pure_len;
	size_t			res_len;
	char			s[MX];
	unsigned int	p;

	p = va_arg(*argv, unsigned int);
	set_flags(&params, c, p);
	ft_bzero(s, MX);
	if (params.capital_hex)
		pure_len = ft_ulltoa_base(p, "0123456789ABCDEF", s);
	else
		pure_len = ft_ulltoa_base(p, "0123456789abcdef", s);
	if (!p && params.precision != -1)
		pure_len = 0;
	if (params.precision != -1)
		params.left_zero_pad = 0;
	res_len = pad_n_put(s, pure_len, fd, params);
	return (res_len);
}
