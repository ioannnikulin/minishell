/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 17:30:23 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlist_add_front(t_dlist **lst, t_dlist *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	if (new->prev)
		new->prev->next = new;
	new->next->prev = new;
	*lst = new;
}

t_dlist	*ft_dlist_add_front_i(t_dlist **lst, int new)
{
	t_dlist	*node;
	int		*n;

	n = ft_calloc_if(sizeof(int), 1);
	if (!n)
		return (0);
	*n = new;
	node = ft_dlist_new(n);
	if (!node || !node->content)
	{
		free(n);
		free(node);
		return (0);
	}
	ft_dlist_add_front(lst, node);
	return (node);
}
