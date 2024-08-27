/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapss_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:41:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/13 22:40:00 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPSS_INTERNAL_H
# define MAPSS_INTERNAL_H
# define FREE_ENVVARS_DLISTS 1
# define FREE_ENVVARS_ENTRIES 2
# define FREE_ENVVARS_KEYS 4
# define FREE_ENVVARS_VALUES 8
# define MAPSS_FULL 15
# include "mapss.h"

int		ft_mapss_insert(t_mapss *map, t_dlist *node);
char	*ft_mapss_error_decoder(int errno, int *finalize_mode);
#endif
