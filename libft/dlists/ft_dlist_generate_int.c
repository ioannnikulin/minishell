/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_generate_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 21:28:00 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	nothing(void *c)
{
	(void)c;
}

static int	make_worm(t_dlist **root, int nums[], int sz)
{
	int		idx;
	t_dlist	*curnode;

	*root = ft_dlist_new((void *)(unsigned long long)(nums[0]));
	if (!*root)
		return (-1);
	idx = 1;
	curnode = *root;
	while (idx < sz)
	{
		curnode->next = ft_dlist_new((void *)
				(unsigned long long)(nums[idx ++]));
		if (!curnode->next)
			return (ft_dlist_clear(root, nothing, -1));
		curnode->next->prev = curnode;
		curnode = curnode->next;
	}
	return (idx);
}

t_dlist	*ft_dlist_generate_int(int nums[], int sz, int end_to)
{
	t_dlist	*root;
	t_dlist	*tail;
	int		idx;

	if (!sz)
		return (0);
	idx = make_worm(&root, nums, sz);
	if (idx == -1)
		return (0);
	if (end_to != -1 && end_to != 0)
		return ((t_dlist *)(unsigned long long)ft_dlist_clear(&root, free, 0));
	if (end_to == -1)
		return (root);
	tail = ft_dlist_last(root);
	tail->next = root;
	tail->next->prev = tail;
	return (root);
}
