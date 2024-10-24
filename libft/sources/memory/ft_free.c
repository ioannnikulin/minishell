/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/23 12:31:43 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_ss(void **c, int sz)
{
	char	**cc;
	int		i;

	i = 0;
	if (c == NULL)
		return ;
	cc = (char **)c;
	while (i < sz)
	{
		free(cc[i]);
		i++;
	}
	free(cc);
}

void	ft_free_s(void *c)
{
	char	*cc;

	cc = c;
	free(cc);
}

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
