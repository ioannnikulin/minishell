/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/23 20:20:19 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_s_null(void **c)
{
	if (!c)
		return ;
	ft_free_s(*((char **)c));
	*c = 0;
}

void	ft_free_pi_null(void **p)
{
	if (!p)
		return ;
	ft_free_pi(*(int **)p);
	*p = 0;
}
