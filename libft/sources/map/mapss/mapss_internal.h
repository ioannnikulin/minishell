/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapss_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:41:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/26 22:28:51 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPSS_INTERNAL_H
# define MAPSS_INTERNAL_H
# include "mapss.h"

void	ft_mapss_insert(t_mapss *map, t_dlist *node);
void	ft_mapss_node_del(t_dlist *node);
#endif
