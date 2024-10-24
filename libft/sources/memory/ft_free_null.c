/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:34:16 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/23 12:34:19 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_ss_null(void ***c, int sz)
{
	if (c && *c)
	{
		ft_free_ss(*c, sz);
		*c = NULL;
	}
}

void	ft_free_s_null(void **c)
{
	ft_free_s(*((char **)c));
	*c = 0;
}

void	ft_free_pi_null(void **p)
{
	ft_free_pi(*(int **)p);
	*p = 0;
}
