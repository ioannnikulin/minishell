/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/29 13:21:50 by inikulin         ###   ########.fr       */
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

int	put_c(char **c, va_list *argv, int fd, t_params params)
{
	int		lens[3];
	char	s;

	(*c)++;
	s = (char)va_arg(*argv, int);
	lens[0] = 0;
	lens[1] = 1;
	lens[2] = 0;
	if (params.min_width > lens[1])
	{
		lens[0] = params.min_width - lens[1];
		if (params.left_space_pad)
		{
			lens[2] = lens[0];
			lens[0] = 0;
		}
	}
	pad(lens[0], ' ', fd);
	write(fd, &s, lens[1]);
	pad(lens[2], ' ', fd);
	return (lens[0] + lens[1] + lens[2]);
}
