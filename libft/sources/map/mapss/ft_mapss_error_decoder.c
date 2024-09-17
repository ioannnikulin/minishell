/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_error_decoder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/14 14:01:01 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss.h"
#include "mapss_internal.h"
#include "../../../libft.h"

static	int	c(int choice, char **wherechar, char *whatchar)
{
	if (!choice)
		return (0);
	if (wherechar && *wherechar && whatchar)
		*wherechar = whatchar;
	return (0);
}

static void	err_option(int choice, int *whereint,
			int whatint, int ignore)
{
	(void)ignore;
	if (!choice)
		return ;
	ft_assign(whereint, whatint, 0);
}

char	*ft_mapss_error_decoder(int errno, int *finalize_mode)
{
	char	*res;

	res = 0;
	err_option(errno == 1, finalize_mode, 0, c(errno == 1, &res,
			"Couldn't allocate memory for a node\n"));
	err_option(errno == 2, finalize_mode, FREE_ENVVARS_DLISTS,
		c(errno == 2, &res, "Couldn't allocate memory for an entry\n"));
	err_option(errno == 3, finalize_mode, FREE_ENVVARS_DLISTS
		| FREE_ENVVARS_ENTRIES, c(errno == 3, &res,
			"Couldn't allocate memory for a key\n"));
	err_option(errno == 4, finalize_mode, FREE_ENVVARS_DLISTS
		| FREE_ENVVARS_ENTRIES | FREE_ENVVARS_KEYS, c(errno == 4, &res,
			"Couldn't allocate memory for a value\n"));
	return (res);
}
