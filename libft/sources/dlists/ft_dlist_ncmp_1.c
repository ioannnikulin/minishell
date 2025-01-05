/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_ncmp_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:41:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/22 16:07:16 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

int	ft_voidptr_strcmp(void *a, void *b)
{
	return (ft_strcmp((char *)a, (char *)b));
}

int	ft_dlist_ncmp_str(t_dlist *a, t_dlist *b, int n)
{
	return (ft_dlist_ncmp(a, b, n, ft_voidptr_strcmp));
}
