/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_del_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/27 01:59:48 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tests_internal.h"

#define START 0
#define SZ 15
//#define DEBUG

typedef struct s_testcase
{
	char	***src_content;
	int		src_sz;
	char	*key;
	char	***exp_content;
	int		exp_sz;
	int		exp_ret;
}	t_testcase;

void	ft_mapss_del_test(void)
{
	t_testcase tests[SZ];
	char **b = ft_s2("b", "bbb");
	char **d = ft_s2("d", "ddd");
	char ***t1 = ft_ss2(b, d);
	char ***t2 = &b;
	char ***t3 = 0;
	tests[0] = (t_testcase){t1, 2, "a", t1, 2, 1};
	tests[1] = (t_testcase){t1, 2, "b", &d, 1, 0};
	tests[2] = (t_testcase){t1, 2, "c", t1, 2, 1};
	tests[3] = (t_testcase){t1, 2, "d", &b, 1, 0};
	tests[4] = (t_testcase){t1, 2, "e", t1, 2, 1};
	tests[5] = (t_testcase){t1, 2, "", t1, 2, 1};
	tests[6] = (t_testcase){t1, 2, 0, t1, 2, 2};
	tests[7] = (t_testcase){t2, 1, "a", t2, 1, 1};
	tests[8] = (t_testcase){t2, 1, "b", t3, 0, 0};
	tests[9] = (t_testcase){t2, 1, "c", t2, 1, 1};
	tests[10] = (t_testcase){t2, 1, "", t2, 1, 1};
	tests[11] = (t_testcase){t2, 1, 0, t2, 1, 2};
	tests[12] = (t_testcase){t3, 0, "a", t3, 0, 1};
	tests[13] = (t_testcase){t3, 0, "", t3, 0, 1};
	tests[14] = (t_testcase){t3, 0, 0, t3, 0, 2};

	#ifdef DEBUG
	printf("Starting %d tests.\n", SZ);
	#endif
	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		printf("%i\n", i);
		#endif
		t_mapss *act = ft_mapss_gen(tests[i].src_content, tests[i].src_sz);
		assert(act);
		t_mapss *exp = ft_mapss_gen(tests[i].exp_content, tests[i].exp_sz);
		assert(exp);
		int act_ret = ft_mapss_del(act, tests[i].key);
		assert(tests[i].exp_ret == act_ret);
		assert(tests[i].exp_sz == act->size);
		assert(ft_mapss_ncmp(exp, act, act->size) == 0);
		ft_mapss_finalize_i(exp, 0, 0);
		ft_mapss_finalize_i(act, 0, 0);
	}
	assert(ft_mapss_del(0, "a") == 2);
	free(b);
	free(d);
	free(t1);
}
