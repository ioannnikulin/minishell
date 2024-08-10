/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 14:08:27 by inikulin         ###   ########.fr       */
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

#define SZ 26

void	ft_strnstr_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"abc", "ab", 0};
	t[1] = (t_testcase){"abc", "ab", 1};
	t[2] = (t_testcase){"abc", "ab", 2};
	t[3] = (t_testcase){"abc", "abc", 2};
	t[4] = (t_testcase){"abc", "abc", 3};
	t[5] = (t_testcase){"abc", "abc", 4};
	t[6] = (t_testcase){"abcd", "cd", 0};
	t[7] = (t_testcase){"abcd", "cd", 1};
	t[8] = (t_testcase){"abcd", "cd", 2};
	t[9] = (t_testcase){"abcd", "cd", 3};
	t[10] = (t_testcase){"abcd", "cd", 4};
	t[11] = (t_testcase){"abcd", "cd", 5};
	t[12] = (t_testcase){"abc", "", 0};
	t[13] = (t_testcase){"abc", "", 1};
	t[14] = (t_testcase){"abc", "", 2};
	t[15] = (t_testcase){"", "", 0};
	t[16] = (t_testcase){"", "", 1};
	t[17] = (t_testcase){"", "a", 0};
	t[18] = (t_testcase){"", "a", 1};
	t[19] = (t_testcase){"abcdef", "abcdefg", 0};
	t[20] = (t_testcase){"abcdef", "abcdefg", 6};
	t[21] = (t_testcase){"abcdef", "abcdefg", 7};
	char s[20] = "abcabcabcabcdabcd";
	s[10] = 0;
	t[22] = (t_testcase){s, "abcd", 15};
	t[23] = (t_testcase){s, "abcd", 16};
	t[24] = (t_testcase){s, "abcd", 17};
	t[25] = (t_testcase){"aaab", "aab", 17};
	for (int i = 0; i < SZ; i ++)
	{
		#ifdef DEBUG
			printf("%i : ", i);
			fflush(stdout);
		#endif
		char *std = strnstr(
				t[i].s1
				, t[i].s2
				, t[i].n
				);
		#ifdef DEBUG
			printf("%p ", std);
			fflush(stdout);
		#endif
		char *custom = ft_strnstr(
				t[i].s1
				, t[i].s2
				, t[i].n
				);
		#ifdef DEBUG
			printf("%p\n\n", custom);
		#endif
		assert(std == custom);
	}
}
