/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapss.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:41:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/23 17:43:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPSS_H
# define MAPSS_H
# include "../../dlists/dlist.h"
# include "../../../libft.h"

typedef struct s_mapss_entry
{
	char	*key;
	char	*value;
}	t_mapss_entry;

typedef struct s_mapss
{
	t_dlist	*head;
	t_dlist	*tail;
	int		size;
}	t_mapss;

int		ft_mapss_add(t_mapss *map, const char *key, const char *value);
int		ft_mapss_del(t_mapss *map, const char *key);
void	ft_mapss_print(t_mapss *map);
int		ft_mapss_finalize(t_mapss *map, int mode, char *msg, int retval);
int		ft_mapss_ncmp(t_mapss *a, t_mapss *b, int n);
char	*ft_mapss_get(t_mapss *map, char *key);
#endif
