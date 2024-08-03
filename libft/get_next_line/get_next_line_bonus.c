/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:40:15 by inikulin          #+#    #+#             */
/*   Updated: 2023/12/30 17:33:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

char	*rebuf(t_bufs *b, char **which, int sz, char *ret);
char	*app(char *a, int *as, char *b, int bs);

static char	*save(t_lefts *lefts, t_bufs *bufs, size_t last, int found)
{
	size_t	c;

	if (!found || last == BUFFER_SIZE - 1 || !((bufs->rdbuf)[last + 1]))
	{
		lefts->len = 0;
		return (bufs->res);
	}
	lefts->len = bufs->rdjn - last - 1;
	c = -1;
	while (++ c < lefts->len)
		lefts->left[c] = (bufs->rdbuf)[c + last + 1];
	return (bufs->res);
}

static char	*r(t_lefts *lefts, t_bufs *bufs)
{
	int	n;
	int	found;
	int	nsz;

	n = 0;
	while (n < bufs->rdjn && (bufs->rdbuf)[n] != '\n' && (bufs->rdbuf)[n])
		n ++;
	found = n < BUFFER_SIZE;
	if (found && (bufs->rdbuf)[n] == '\n')
		n ++;
	if (!rebuf(bufs, &(bufs->misc), bufs->tlen + n + 1, 0))
		return (0);
	nsz = 0;
	app(app(app(bufs->misc, &nsz, bufs->res, bufs->tlen), \
&nsz, bufs->rdbuf, n), &nsz, "\0", found);
	free(bufs->res);
	bufs->res = bufs->misc;
	bufs->misc = 0;
	bufs->tlen += n;
	return (save(lefts, bufs, n - 1, found));
}

static int	already(t_lefts *lefts, t_bufs *bufs)
{
	size_t	c;
	size_t	cc;
	int		found;

	c = 0;
	while (c < lefts->len && lefts->left[c] != '\n')
		c ++;
	found = (c < lefts->len && lefts->left[c] == '\n');
	c += found;
	bufs->msz = lefts->len - c;
	if (!rebuf(bufs, &(bufs->res), c + 1, 0))
		return (0);
	bufs->tlen = 0;
	app(bufs->res, &(bufs->tlen), lefts->left, c);
	cc = -1;
	while (++ cc < lefts->len - c)
		lefts->left[cc] = lefts->left[cc + c];
	lefts->len = cc;
	return (found);
}

static char	*gnl(int fd, t_lefts *lefts, t_bufs *b)
{
	if (lefts->len && already(lefts, b))
		return (rebuf(b, 0, -5, b->res));
	while (1)
	{
		b->rdjn = BUFFER_SIZE;
		while (--b->rdjn >= 0)
			b->rdbuf[b->rdjn] = 0;
		b->rdjn = read(fd, b->rdbuf, BUFFER_SIZE);
		if (b->rdjn < 0 || (!b->rdjn && !b->tlen))
			return (rebuf(b, 0, -7, 0));
		if (b->rdjn == 0)
			return (rebuf(b, 0, -5, app(b->res, &(b->tlen), "\0", 1)));
		r(lefts, b);
		if ((b->res)[b->tlen - 1] == '\n' || b->rdjn < BUFFER_SIZE)
			return (rebuf(b, 0, -5, b->res));
	}
}

char	*get_next_line(int fd)
{
	static t_lefts	lefts[1024];
	t_bufs			*bufs;
	char			*res;

	if (fd < 0 || fd > 1023)
		return (0);
	bufs = malloc(sizeof(t_bufs));
	if (!bufs)
	{
		free(bufs);
		return (0);
	}
	bufs->misc = 0;
	bufs->res = 0;
	bufs->tlen = 0;
	bufs->rdjn = 0;
	bufs->msz = 0;
	res = gnl(fd, &lefts[fd], bufs);
	bufs->res = 0;
	free(bufs);
	return (res);
}
