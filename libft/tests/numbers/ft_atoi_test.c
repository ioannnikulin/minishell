/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 18:30:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 12 

void	ft_atoi_test(void)
{
	char *tests[SZ] = {"hello", "¤", " \n  --12", "\t\v\r\a33", " \v \f \r  \n\n \t +70", "2147483647", "-2147483648", "007", "000", "", "-*", "999999999999999"};
	int errnos[SZ] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int errno = 0;
	for (int i = 0; i < SZ; i ++) {
		assert(ft_atoi(tests[i], &errno) == atoi(tests[i]));
		assert(errno == errnos[i]);
	}
}
