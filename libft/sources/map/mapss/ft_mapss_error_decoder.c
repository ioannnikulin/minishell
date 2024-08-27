/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_error_decoder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:31:10 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 10:39:12 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss.h"
#include "mapss_internal.h"
#include "../../../libft.h"

static void	err_option(int choice, int *whereint, int whatint, char **wherechar, char *whatchar)
{
	if (!choice)
		return ;
	ft_assign(whereint, whatint, 0);
	if (wherechar && *wherechar && whatchar)
		*wherechar = whatchar;
}

char	*ft_mapss_error_decoder(int errno, int *finalize_mode)
{
	char	*res;

	res = 0;
	err_option(errno == 1, finalize_mode, 0, &res, "Couldn't allocate memory for a node\n");
	err_option(errno == 2, finalize_mode, FREE_ENVVARS_DLISTS, &res, "Couldn't allocate memory for an entry\n");
	err_option(errno == 3, finalize_mode, FREE_ENVVARS_DLISTS | FREE_ENVVARS_ENTRIES, &res, "Couldn't allocate memory for a key\n");
	err_option(errno == 4, finalize_mode, FREE_ENVVARS_DLISTS | FREE_ENVVARS_ENTRIES | FREE_ENVVARS_KEYS, &res, "Couldn't allocate memory for a value\n");
	return (res);
}
