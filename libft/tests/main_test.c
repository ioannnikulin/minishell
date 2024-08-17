/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 20:41:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	mapss_test();
	strings_test();
	numbers_test();
	symbols_test();
	memory_test();
	ft_printf("printf in testing\n");
	ft_printf_test();
	ft_printf("get_next_line in testing\n");
	get_next_line_test();
	printf("All tests passed successfully!\n");
	return (0);
}
