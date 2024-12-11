/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 13:38:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers_test.h"

int	numbers_test(void)
{
	printf("atoi in testing\n");
	ft_atoi_test();
	printf("itoa in testing\n");
	ft_itoa_test();
	printf("ft_lltoa_base in testing\n");
	ft_lltoa_base_test();
	printf("ft_ulltoa_base in testing\n");
	ft_ulltoa_base_test();
	return (0);
}
