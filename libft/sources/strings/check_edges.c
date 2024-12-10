/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_edges.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:38:52 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/26 15:38:58 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

int	check_edges(char **res, int *cwi)
{
	if (!res[*cwi])
	{
		while (-- (*cwi) > -1)
			free(res[*cwi]);
		free(res);
		return (1);
	}
	if (!res[*cwi][0])
	{
		free(res[*cwi]);
		(*cwi)--;
	}
	return (0);
}
