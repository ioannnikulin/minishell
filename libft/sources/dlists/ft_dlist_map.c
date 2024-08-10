/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/23 20:41:53 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dlist	*connect_tail( \
	t_dlist **res, t_dlist *res_tail, t_dlist *orig, void (*d)(void*))
{
	t_dlist	*loop_to;

	loop_to = ft_dlist_last(orig)->next;
	if (!loop_to)
		return (*res);
	if (loop_to != orig)
		return ((t_dlist *)(unsigned long long)ft_dlist_clear(res, d, 0));
	res_tail->next = *res;
	(*res)->prev = res_tail;
	return (*res);
}

static t_dlist	*m(void *(*f)(void *), void (*d)(void*), void *o, t_dlist **r)
{
	void	*nc;
	t_dlist	*nnode;

	nc = f(o);
	nnode = ft_dlist_new(nc);
	if (!nnode)
	{
		d(nc);
		if (*r)
			ft_dlist_clear(r, d, 0);
		return (0);
	}
	return (nnode);
}

t_dlist	*ft_dlist_map(t_dlist *lst, void *(*f)(void *), void (*del)(void*))
{
	t_dlist	*res;
	t_dlist	*iter_res;
	t_dlist	*iter_orig;
	int		lstlen;

	lstlen = ft_dlist_size(lst);
	if (!(lstlen --))
		return (0);
	res = 0;
	res = m(f, del, lst->content, &res);
	if (!res)
		return (0);
	iter_orig = lst->next;
	iter_res = res;
	while (lstlen --)
	{
		iter_res->next = m(f, del, iter_orig->content, &res);
		if (!(iter_res->next))
			return (0);
		iter_res->next->prev = iter_res;
		iter_orig = iter_orig->next;
		iter_res = iter_res->next;
	}
	return (connect_tail(&res, ft_dlist_last(res), lst, del));
}
