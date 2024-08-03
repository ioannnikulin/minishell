/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_ncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:41:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 21:23:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdint.h>

/*int	ft_voidptr_strcmp(void *a, void *b)
{
	return (ft_strncmp((char *)a, (char *)b, ft_strlen((char *)a)));
}*/

int	ft_voidptr_icmp(void *a, void *b)
{
	if ((int)(intptr_t)a > (int)(intptr_t)b)
		return (1);
	if ((int)(intptr_t)a < (int)(intptr_t)b)
		return (-1);
	return (0);
}

static int	loop(t_dlist *a, t_dlist *b, int (*cmp)(void *, void *), int *cur)
{
	int	rs;

	rs = cmp(a->content, b->content);
	if (rs != 0)
	{
		if (rs < 0)
			(*cur) = -(*cur);
		return (1);
	}
	return (0);
}

int	ft_dlist_ncmp(t_dlist *a, t_dlist *b, int n, int (*cmp)(void *, void *))
{
	int	cur;
	int	alen;
	int	blen;

	cur = 1;
	if (a == b)
		return (0);
	alen = ft_dlist_size(a);
	blen = ft_dlist_size(b);
	while (cur <= n && alen > 0 && blen > 0)
	{
		alen --;
		blen --;
		if (loop(a, b, cmp, &cur))
			return (cur);
	}
	if (alen < blen)
		return (-cur);
	if (alen > blen)
		return (cur);
	return (0);
}

/*int	ft_dlist_ncmp_str(t_dlist *a, t_dlist *b, int n)
{
	return (ft_dlist_ncmp(a, b, n, ft_voidptr_strcmp));
}*/

int	ft_dlist_ncmp_i(t_dlist *a, t_dlist *b, int n)
{
	return (ft_dlist_ncmp(a, b, n, ft_voidptr_icmp));
}
