/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbuf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:54:35 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 22:06:35 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define STEP 20

t_sbuf	*ft_sbuf_make(char *src)
{
	t_sbuf	*res;

	res = ft_calloc_if(sizeof(t_sbuf), 1);
	if (!res)
		return (0);
	res->step = STEP;
	res->capacity = res->step;
	res->sz = 0;
	if (src)
	{
		res->sz = ft_strlen(src);
		if (res->capacity < res->sz + 2)
			res->capacity = ft_ceil(((float)res->sz)
					/ res->step) * res->step;
	}
	res->content = ft_calloc_if(res->capacity, 1);
	if (!res->content)
	{
		free(res);
		return (0);
	}
	ft_memcpy(res->content, src, res->sz);
	return (res);
}

t_sbuf	*ft_sbuf_realloc(t_sbuf *sbuf, int ncap)
{
	char	*ncont;
	int		copy;

	if (ncap == sbuf->capacity)
		return (sbuf);
	ncont = ft_calloc_if(ncap, 1);
	if (!ncont)
		return (0);
	copy = *ft_min_int(&ncap, &sbuf->sz);
	ft_memcpy(ncont, sbuf->content, copy);
	free(sbuf->content);
	sbuf->content = ncont;
	sbuf->capacity = ncap;
	sbuf->sz = copy;
	return (sbuf);
}

t_sbuf	*ft_sbuf_append(t_sbuf *sbuf, char *what)
{
	char	*ncont;
	int		wlen;
	int		ncap;

	if (!sbuf || !what)
		return (sbuf);
	wlen = ft_strlen(what);
	if (sbuf->sz + wlen < sbuf->capacity - 2)
		ft_memcpy(&sbuf->content[sbuf->sz], what, wlen);
	else
	{
		ncap = sbuf->capacity + ft_ceil(((float)wlen) / sbuf->step)
			* sbuf->step;
		ncont = ft_calloc_if(ncap, 1);
		if (!ncont)
			return (0);
		sbuf->capacity = ncap;
		ft_memcpy(ncont, sbuf->content, sbuf->sz);
		ft_memcpy(&ncont[sbuf->sz], what, wlen);
		free(sbuf->content);
		sbuf->content = ncont;
	}
	sbuf->sz += wlen;
	return (sbuf);
}

char	*ft_sbuf_get(t_sbuf *sbuf)
{
	return (ft_strdup(sbuf->content));
}

int	ft_sbuf_finalize(t_sbuf **sbuf)
{
	free((*sbuf)->content);
	ft_bzero(*sbuf, sizeof(*sbuf));
	free(*sbuf);
	return (0);
}
