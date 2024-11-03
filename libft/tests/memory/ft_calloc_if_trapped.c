/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_if_trapped.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 17:49:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/memory/memory.h"
#ifndef FT_CALLOC_IF_TRAPPED
# define FT_CALLOC_IF_TRAPPED 0
#endif

typedef struct s_calloc_trap
{
	int	cur;
	int	tgt;
}	t_calloc_trap;

t_calloc_trap	trap = (t_calloc_trap){0, 0};

// TODO: get from cmd
void	ft_calloc_if_trap_setup()
{
	trap.tgt = FT_CALLOC_IF_TRAPPED;
}

void	*ft_calloc_if(size_t size, int choice)
{
	if (++ trap.cur == trap.tgt || !choice)
		return (0);
	return (ft_calloc(size, 1));
}

void	ft_calloc_if_trap_count()
{
	ft_printf("Total ft_calloc_calls: %i\n", trap.cur);
}
