/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:49:54 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/19 12:21:17 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizing_internal.h"

int	cleanup(t_delims *arr, char **ss, int retval)
{
	if (arr != NULL)
	{
		ft_free_delims_arr(arr);
	}
	if (ss != NULL && *ss != NULL)
	{
		ft_free_ss_uptonull((void **)ss);
	}
	return (retval);
}
