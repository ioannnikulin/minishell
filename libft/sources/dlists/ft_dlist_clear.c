/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/06 22:23:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_dlist_clear(t_dlist **lst, void (*del)(void *), int ret)
{
	t_dlist	*cur;
	t_dlist	*n;
	int		lstlen;

	if (!lst || !(*lst))
		return (ret);
	lstlen = ft_dlist_size(*lst);
	cur = *lst;
	while (lstlen --)
	{
		n = cur->next;
		if (del)
			del(cur->content);
		free(cur);
		cur = n;
	}
	*lst = 0;
	return (ret);
}

int	ft_dlist_clear_s(t_dlist **lst, int ret)
{
	return (ft_dlist_clear(lst, ft_free_s, ret));
}
