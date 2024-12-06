/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/09 19:16:48 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	l;
	size_t	r;

	l = ft_strlen((char *)s1);
	r = ft_strlen((char *)s2);
	res = ft_calloc_if((l + r + 1) * sizeof(char), 1);
	if (!res)
		return (0);
	ft_strlcpy(res, s1, l + 1);
	ft_strlcpy(&res[l], s2, r + 1);
	res[l + r] = 0;
	return (res);
}

static char	*alloc(const char **ss, int sz, const char *delim, int *delim_len)
{
	int		i;
	char	*res;
	int		len;

	len = 0;
	*delim_len = ft_strlen(delim);
	i = -1;
	len = 0;
	while (++i < sz)
		len += ft_strlen(ss[i]);
	len += *delim_len * (sz - 1) + 1;
	res = ft_calloc_if(len * sizeof(char), 1);
	return (res);
}

char	*ft_strjoin_multi(const char **ss, int sz, const char *delim)
{
	char	*res;
	int		delim_len;
	int		i;
	int		cur_len;
	int		app_len;

	if (!ss)
		return (0);
	res = alloc(ss, sz, delim, &delim_len);
	if (!res)
		return (0);
	i = -1;
	cur_len = 0;
	while (++i < sz)
	{
		app_len = ft_strlen(ss[i]);
		ft_strlcpy(&res[cur_len], ss[i], app_len + 1);
		cur_len += app_len;
		if (i != sz - 1)
			ft_strlcpy(&res[cur_len], delim, delim_len + 1);
		cur_len += delim_len;
	}
	return (res);
}

char	*ft_strjoin_multi_free_outer(char **ss, int sz, const char *delim)
{
	char		*res;
	int			i;
	const char	**sss;

	if (!ss)
		return (0);
	sss = ft_calloc_if(sizeof(char *) * sz, 1);
	if (!sss)
	{
		free(ss);
		return (0);
	}
	i = -1;
	while (++i < sz)
		sss[i] = ss[i];
	res = ft_strjoin_multi(sss, sz, delim);
	free(sss);
	free(ss);
	return (res);
}

char	*ft_strjoin_multi_free_full(char **ss, int sz, const char *delim)
{
	char	*res;
	int		i;

	if (!ss)
		return (0);
	res = ft_strjoin_multi_free_outer(ss, sz, delim);
	i = -1;
	while (++i < sz)
		free(ss[i]);
	return (res);
}
