/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 14:17:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define START 0
#define SZ 14
//#define DEBUG

void	ft_atoi_test(void)
{
	char *tests[SZ] = {"hello", "¤", " \n  --12", "\t\v\r\a33", " \v \f \r  \n\n \t +70", "2147483647", "-2147483648", "007", "000", "", "-*", "999999999999999", "2147483648", "-2147483649"};
	int	exp[SZ] = {0, 0, 12, 0, 70, 2147483647, -2147483648, 7, 0, 0, 0, 0, 0, 0};
	int errnos[SZ] = {1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2};
	int errno = 0;
	for (int i = START; i < SZ; i ++) {
		#ifdef DEBUG
		printf("#%i", i);
		#endif
		errno = 0;
		int custom = ft_atoi(tests[i], &errno);
		#ifdef DEBUG
		if (custom != exp[i])
			printf(": expected [%i], got [%i]", exp[i], custom);
		printf("\n");
		#endif
		assert(exp[i] == custom);
		assert(errno == errnos[i]);
	}
}
