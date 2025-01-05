/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:56:57 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 19:54:11 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
int	e2e_tests(void);
int	unit_tests(void);

int	main(void)
{
	FT_PRINTF("unit tests in progress\n");
	unit_tests();
	FT_PRINTF("unit tests completed\n");
	FT_PRINTF("e2e tests in progress\n");
	e2e_tests();
	FT_PRINTF("e2e tests completed\n");
	return (0);
}
