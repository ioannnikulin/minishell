/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:49:20 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/31 16:44:24 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"

char	*ft_mapss_get(t_mapss *map, char *key)
{
	t_dlist	*cur;

	if (!map || !map->head || !key)
		return (0);
	cur = map->head;
	while (ft_strcmp(key, ((t_mapss_entry *)cur)->key) < 0)
		cur = cur->next;
	if (ft_strcmp(key, ((t_mapss_entry *)cur)->key) == 0)
		return (((t_mapss_entry *)cur)->value);
	return (0);
}
