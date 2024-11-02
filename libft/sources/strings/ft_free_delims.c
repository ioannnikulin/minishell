/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_delims.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:54:16 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/02 15:35:04 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "libft.h"

void	ft_free_delim_s(t_delims *arr)
{
	size_t	i;

	if (arr == NULL || arr->delims == NULL)
		return;

	i = 0; 
    while(i < arr->count)
	{
		if (arr->delims[i].delim != NULL)
		{
			free(arr->delims[i].delim);
			arr->delims[i].delim = NULL;
		}
        i++;
	}
}

void	ft_free_delims_arr(t_delims *arr)
{
	if (arr == NULL)
		return ;

	free(arr->delims);
	arr->delims = NULL;
	arr->count = 0;
	arr->error = 0;
}