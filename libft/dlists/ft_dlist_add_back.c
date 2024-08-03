/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/16 17:52:01 by inikulin         ###   ########.fr       */
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
