/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:16:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 20:22:40 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# define LLTOA_BASE_MAX_LEN 65
# include "sources/symbols/symbols.h"
# include "sources/numbers/numbers.h"
# include "sources/strings/strings.h"
# include "sources/memory/memory.h"
# include "sources/lists/list.h"
# include "sources/dlists/dlist.h"
# include "sources/map/mapss/mapss.h"
# include "sources/tree/tree.h"

int		ft_printf(const char *s, ...);
int		ft_fprintf(int fd, const char *s, ...);
char	*get_next_line(int fd);
#endif
