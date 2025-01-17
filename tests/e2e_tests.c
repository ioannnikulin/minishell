/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:57:54 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 23:52:40 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e2e_internal.h"
#define START 0
#define DEBUG
#define SZ 34
#define PRINT_TEST_NO
#define MAX_CHECKED_MALLOCS_PRELIM 200
// if preliminary shell start (with exit) gives 500, 
// only 0-200 (empty run) + 500-... (actual commands) will be trapped -
// assuming 300 go to envvars, and there's no need to check ALL of them

t_testcase tests[SZ];
t_testcase empty_test;
t_mapss	*m[SZ];
t_mapss *empty_m;

int	e2e_tests(void)
{
	populate();
	
	int	empty_call_mallocs = 0;
	#ifdef PRINT_TEST_NO
	printf("\t ======== preliminary empty start ======== \n");
	#endif
	successful_execution(&empty_test, &empty_call_mallocs);
	#ifdef FT_CALLOC_IF_TRAPPED
	if (empty_test.check_mallocs)
		malloc_failure_recoveries(empty_test.cmd, (empty_call_mallocs > MAX_CHECKED_MALLOCS_PRELIM ? MAX_CHECKED_MALLOCS_PRELIM : empty_call_mallocs), 0);
	#endif
	ft_mapss_finalize_i(empty_m, 0, 0);
	for (int i = 0; i < START; i ++)
	{
		ft_mapss_finalize_i(m[i], 0, 0);
	}
	for (int i = START; i < SZ; i ++)
	{
		#ifdef PRINT_TEST_NO
		printf("\t ======== %i ======== \n", i);
		#endif
		#ifndef HOME_FOLDER_AVAILABLE_NOT_GITHUB
		if (i == 12)
		{
			ft_mapss_finalize_i(m[i], 0, 0);
			continue ;
		}
	  	#endif
		int mallocs;
		successful_execution(&tests[i], &mallocs);
		#ifdef FT_CALLOC_IF_TRAPPED
		if (tests[i].check_mallocs)
			malloc_failure_recoveries(tests[i].cmd, mallocs, empty_call_mallocs);
		#endif
		ft_mapss_finalize_i(m[i], 0, 0);
	}
	system("rm -rf e2e_f && rm -f e2e.stdout e2e.stderr");
	return (0);
}

