/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 17:43:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 15
//#define DEBUG

typedef struct s_testcase
{
	char	*s;
	int	c;
	size_t	n;
}	t_testcase;

void	ft_memchr_test(void)
{
	t_testcase tests[SZ];
	tests[0] = (t_testcase){"hello", 'h', 5};
	tests[1] = (t_testcase){"hello", 'l', 5};
	tests[2] = (t_testcase){"hello", 'o', 5};
	tests[3] = (t_testcase){"hello", '\n', 5};
	tests[4] = (t_testcase){"hello", '\0', 5};
	tests[5] = (t_testcase){"hello", 'H', 5};
	tests[6] = (t_testcase){"hello", 2147483647, 5};
	char s[20] = "abcdefghi";
	s[1] = 66;
	tests[7] = (t_testcase){s, 66, 5};
	s[2] = 66;
	tests[8] = (t_testcase){s, 66, 5};
	s[8] = 66;
	tests[9] = (t_testcase){s, 66, 5};
	bzero(s, 20);
	tests[10] = (t_testcase){s, '0', 5};
	tests[11] = (t_testcase){s, '\0', 5};
	tests[12] = (t_testcase){0, '\0', 0};
	tests[13] = (t_testcase){"hello", 'l' + 512, 5};
	tests[14] = (t_testcase){"¤hello¤", 'l' + 512 + 2048, 5};
	for (int i = 0; i <  SZ; i ++)
	{
		char* std = memchr(tests[i].s, tests[i].c, tests[i].n);
		char* custom = ft_memchr(tests[i].s, tests[i].c, tests[i].n);
		#ifdef DEBUG
			printf("%i %p %p %p\n", i, tests[i].s, std, custom);
		#endif
		assert(std == custom);
	}
}
