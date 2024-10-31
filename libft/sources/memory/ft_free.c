/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/30 13:01:17 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_nop(void **c)
{
	(void)c;
}

void	ft_free_pi(void *p)
{
	int	*pp;

	pp = p;
	free(pp);
}

void	ft_free_arr(void **arr)
{
	if (arr && *arr)
	{
		free(*arr);
		*arr = NULL;
	}
}
