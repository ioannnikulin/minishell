/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:58:05 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 17:29:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
//#define DEBUG

typedef struct	s_testcase
{
	char		*s1;
	char		*s2;
	char		*res;
}	t_testcase;

#define SZ 10

void	ft_strjoin_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"", "", ""};
	t[1] = (t_testcase){"", "i", "i"};
	t[2] = (t_testcase){"", "ii", "ii"};
	t[3] = (t_testcase){"i", "", "i"};
	t[4] = (t_testcase){"ii", "", "ii"};
	t[5] = (t_testcase){"i", "i", "ii"};
	t[6] = (t_testcase){"i", "q", "iq"};
	t[7] = (t_testcase){"abcdefgh", "qwertyuio", "abcdefghqwertyuio"};
	char s[10] = "abcdefgh";
	s[3] = 0;
	t[8] = (t_testcase){s, "qwertyuio", "abcqwertyuio"};
	t[9] = (t_testcase){"abcdefgh", s, "abcdefghabc"};
	for (int i = 0; i < SZ; i ++)
	{
		char * res = ft_strjoin(t[i].s1, t[i].s2);
		#ifdef DEBUG
			printf("%i [%s] [%s] -> [%s] %lu ([%s] %lu)\n", i, t[i].s1, t[i].s2, res, strlen(res), t[i].res, strlen(t[i].res));
		#endif
		assert(strcmp(res, t[i].res) == 0);
		free(res);
	}
}
