/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/27 01:36:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
//#define DEBUG

typedef struct s_testcase
{
	char	*s1;
	char	*s2;
	size_t	n;
}	t_testcase;

#define START 0
#define SZ 32

void	ft_memcmp_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"abc", "abC", 0};
	t[1] = (t_testcase){"abc", "abC", 1};
	t[2] = (t_testcase){"abc", "abC", 2};
	t[3] = (t_testcase){"abc", "abC", 3};
	t[4] = (t_testcase){"abc", "abC", 4};
	t[5] = (t_testcase){"abc", "ab", 0};
	t[6] = (t_testcase){"abc", "ab", 1};
	t[7] = (t_testcase){"abc", "ab", 2};
	t[8] = (t_testcase){"abc", "ab", 3};
	t[9] = (t_testcase){"abc", "ab", 4};
	t[10] = (t_testcase){"", "", 0};
	t[11] = (t_testcase){"", "", 1};
	t[12] = (t_testcase){"abC", "abc", 0};
	t[13] = (t_testcase){"abC", "abc", 1};
	t[14] = (t_testcase){"abC", "abc", 2};
	t[15] = (t_testcase){"abC", "abc", 3};
	t[16] = (t_testcase){"abC", "abc", 4};
	t[17] = (t_testcase){"ab", "abc", 0};
	t[18] = (t_testcase){"ab", "abc", 1};
	t[19] = (t_testcase){"ab", "abc", 2};
	t[20] = (t_testcase){"ab", "abc", 3};
	t[21] = (t_testcase){"ab", "abc", 4};
	t[22] = (t_testcase){"!@#", "$%*&", 0};
	t[23] = (t_testcase){"!@#", "$%*&", 1};
	char *s1 = malloc(20);
	assert(s1 != NULL);
	strcpy(s1, "abcdefghijk");
	char *s2 = malloc(20);
	assert(s2 != NULL);
	strcpy(s2, "abcdefghijiK");
	for (int i = 12; i < 20; i++)
	{
		s1[i] = 0;
		s2[i] = 0;
	}
	s1[5] = 0;
	s1[6] = 0;
	s1[11] = 0;
	s2[5] = 0;
	s2[6] = 0;
	t[24] = (t_testcase){s1, s2, 0};
	t[25] = (t_testcase){s1, s2, 5};
	t[26] = (t_testcase){s1, s2, 10};
	t[27] = (t_testcase){s1, s2, 11};
	t[28] = (t_testcase){s1, s2, 12};
	t[29] = (t_testcase){0, s2, 0};
	t[30] = (t_testcase){s1, 0, 0};
	t[31] = (t_testcase){0, 0, 0};
	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		printf("#%i\n", i);
		#endif
		int std = memcmp(
				t[i].s1
				, t[i].s2
				, t[i].n
				);
		int custom = ft_memcmp(
				t[i].s1
				, t[i].s2
				, t[i].n
				);
		#ifdef DEBUG
		printf("%i %i\n", std, custom);
		#endif
		assert(ft_sign_i(std) == ft_sign_i(custom));
	}
	free(s1);
	free(s2);
}
