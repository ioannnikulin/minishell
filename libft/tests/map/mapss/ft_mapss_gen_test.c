/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_gen_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 10:02:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tests_internal.h"

#define START 0
#define SZ 3
//#define DEBUG

typedef struct s_testcase
{
	char	***content;
	int		sz;
}	t_testcase;

// partially tested in ft_mapss_print_test, here it's only memleak check
void	ft_mapss_gen_test(void)
{
	t_testcase tests[SZ];
	char **a = ft_s2("a", "aaa");
	char **b = ft_s2("b", "");
	char **c = ft_s2("", "ccc");
	char **d = ft_s2("c", 0);
	char **e = ft_s2(0, "eee");
	char **f = ft_s2(0, 0);
	char ***t1 = ft_ss3(a, b, d);
	char ***t2 = ft_ss3(c, b, e);
	char ***t3 = ft_ss3(c, f, e);
	tests[0] = (t_testcase){t1, 3};
	tests[1] = (t_testcase){t2, 3};
	tests[2] = (t_testcase){t3, 3};

	#ifdef DEBUG
	printf("Starting %d tests.\n", SZ);
	#endif
	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		printf("%i\n", i);
		#endif
		t_mapss *map = ft_mapss_gen(tests[i].content, tests[i].sz);
		assert(!map);
	}
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	free(t1);
	free(t2);
	free(t3);
}
