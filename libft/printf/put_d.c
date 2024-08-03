/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/12/20 17:19:31 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65

int	put_d(char **c, va_list *argv, int fd, t_params params)
{
	size_t	pure_len;
	size_t	res_len;
	char	s[MX];
	int		p;

	(*c)++;
	params.hex_prefix = 0;
	p = va_arg(*argv, int);
	pure_len = ft_lltoa_base(p, "0123456789", s);
	if (!p && params.precision != -1)
		pure_len = 0;
	if (params.precision != -1)
		params.left_zero_pad = 0;
	res_len = pad_n_put(s, pure_len, fd, params);
	return (res_len);
}
