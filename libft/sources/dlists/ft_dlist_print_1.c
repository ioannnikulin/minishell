/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_print_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/11 17:30:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printpi(void *p)
{
	FT_PRINTF("%i", *(int *)p);
}

int	ft_dlist_print_pi(t_dlist *lst, char *delim)
{
	return (ft_dlist_print(lst, 0, delim, printpi));
}
