/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 17:40:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 11

typedef struct s_testcase
{
	char	*s;
	int	c;
}	t_testcase;

void	ft_strrchr_test(void)
{
	t_testcase tests[SZ];
	tests[0] = (t_testcase){"hello", 'h'};
	tests[1] = (t_testcase){"hello", 'l'};
	tests[2] = (t_testcase){"hello", 'o'};
	tests[3] = (t_testcase){"hello", '\n'};
	tests[4] = (t_testcase){"hello", '\0'};
	tests[5] = (t_testcase){"hello", 'H'};
	tests[6] = (t_testcase){"hello", 2147483647};
	tests[7] = (t_testcase){"hello", 'l' + 256};
	tests[8] = (t_testcase){"¤hello¤", 'l' + 256 + 2048};
	tests[9] = (t_testcase){"", '0'};
	tests[10] = (t_testcase){"", '\0'};
	// system strlen segfaults on NULL, so not checking it
	for (int i = 0; i <  SZ; i ++)
	{
		char* std = strrchr(tests[i].s, tests[i].c);
		char* custom = ft_strrchr(tests[i].s, tests[i].c);
		//printf("%i %p %p %p\n", i, tests[i].s, std, custom);
		assert(std == custom);
	}
}
