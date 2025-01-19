/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/19 18:49:21 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers_test.h"

int	numbers_test(void)
{
	printf("ceil/floor in testing\n");
	ft_ceil_floor_test();
	printf("atoi in testing\n");
	ft_atoi_test();
	printf("itoa in testing\n");
	ft_itoa_test();
	printf("ft_lltoa_base in testing\n");
	ft_lltoa_base_test();
	printf("ft_ulltoa_base in testing\n");
	ft_ulltoa_base_test();
	printf("ft_ulltoa_base_strdup in testing\n");
	ft_ulltoa_base_strdup_test();
	printf("ft_lltoa_base_strdup in testing\n");
	ft_lltoa_base_strdup_test();
	return (0);
}
