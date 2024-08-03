/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/13 20:18:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
//#define DEBUG

typedef struct s_testcase
{
	char	what[20];
	void	(*f)(unsigned int, char *);
	char	*res;
	char	nullify;
}	t_testcase;

#define SZ 11

static void	a(unsigned int idx, char *c)
{
	if (idx % 2 == 0)
		*c = '_';
	else
		*c = (*c) - 1;
}

static void	b(unsigned int idx, char *c)
{
	(void)idx;
	if (ft_isalpha(*c))
		*c = 'a';
	else if (ft_isdigit(*c))
		*c = '0';
	else if (ft_isspace(*c))
		*c = ' ';
	else
		*c = '.';
}

void	ft_striteri_test(void)
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
	t[8] = (t_testcase){"abc", a, 0, 1};
	t[9] = (t_testcase){"abc", a, "abc", 2};
	t[10] = (t_testcase){"abc", a, 0, 3};
	for (int i = 0; i < SZ; i ++)
	{
		char *what = ((t[i].nullify & 1) > 0 ? NULL : t[i].what);
		void (*f)(unsigned int, char *) = ((t[i].nullify & 2) > 0 ? NULL : t[i].f);
		ft_striteri(what, f);
		#ifdef DEBUG
		printf("%i %p %p\n", i, what, t[i].res);
		if (what != NULL && (char *)t[i].res != NULL)
			printf("[%s][%s]\n", what, t[i].res);
		#endif
		if (what == (char *)t[i].res && what == NULL)
			continue;
		assert(what && (char *)t[i].res);
		assert(strcmp(what, t[i].res) == 0);
	}
}
