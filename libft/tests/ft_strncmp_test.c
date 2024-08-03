/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 15:37:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_testcase
{
	char	*s1;
	char	*s2;
	size_t	n;
	char	nullify;
}	t_testcase;

# define SZ 27

void	ft_strncmp_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"abc", "abC", 0, 0};
	t[1] = (t_testcase){"abc", "abC", 1, 0};
	t[2] = (t_testcase){"abc", "abC", 2, 0};
	t[3] = (t_testcase){"abc", "abC", 3, 0};
	t[4] = (t_testcase){"abc", "abC", 4, 0};
	t[5] = (t_testcase){"abc", "ab", 0, 0};
	t[6] = (t_testcase){"abc", "ab", 1, 0};
	t[7] = (t_testcase){"abc", "ab", 2, 0};
	t[8] = (t_testcase){"abc", "ab", 3, 0};
	t[9] = (t_testcase){"abc", "ab", 4, 0};
	t[10] = (t_testcase){"", "", 0, 0};
	t[11] = (t_testcase){"", "", 1, 0};
	t[12] = (t_testcase){"abC", "abc", 0, 0};
	t[13] = (t_testcase){"abC", "abc", 1, 0};
	t[14] = (t_testcase){"abC", "abc", 2, 0};
	t[15] = (t_testcase){"abC", "abc", 3, 0};
	t[16] = (t_testcase){"abC", "abc", 4, 0};
	t[17] = (t_testcase){"ab", "abc", 0, 0};
	t[18] = (t_testcase){"ab", "abc", 1, 0};
	t[19] = (t_testcase){"ab", "abc", 2, 0};
	t[20] = (t_testcase){"ab", "abc", 3, 0};
	t[21] = (t_testcase){"ab", "abc", 4, 0};
	t[22] = (t_testcase){"!@#", "$%*&", 0, 0};
	t[23] = (t_testcase){"!@#", "$%*&", 1, 0};
	t[24] = (t_testcase){"!@#", "$%*&", 0, 1};
	t[25] = (t_testcase){"!@#", "$%*&", 0, 2};
	t[26] = (t_testcase){"!@#", "$%*&", 0, 3};
	for (int i = 0; i < SZ; i ++)
	{
		int std = strncmp(
				((t[i].nullify & 1) > 0 ? NULL : t[i].s1)
				, ((t[i].nullify & 2) > 0 ? NULL : t[i].s2)
				, t[i].n
				);
		int custom = ft_strncmp(
				((t[i].nullify & 1) > 0 ? NULL : t[i].s1)
				, ((t[i].nullify & 2) > 0 ? NULL : t[i].s2)
				, t[i].n
				);
		//printf("!%i %i %i\n\n", i, std, custom);
		assert(std == custom);
	}
}
