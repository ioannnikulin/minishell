/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:40:54 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/18 15:03:42 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
//#define DEBUG

typedef struct s_testcase
{
	char	what[20];
	char	(*f)(unsigned int, char);
	char	*res;
	char	nullify;
}	t_testcase;

#define SZ 11

static char	a(unsigned int idx, char c)
{
	if (idx % 2 == 0)
		return '_';
	return (c - 1);
}

static char	b(unsigned int idx, char c)
{
	(void)idx;
	if (ft_isalpha(c))
		return ('a');
	if (ft_isdigit(c))
		return ('0');
	if (ft_isspace(c))
		return (' ');
	return ('.');
}

void	ft_strmapi_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"abc", a, "_a_", 0}; 
	t[1] = (t_testcase){"", a, "", 0}; 
	t[2] = (t_testcase){"@!@#723gfd\t\n", a, "_ _\"_1_f_c_\t", 0}; 
	t[3] = (t_testcase){"i\x7F\x01r", a, "_\x7E_q", 0}; 
	t[4] = (t_testcase){"abc", b, "aaa", 0}; 
	t[5] = (t_testcase){"", b, "", 0}; 
	t[6] = (t_testcase){"@!@#723gfd\t\n", b, "....000aaa  ", 0}; 
	t[7] = (t_testcase){"i\x7F\x01r", b, "a..a", 0}; 
	t[8] = (t_testcase){"abc", a, "", 1}; 
	t[9] = (t_testcase){"abc", a, "abc", 2}; 
	t[10] = (t_testcase){"abc", a, "", 3}; 
	for (int i = 0; i < SZ; i ++)
	{
		char *res = ft_strmapi(
				((t[i].nullify & 1) > 0 ? NULL : t[i].what)
				, ((t[i].nullify & 2) > 0 ? NULL : t[i].f)
				);
		#ifdef DEBUG
		printf("%i %p %p\n", i, &res, t[i].res);
		if (!res && !t[i].res)
			printf("[%s][%s]\n", res, t[i].res);
		#endif
		assert((res == t[i].res && !res) || strcmp(res, t[i].res) == 0);
		free(res);
	}
}
