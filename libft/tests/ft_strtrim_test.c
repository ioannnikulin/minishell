/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/18 12:13:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
//#define DEBUG

typedef struct s_testcase
{
	char	*what;
	char	*totrim;
	char	*res;
}	t_testcase;

#define SZ 7

void	ft_strtrim_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"abc", "ab", "c"};
	t[1] = (t_testcase){"abc", "abc", ""};
	t[2] = (t_testcase){"abacabadabacaba", "ab", "cabadabac"};
	t[3] = (t_testcase){"abacabadabacaba", "abac", "d"};
	t[4] = (t_testcase){"", "", ""};
	t[5] = (t_testcase){" cc  c", " ", "cc  c"};
	t[6] = (t_testcase){"cc  c  c   ", "  ", "cc  c  c"};
	for (int i = 0; i < SZ; i ++)
	{
		char *res = ft_strtrim(t[i].what, t[i].totrim);
		#ifdef DEBUG
		printf("%i [%s][%s]\n", i, res, t[i].res);
		#endif
		assert(strcmp(res, t[i].res) == 0);
		free(res);
	}
}
