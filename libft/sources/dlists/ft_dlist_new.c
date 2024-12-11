/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 21:37:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist	*ft_dlist_new(void *content)
{
	t_dlist	*r;

	r = ft_calloc_if(sizeof(t_dlist), 1);
	if (!r)
		return (0);
	r->next = 0;
	r->prev = 0;
	r->content = content;
	return (r);
}
