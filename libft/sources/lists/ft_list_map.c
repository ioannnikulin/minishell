/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 11:34:37 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*connect_tail(t_list **res, t_list *res_tail, t_list *orig)
{
	t_list	*orig_loop_to;
	t_list	*res_iter;

	orig_loop_to = ft_list_last(orig)->next;
	if (!orig_loop_to)
		return (*res);
	res_iter = *res;
	while (orig != orig_loop_to)
	{
		res_iter = res_iter->next;
		orig = orig->next;
	}
	res_tail->next = res_iter;
	return (*res);
}

static t_list	*m(void *(*f)(void *), void (*d)(void*), void *o, t_list **r)
{
	void	*nc;
	t_list	*nnode;

	nc = f(o);
	nnode = ft_list_new(nc);
	if (!nnode)
	{
		d(nc);
		if (*r)
			ft_list_clear(r, d);
		return (0);
	}
	return (nnode);
}

t_list	*ft_list_map(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*res;
	t_list	*iter_res;
	t_list	*iter_orig;
	int		lstlen;

	lstlen = ft_list_size(lst);
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
		iter_orig = iter_orig->next;
		iter_res = iter_res->next;
	}
	return (connect_tail(&res, ft_list_last(res), lst));
}
