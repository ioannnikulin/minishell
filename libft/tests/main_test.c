/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/31 16:20:31 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	memcheck_enabled;

int	main(int argc, char **argv)
{
	memcheck_enabled = 0;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i ++)
		{
			if (ft_strncmp(argv[i], "memcheck", 9) == 0)
			{
				memcheck_enabled = 1;
				break;
			}
		}
	}
	tree_test();
	mapss_test();
	strings_test();
	numbers_test();
	symbols_test();
	memory_test();
	FT_PRINTF("printf in testing\n");
	ft_printf_test();
	FT_PRINTF("get_next_line in testing\n");
	get_next_line_test();
	printf("All tests passed successfully!\n");
	return (0);
}
