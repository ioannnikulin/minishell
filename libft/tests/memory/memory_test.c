/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 18:35:12 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_test.h"

int	memory_test(void)
{
	printf("memset in testing\n");
	ft_memset_test();
	printf("bzero in testing\n");
	ft_bzero_test();
	printf("memcpy in testing\n");
	ft_memcpy_test();
	printf("memmove in testing\n");
	ft_memmove_test();
	printf("memchr in testing\n");
	ft_memchr_test();
	printf("memcmp in testing\n");
	ft_memcmp_test();
	return (0);
}
