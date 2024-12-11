/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_ncmp_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 06:04:44 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 11:42:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tests_internal.h"

typedef struct s_testcase
{
	char	***a_content;
	int		a_sz;
	char	***b_content;
	int		b_sz;
	int		ncmp;
	int		exp_cmp_res;
}	t_testcase;

#define START 0
#define SZ 14
//#define DEBUG

void	ft_mapss_ncmp_test(void)
{
	t_testcase	tests[SZ];
	char	**a00 = ft_s2("a", "aaa");
	char	**b00 = ft_s2("a", "aaa");
	char	**a01 = ft_s2("b", "bbb");
	char	**b01 = ft_s2("b", "bbb");
	char	**a10 = ft_s2("a", "aa");
	char	**b10 = ft_s2("a", "aaa");
	char	**a11 = ft_s2("b", "bbb");
	char	**b11 = ft_s2("b", "bbb");
	char	**a20 = ft_s2("a", "aaa");
	char	**b20 = ft_s2("a", "aa");
	char	**a21 = ft_s2("b", "bbb");
	char	**b21 = ft_s2("b", "bbb");
	char	**a30 = ft_s2("a", "aaa");
	char	**b30 = ft_s2("a", "aaa");
	char	**a31 = ft_s2("b", "bb");
	char	**b31 = ft_s2("b", "bbb");
	char	**a40 = ft_s2("a", "aaa");
	char	**b40 = ft_s2("a", "aaa");
	char	**a41 = ft_s2("b", "bbb");
	char	**b41 = ft_s2("b", "bb");
	char	**a50 = ft_s2("aa", "a");
	char	**b50 = ft_s2("aaa", "a");
	char	**a51 = ft_s2("bbb", "b");
	char	**b51 = ft_s2("bbb", "b");
	char	**a60 = ft_s2("aaa", "a");
	char	**b60 = ft_s2("aa", "a");
	char	**a61 = ft_s2("bbb", "b");
	char	**b61 = ft_s2("bbb", "b");
	char	**a70 = ft_s2("aaa", "a");
	char	**b70 = ft_s2("aaa", "a");
	char	**a71 = ft_s2("bb", "b");
	char	**b71 = ft_s2("bbb", "b");
	char	**a80 = ft_s2("aaa", "a");
	char	**b80 = ft_s2("aaa", "a");
	char	**a81 = ft_s2("bbb", "b");
	char	**b81 = ft_s2("bb", "b");
	char	***a0 = ft_ss2(a00, a01);
	char	***b0 = ft_ss2(b00, b01);
	char	***a1 = ft_ss2(a10, a11);
	char	***b1 = ft_ss2(b10, b11);
	char	***a2 = ft_ss2(a20, a21);
	char	***b2 = ft_ss2(b20, b21);
	char	***a3 = ft_ss2(a30, a31);
	char	***b3 = ft_ss2(b30, b31);
	char	***a4 = ft_ss2(a40, a41);
	char	***b4 = ft_ss2(b40, b41);
	char	***a5 = ft_ss2(a50, a51);
	char	***b5 = ft_ss2(b50, b51);
	char	***a6 = ft_ss2(a60, a61);
	char	***b6 = ft_ss2(b60, b61);
	char	***a7 = ft_ss2(a70, a71);
	char	***b7 = ft_ss2(b70, b71);
	char	***a8 = ft_ss2(a80, a81);
	char	***b8 = ft_ss2(b80, b81);
	tests[0] = (t_testcase){a0, 2, b0, 2, 3, 0};
	tests[1] = (t_testcase){a1, 2, b1, 2, 2, -1};
	tests[2] = (t_testcase){a2, 2, b2, 2, 2, 1};
	tests[3] = (t_testcase){a3, 2, b3, 2, 2, -2};
	tests[4] = (t_testcase){a4, 2, b4, 2, 2, 2};
	tests[5] = (t_testcase){a5, 2, b5, 2, 2, -1};
	tests[6] = (t_testcase){a6, 2, b6, 2, 2, 1};
	tests[7] = (t_testcase){a7, 2, b7, 2, 2, -2};
	tests[8] = (t_testcase){a8, 2, b8, 2, 2, 2};
	tests[9] = (t_testcase){&a00, 1, b0, 2, 2, -2};
	tests[10] = (t_testcase){a0, 2, &b00, 1, 2, 2};
	tests[11] = (t_testcase){a8, 2, b8, 2, 0, 0};
	tests[12] = (t_testcase){a8, 2, b8, 2, 1, 0};
	tests[13] = (t_testcase){a8, 2, b8, 2, 3, 2};

	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		printf("test %i:", i);
		#endif
		t_mapss	*a = ft_mapss_gen(tests[i].a_content, tests[i].a_sz);
		assert(a);
		t_mapss	*b = ft_mapss_gen(tests[i].b_content, tests[i].b_sz);
		assert(b);
		int act_res = ft_mapss_ncmp(a, b, tests[i].ncmp);
	  	#ifdef DEBUG
	  	printf("expected %i, got %i\n", tests[i].exp_cmp_res, act_res);
		#endif
		assert(act_res == tests[i].exp_cmp_res);
		ft_mapss_finalize_i(a, 0, 0);
		ft_mapss_finalize_i(b, 0, 0);
	}
	free(a00);
	free(b00);
	free(a01);
	free(b01);
	free(a10);
	free(b10);
	free(a11);
	free(b11);
	free(a20);
	free(b20);
	free(a21);
	free(b21);
	free(a30);
	free(b30);
	free(a31);
	free(b31);
	free(a40);
	free(b40);
	free(a41);
	free(b41);
	free(a50);
	free(b50);
	free(a51);
	free(b51);
	free(a60);
	free(b60);
	free(a61);
	free(b61);
	free(a70);
	free(b70);
	free(a71);
	free(b71);
	free(a80);
	free(b80);
	free(a81);
	free(b81);
	free(a0);
	free(b0);
	free(a1);
	free(b1);
	free(a2);
	free(b2);
	free(a3);
	free(b3);
	free(a4);
	free(b4);
	free(a5);
	free(b5);
	free(a6);
	free(b6);
	free(a7);
	free(b7);
	free(a8);
	free(b8);
}
