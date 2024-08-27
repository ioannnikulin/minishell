/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/12/20 16:19:01 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"

static void	pad(int l, char c, int fd)
{
	while (l > 0)
	{
		write(fd, &c, 1);
		l --;
	}
}

static void	calc_lens(char **s, t_params params, int lens[3])
{
	if (!(*s))
	{
		*s = "(null)";
		lens[1] = (int)ft_strlen(*s);
		if (params.precision > -1 && params.precision < lens[1])
			*s = "";
	}
	lens[0] = 0;
	lens[1] = (int)ft_strlen(*s);
	lens[2] = 0;
	if (params.precision >= 0 && params.precision < lens[1])
		lens[1] = params.precision;
	if (params.min_width > lens[1])
	{
		lens[0] = params.min_width - lens[1];
		if (params.left_space_pad)
		{
			lens[2] = lens[0];
			lens[0] = 0;
		}
	}
}

int	put_s(char **c, va_list *argv, int fd, t_params params)
{
	int		lens[3];
	char	*s;

	(*c)++;
	s = va_arg(*argv, char *);
	calc_lens(&s, params, lens);
	pad(lens[0], ' ', fd);
	write(fd, s, lens[1]);
	pad(lens[2], ' ', fd);
	return (lens[0] + lens[1] + lens[2]);
}
