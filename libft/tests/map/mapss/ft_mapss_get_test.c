/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_get_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/27 01:04:19 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tests_internal.h"

#define START 0
#define SZ 15
//#define DEBUG

typedef struct s_testcase
{
	char	***content;
	int		sz;
	char	*key;
	char	*exp_val;
}	t_testcase;

void	ft_mapss_get_test(void)
{
	t_testcase tests[SZ];
	char **b = ft_s2("b", "bbb");
	char **d = ft_s2("d", "ddd");
	char ***t1 = ft_ss2(b, d);
	char ***t2 = &b;
	char ***t3 = 0;
	tests[0] = (t_testcase){t1, 2, "a", 0};
	tests[1] = (t_testcase){t1, 2, "b", "bbb"};
	tests[2] = (t_testcase){t1, 2, "c", 0};
	tests[3] = (t_testcase){t1, 2, "d", "ddd"};
	tests[4] = (t_testcase){t1, 2, "e", 0};
	tests[5] = (t_testcase){t1, 2, "", 0};
	tests[6] = (t_testcase){t1, 2, 0, 0};
	tests[7] = (t_testcase){t2, 1, "a", 0};
	tests[8] = (t_testcase){t2, 1, "b", "bbb"};
	tests[9] = (t_testcase){t2, 1, "c", 0};
	tests[10] = (t_testcase){t2, 1, "", 0};
	tests[11] = (t_testcase){t2, 1, 0, 0};
	tests[12] = (t_testcase){t3, 0, "a", 0};
	tests[13] = (t_testcase){t3, 0, "", 0};
	tests[14] = (t_testcase){t3, 0, 0, 0};

	#ifdef DEBUG
	printf("Starting %d tests.\n", SZ);
	#endif
	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		printf("%i\n", i);
		#endif
		t_mapss *map = ft_mapss_gen(tests[i].content, tests[i].sz);
		assert(map);
		if (tests[i].sz == 0 || tests[i].content == NULL)
			assert(map->head == NULL && map->size == 0);
		char *act_val = ft_mapss_get(map, tests[i].key);
		assert((act_val == 0) == (tests[i].exp_val == 0));
		if (tests[i].exp_val)
			assert(ft_strcmp(tests[i].exp_val, act_val) == 0);
		ft_mapss_finalize_i(map, 0, 0);
	}
	free(b);
	free(d);
	free(t1);
}
