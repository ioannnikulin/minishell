/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 11:31:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_list_clear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*n;
	int		lstlen;

	lstlen = ft_list_size(*lst);
	cur = *lst;
	while (lstlen --)
	{
		n = cur->next;
		del(cur->content);
		free(cur);
		cur = n;
	}
	*lst = 0;
}
