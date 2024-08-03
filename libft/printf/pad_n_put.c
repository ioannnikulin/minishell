/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_n_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/12/20 17:36:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65

static void	pad(int len, char c, int fd)
{
	while (len --)
		write(fd, &c, 1);
}

static int	hex_prefix(t_params params, int fd, int print)
{
	if (!params.hex_prefix)
		return (0);
	if (!print)
		return (2);
	if (params.capital_hex)
		write(fd, "0X", 2);
	else
		write(fd, "0x", 2);
	return (2);
}

static int	sign(char orig, t_params params, int fd, int print)
{
	if (orig == '-')
	{
		if (print)
			write(fd, &orig, 1);
		return (1);
	}
	if (params.sign_mandatory)
	{
		if (print)
			write(fd, "+", 1);
		return (1);
	}
	if (params.space_before_positive)
	{
		if (print)
			write(fd, " ", 1);
		return (1);
	}
	return (0);
}

static void	calc_lens(int lens[6], t_params p, char *c, int l)
{
	int	pure;

	ft_bzero(lens, 6 * sizeof(int));
	if (l <= MX && l > 0)
		lens[1] = sign(c[MX - l], p, 0, 0);
	lens[4] = l;
	if (l > 0 && l <= MX && c[MX - l] == '-')
		lens[4]--;
	if (p.precision > lens[4])
		lens[3] = p.precision - lens[4];
	lens[2] = hex_prefix(p, 0, 0);
	pure = lens[1] + lens[2] + lens[3] + lens[4];
	if (p.left_space_pad && p.min_width > pure)
		lens[5] = p.min_width - pure;
	else if (p.left_zero_pad && p.min_width > pure)
		lens[3] += p.min_width - pure;
	else if (!p.left_space_pad && !p.left_zero_pad \
			&& p.min_width > pure)
		lens[0] = p.min_width - pure;
}

int	pad_n_put(char *c, int l, int fd, t_params params)
{
	int	lens[6];

	if (params.left_space_pad)
		params.left_zero_pad = 0;
	if (params.sign_mandatory)
		params.space_before_positive = 0;
	calc_lens(lens, params, c, l);
	pad(lens[0], ' ', fd);
	if (l <= MX && l > 0)
		sign(c[MX - l], params, fd, 1);
	hex_prefix(params, fd, 1);
	pad(lens[3], '0', fd);
	write(fd, &c[MX - lens[4]], lens[4]);
	pad(lens[5], ' ', fd);
	return (lens[0] + lens[1] + lens[2] + lens[3] + lens[4] + lens[5]);
}
