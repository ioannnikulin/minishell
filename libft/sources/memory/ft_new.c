/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 19:31:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_new_pi_pvoid(int i)
{
	return (ft_new_pi(i));
}

int	*ft_new_pi(int i)
{
	int	*res;

	res = ft_calloc_if(sizeof(int), 1);
	if (!res)
		return (0);
	*res = i;
	return (res);
}
