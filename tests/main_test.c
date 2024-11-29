/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:56:57 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/29 14:17:13 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
int	e2e_tests(void);
int	unit_tests(void);

int	main(void)
{
	ft_printf("unit tests in progress\n");
	unit_tests();
	ft_printf("e2e tests in progress\n");
	e2e_tests();
	ft_printf("e2e tests completed\n");
	printf("tokenization in testing\n");
	tokenize_cmd_test();
	return (0);
}