int	populate(void)
{
	for (int i = 0; i < SZ; i ++ )
	{
		m[i] = ft_mapss_init();
		assert(!!m[i]);
	}
	empty_m = ft_mapss_init();
	assert(!!empty_m);
	ft_mapss_add(empty_m, "stdout", "");
	ft_mapss_add(empty_m, "stderr", "exit");
	empty_test = (t_testcase){"exit", empty_m, 0, 1};

	ft_mapss_add(m[0], "stdout", "hello world\n");
	tests[0] = (t_testcase){"echo hello world", m[0], 0, 0};

	ft_mapss_add(m[1], "stdout", "1   2 3\n");
	tests[1] = (t_testcase){"echo \"1   2\"   3", m[1], 0, 0};

	ft_mapss_add(m[2], "stdout", "");
	ft_mapss_add(m[2], "testf/out.txt", "1\n11\nf1\n");
	tests[2] = (t_testcase){"rm -rf testf && mkdir testf && cd testf && mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -h | grep 1 >> out.txt", m[2], 0, 1};

	ft_mapss_add(m[3], "stdout", "1\n3\n4\n6\n");
	tests[3] = (t_testcase){"echo 1 || echo 2 && echo 3 && echo 4 || echo 5 && echo 6", m[3], 0, 0};

	ft_mapss_add(m[4], "stdout", "1\n3\n4\n6\n");
	tests[4] = (t_testcase){"echo 1 || echo 2 && (echo 3 && echo 4 || echo 5 && echo 6)", m[4], 0, 0};

	ft_mapss_add(m[5], "stdout", "1\n3\n4\n");
	tests[5] = (t_testcase){"echo 1 || echo 2 && (echo 3 && echo 4 || (echo 5 && echo 6))", m[5], 0, 1};

	ft_mapss_add(m[6], "stdout", "Linux\n");
	tests[6] = (t_testcase){"uname", m[6], 0, 0};

	ft_mapss_add(m[7], "stdout", "/[^\n]*\n");
	tests[7] = (t_testcase){"pwd", m[7], 0, 0};

	ft_mapss_add(m[8], "stdout", "/[^\n]*/testf\n");
	tests[8] = (t_testcase){"mkdir testf && cd testf && pwd", m[8], 0, 0};

	ft_mapss_add(m[9], "stdout", "(/[^\n]*\n){2}");
	tests[9] = (t_testcase){"pwd && mkdir testf && cd ./testf/.. && pwd", m[9], 0, 1};

	ft_mapss_add(m[10], "stdout", "/usr/bin\n");
	tests[10] = (t_testcase){"cd /bin && pwd", m[10], 0, 1};

	ft_mapss_add(m[11], "stdout", "");
	ft_mapss_add(m[11], "stderr", "cd: /nope: No such file or directory\n");
	tests[11] = (t_testcase){"cd /nope && pwd", m[11], 1, 1};

	ft_mapss_add(m[12], "stdout", "/home/.*");
	tests[12] = (t_testcase){"cd && pwd && cd nope && pwd", m[12], 1, 1};

	ft_mapss_add(m[13], "stdout", "1\n");
	ft_mapss_add(m[13], "stderr", "exit\n");
	tests[13] = (t_testcase){"echo 1 && exit 300 && echo 2", m[13], 44, 1};

	ft_mapss_add(m[14], "stdout", "1\n");
	ft_mapss_add(m[14], "stderr", "exit\n");
	tests[14] = (t_testcase){"echo 1 && exit || echo 2", m[14], 0, 0};

	ft_mapss_add(m[15], "stdout", "1\n3\n4\n6\n");
	tests[15] = (t_testcase){"echo 1 || echo 2 && (echo 3 && (echo 4 || echo 5) && echo 6)", m[15], 0, 0};

	ft_mapss_add(m[16], "stdout", "1\n3\n4\n6\n");
	tests[16] = (t_testcase){"echo 1 || echo 2 && (echo 3 && (echo 4) || echo 5 && echo 6)", m[16], 0, 0};

	ft_mapss_add(m[17], "stdout", "1\n");
	tests[17] = (t_testcase){"echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5 && echo 6))", m[17], 0, 0};

	ft_mapss_add(m[18], "stdout", "1\n6\n");
	tests[18] = (t_testcase){"echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5)) && echo 6", m[18], 0, 0};

	ft_mapss_add(m[19], "stdout", "\\[bar\\] \\[\\$sea\\] \\[\\] \\[\\] \\[\\] \\[\\$\\]\n");
	tests[19] = (t_testcase){"export foo=bar sea=$foo say=echo _1=$_1 && $say [$foo] ['$sea'] [\"$sea\"] [$food] [$_1] [$]", m[19], 0, 1};

	ft_mapss_add(m[20], "stdout", "\\$\\(echo \"\\$\\(echo \"\\$\\(echo \"bla\")\")\")\n");
	tests[20] = (t_testcase){"echo '$(echo \"$(echo \"$(echo \"bla\")\")\")'", m[20], 0, 0};

	ft_mapss_add(m[21], "stdout", "1 2");
	tests[21] = (t_testcase){"echo -nn 1 2", m[21], 0, 0};

	ft_mapss_add(m[22], "stdout", "1 -n 2\n3\n");
	tests[22] = (t_testcase){"echo 1 -n 2&&echo 3||echo 4   ||echo 5 ||   echo 6", m[22], 0, 0};

	ft_mapss_add(m[23], "stderr", "minishell: cd: too many arguments\n");
	ft_mapss_add(m[23], "stdout", "");
	tests[23] = (t_testcase){"cd a b && echo 1", m[23], 1, 1};

	ft_mapss_add(m[24], "stdout", "      1       3      24");
	tests[24] = (t_testcase){"echo 1 | wc | wc", m[24], 0, 1};

	ft_mapss_add(m[25], "stdout", "");
	ft_mapss_add(m[25], "out.txt", "1\n");
	tests[25] = (t_testcase){"rm -f out.txt && echo 1 > out.txt", m[25], 0, 0};

	ft_mapss_add(m[26], "stdout", "");
	ft_mapss_add(m[26], "out.txt", "1\n");
	tests[26] = (t_testcase){"rm -f out.txt && echo 1 >> out.txt", m[26], 0, 1};

	ft_mapss_add(m[27], "stdout", "");
	ft_mapss_add(m[27], "out.txt", "2\n");
	tests[27] = (t_testcase){"rm -f out.txt && echo 1 > out.txt && echo 2 > out.txt", m[27], 0, 0};

	ft_mapss_add(m[28], "stdout", "");
	ft_mapss_add(m[28], "out.txt", "1\n2\n");
	tests[28] = (t_testcase){"rm -f out.txt && echo 1 >> out.txt && echo 2 >> out.txt", m[28], 0, 0};

	ft_mapss_add(m[29], "stdout", "1");
	ft_mapss_add(m[29], "one.txt", "1");
	tests[29] = (t_testcase){"rm -f one.txt && echo 1 > one.txt && cat < one.txt", m[29], 0, 1};

	ft_mapss_add(m[30], "stdout", "");
	ft_mapss_add(m[30], "one.txt", "1");
	ft_mapss_add(m[30], "stderr", "minishell: two.txt: No such file or directory\n");
	tests[30] = (t_testcase){"rm -f one.txt two.txt && echo 1 > one.txt && cat < two.txt < one.txt", m[30], 1, 0};

	ft_mapss_add(m[31], "stdout", "1");
	ft_mapss_add(m[31], "one.txt", "1\n2\n");
	tests[31] = (t_testcase){"rm -f one.txt && echo 1 >> one.txt && echo 2 >> one.txt && cat < one.txt | grep 1", m[31], 0, 0};

	ft_mapss_add(m[32], "stdout", "");
	ft_mapss_add(m[32], "one.txt", "1\n2\n");
	ft_mapss_add(m[32], "two.txt", "2\n");
	tests[32] = (t_testcase){"rm -f one.txt two.txt && echo 1 >> one.txt && echo 2 >> one.txt && cat < one.txt | grep 2 > two.txt", m[32], 0, 0};

	ft_mapss_add(m[33], "stdout", "");
	ft_mapss_add(m[33], "one.txt", "1\n2\n");
	ft_mapss_add(m[33], "two.txt", "2\n");
	tests[33] = (t_testcase){"rm -f one.txt two.txt && echo 1 >> one.txt && echo 2 >> one.txt && cat < one.txt | grep 2 > two.txt | grep 2", m[33], 0, 0};

	return (0);
}