/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:20:33 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/27 00:07:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapss_print(t_mapss *map)
{
	int				i;
	t_dlist			*current;
	t_mapss_entry	*entry;

	i = -1;
	current = map->head;
	FT_PRINTF("Map size: [%i]\n", map->size);
	while (++i < map->size)
	{
		entry = current->content;
		FT_PRINTF("key: [%s], value: [%s]\n", entry->key, entry->value);
		current = current->next;
	}
}
