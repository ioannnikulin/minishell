/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_generate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/17 20:10:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	make_worm(t_dlist **root, char *texts[])
{
	int		idx;
	t_dlist	*curnode;

	*root = ft_dlist_new(ft_strdup(texts[0]));
	if (!*root)
		return (-1);
	idx = 1;
	curnode = *root;
	while (texts[idx])
	{
		curnode->next = ft_dlist_new(ft_strdup(texts[idx]));
		if (!curnode->next)
			return (ft_dlist_clear(root, free, -1));
		curnode->next->prev = curnode;
		idx ++;
		curnode = curnode->next;
	}
	return (idx);
}

t_dlist	*ft_dlist_generate(char *texts[], int end_to)
{
	t_dlist	*root;
	t_dlist	*tail;
	int		idx;

	if (!texts || !texts[0])
		return (0);
	idx = make_worm(&root, texts);
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
