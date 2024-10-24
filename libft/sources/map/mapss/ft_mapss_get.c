/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:49:20 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/23 00:17:44 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"

char	*ft_mapss_get(t_mapss *map, char *key)
{
	t_dlist	*cur;

	if (!map || !map->head || !key)
		return (0);
	cur = map->head;
	while (cur && ft_strcmp(key, ((t_mapss_entry*)cur->content)->key) < 0)
		cur = cur->next;
	if (cur && ft_strcmp(key, ((t_mapss_entry*)cur->content)->key) == 0)
		return (((t_mapss_entry*)cur->content)->value);
	return (0);
}
