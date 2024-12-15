/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_empty_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:27:51 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/11 14:28:02 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

int	if_empty_string(const char *s, char ***p_ss)
{
	if (!*s)
	{
		*p_ss = ft_calloc_if(sizeof(char *) * 2, 1);
		if (!*p_ss)
			return (1);
		return (2);
	}
	return (0);
}
