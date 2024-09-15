/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_ncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:17:49 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 13:39:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss.h"
#include "../../numbers/numbers.h"

static int	node_cmp(t_dlist *a, t_dlist *b)
{
	t_mapss_entry	*aa;
	t_mapss_entry	*bb;
	int				res;

	aa = a->content;
	bb = b->content;
	res = ft_strcmp(aa->key, bb->key);
	if (res)
		return (res);
	return (ft_strcmp(aa->value, bb->value));
}

int	ft_mapss_ncmp(t_mapss *a, t_mapss *b, int n)
{
	t_dlist	*a_node;
	t_dlist	*b_node;
	int		res;
	int		i;

	i = *ft_min_int(&a->size, &n);
	n = *ft_min_int(&b->size, &i);
	i = -1;
	a_node = a->head;
	b_node = b->head;
	while (++ i < n)
	{
		res = node_cmp(a_node, b_node);
		if (res > 0)
			return (i + 1);
		if (res < 0)
			return (-i - 1);
		a_node = a_node->next;
		b_node = b_node->next;
	}
	if (a_node)
		return (i + 1);
	if (b_node)
		return (-i - 1);
	return (0);
}
