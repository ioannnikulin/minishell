/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_s_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/09 16:47:07 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_free_ss_uptonull_map(void **c, void (*f)(void **))
{
	char	**cc;
	int		i;

	if (!c)
		return ;
	cc = (char **)c;
	i = -1;
	while (c[++ i])
		f((void **)&cc[i]);
	free(cc);
}

static void	free_s_p(void **c)
{
	char	*cc;

	if (!c)
		return ;
	cc = *c;
	free(cc);
}

void	ft_free_ss_uptonull(void **c)
{
	ft_free_ss_uptonull_map(c, free_s_p);
}

void	ft_free_ss_uptonull_null(void ***c)
{
	if (!c)
		return ;
	ft_free_ss_uptonull_map(*c, ft_free_s_null);
	*c = 0;
}
