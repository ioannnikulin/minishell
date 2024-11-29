/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:43:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/28 15:08:12 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free_s(void *c)
{
	char	*cc;

	cc = c;
	free(cc);
}

static void	ft_free_ss_sz_map(void **c, int sz, void (*f)(void **))
{
	char	**cc;
	int		i;

	if (!c)
		return ;
	cc = (char **)c;
	i = -1;
	while (++i < sz)
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

void	ft_free_ss_sz(void **c, int sz)
{
	ft_free_ss_sz_map(c, sz, free_s_p);
}

void	ft_free_ss_sz_null(void ***c, int sz)
{
	if (!c)
		return ;
	ft_free_ss_sz_map(*c, sz, ft_free_s_null);
	*c = 0;
}
