/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_gen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:12:55 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/27 00:43:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss.h"

// ends on first of: nullptr in data / sz
t_mapss	*ft_mapss_gen(char ***data, int sz)
{
	t_mapss	*map;
	char	**kv;
	int		i;

	map = ft_calloc_if(sizeof(t_mapss), 1);
	if (!map)
		return (0);
	if (!sz || !*data)
		return (map);
	i = 0;
	kv = *data;
	while (kv && i < sz)
	{
		if (!kv[0] || !kv[1] || ft_mapss_add(map, kv[0], kv[1]))
			return (ft_mapss_finalize_nullptr(map, 0));
		if (++i < sz)
			kv = data[i];
		else
			kv = 0;
	}
	return (map);
}
