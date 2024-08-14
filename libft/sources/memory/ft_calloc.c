/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/14 20:59:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (0);
	ft_bzero(res, nmemb * size);
	return (res);
}

void	*ft_calloc_if(size_t size, int choice)
{
	void	*res;

	if (!choice)
		return (0);
	res = malloc(size);
	if (!res)
		return (0);
	ft_bzero(res, size);
	return (res);
}
