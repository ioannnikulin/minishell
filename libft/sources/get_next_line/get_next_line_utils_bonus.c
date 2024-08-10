/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:40:15 by inikulin          #+#    #+#             */
/*   Updated: 2023/12/30 17:26:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

char	*rebuf(t_bufs *b, char **wh, int sz, char *ret)
{
	if (!b)
		return (0);
	if (sz < 0 && !wh)
	{
		if ((2 & -sz) > 0)
			rebuf(b, &(b->res), 0, ret);
		if ((4 & -sz) > 0)
			rebuf(b, &(b->misc), 0, ret);
		return (ret);
	}
	if (wh == &(b->res) || wh == &(b->misc))
	{
		free(*wh);
		*wh = 0;
		if (!sz)
			return (ret);
		*wh = malloc(sz);
		if (!*wh)
			return (rebuf(b, 0, -7, ret));
	}
	while (--sz >= 0)
		(*wh)[sz] = 0;
	return (*wh);
}

char	*app(char *a, int *as, char *b, int bs)
{
	int	c;

	c = 0;
	while (c < bs)
	{
		a[*as + c] = b[c];
		c ++;
	}
	*as = *as + bs;
	return (a);
}
