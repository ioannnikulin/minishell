/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 20:51:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_s(void **c)
{
	char	*cc;

	cc = *c;
	free(cc);
	*c = 0;
}

void	ft_free_nop(void **c)
{
	(void)c;
}

void	ft_free_pi(void **p)
{
	int	*pp;

	pp = *p;
	free(pp);
	*p = 0;
}
