/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:16:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 16:57:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# define LLTOA_BASE_MAX_LEN 65
# include "sources/symbols/symbols.h"
# include "sources/numbers/numbers.h"
# include "sources/strings/strings.h"
# include "sources/memory/memory.h"
# include "sources/lists/list.h"
# include "sources/dlists/dlist.h"
# include "sources/map/mapss/mapss.h"
# include "sources/tree/tree.h"
# include "sources/control_flow/control_flow.h"
# include "sources/printf/print.h"

char	*get_next_line(int fd);
#endif
