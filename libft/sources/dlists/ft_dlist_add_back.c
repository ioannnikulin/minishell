/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 23:58:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlist_add_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*cur;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	cur = ft_dlist_last(*lst);
	new->next = cur->next;
	new->prev = cur;
	if (new->next)
		new->next->prev = new;
	if (new->prev)
		new->prev->next = new;
}

t_dlist	*ft_dlist_add_back_s(t_dlist **lst, char *new)
{
	t_dlist	*node;
	char	*n;

	n = ft_strdup(new);
	if (!n)
		return (0);
	node = ft_dlist_new(n);
	if (!node || !node->content)
	{
		free(n);
		free(node);
		return (0);
	}
	ft_dlist_add_back(lst, node);
	return (node);
}
