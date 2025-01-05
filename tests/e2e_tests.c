/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:57:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/28 15:51:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#define START 0
#define TRAP_START 0
//#define DEBUG
#define SZ 22
#define PRINT_MALLOC_FAILURE_NO
#define PRINT_TEST_NO

typedef struct s_testcase
{
	char	*cmd;
	t_mapss	*exp;
}	t_testcase;

static void	catch(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stdout);
	*out = open(fname, O_WRONLY|O_APPEND|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stdout));
	assert (-1 != dup2(*out, fileno(stdout)));
}

#ifdef FT_CALLOC_IF_TRAPPED
static void	catch_err(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stderr);
	*out = open(fname, O_WRONLY|O_APPEND|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stderr));
	assert (-1 != dup2(*out, fileno(stderr)));
}
#endif

static void	finally(int *out, int *save)
{
	fflush(stdout);
	close(*out);
	dup2(*save, fileno(stdout));
	close(*save);
}

#ifdef FT_CALLOC_IF_TRAPPED
static void	finally_err(int *out, int *save)
{
	fflush(stderr);
	close(*out);
	dup2(*save, fileno(stderr));
	close(*save);
}
#endif

static int	file_compare(char *exp_content, char *act_fname)
{
	#ifdef DEBUG
	fprintf(stderr, "comparing files\n");
	fflush(stderr);
	fprintf(stderr, "expected [%p]\n", exp_content);
	fflush(stderr);
	fprintf(stderr, "expected [%s]\n", exp_content);
	fflush(stderr);
	fprintf(stderr, "actual fname [%s]\n", act_fname);
	fflush(stderr);
	#endif
	FILE *f = fopen(act_fname, "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	char *act = ft_calloc(sizeof(char), fsize + 1);
	assert(act);
	fread(act, fsize, 1, f);
	act[fsize] = 0;
	fclose(f);

	regex_t re;
	char	*exp_re = ft_strjoin(exp_content, "(Total ft_calloc_calls: [0-9]*\n)?");
	assert(exp_re);
	assert(regcomp(&re, exp_re, REG_EXTENDED | REG_NOSUB) == 0);
	int comp_res = regexec(&re, act, 0, NULL, 0);
	#ifdef DEBUG
	int	diff = -1;
	for (int i = 0; i < fsize; i ++)
		if (act[i] != exp_re[i])
		{
			diff = i;
			break ;
		}
	ft_printf("comparison result %i, expected:{{%s}}\nactual:{{%s}}\nstrncmp %i\nstart to differ from index %i\n", comp_res, exp_re, act, ft_strncmp(exp_content, act, fsize), diff); // a strcmp giving not 0 is possible, since the actual result should be matched to regexp, not strcompared to it. Regexps contain special characters in most cases, hence direct comparison will fail. Hence strcmp result is not asserted to be 0 only regcomp is asseted. This output is for my reference.
	fflush(stdout);
	#endif
	assert(comp_res == 0);
	free(exp_re);
	int i;
	for (i = fsize - 2; act[i] >= '0' && act[i] <= '9'; i --); // When started with traps, the output always ends in a number. Counter of callocs. Here I navigate fron the end of file to the last non-digit to find the start of this number to parse it out.
	char *sub = ft_substr(act, i, fsize - i);
	int mallocs = ft_atoi(sub, 0);
	free(sub);
	free(act);
	return (mallocs);
}

static void	successful_execution(t_testcase *test, int *mallocs)
{
	int out, save;
	system("(rm -r e2e_f testf && rm e2e.stdout e2e.stderr) 2> /dev/null");
	assert(system("mkdir e2e_f") == 0);
	assert(system("cp minishell e2e_f/minishell") == 0);
	catch("e2e.stdout", &out, &save);
	char *tmp = ft_strjoin("./e2e_f/minishell ", test->cmd);
	assert(!!tmp);
	#ifdef DEBUG
	fprintf(stderr, "executing [%s]\n", tmp);
	#endif
	assert(system(tmp) == 0);
	finally(&out, &save);
	*mallocs = file_compare(ft_mapss_get(test->exp, "stdout"), "e2e.stdout");
	t_dlist	*entry;
	char	*key;
	entry = test->exp->head;
	while (entry)
	{
		key = ((t_mapss_entry *)entry->content)->key;
		free(tmp);
		tmp = ft_strjoin("e2e_f/", key);
		assert(!!tmp);
		if (ft_strcmp(key, "stdout") != 0)
			file_compare(((t_mapss_entry *)entry->content)->value, tmp);
		entry = entry->next;
		// TODO: assure no more files except mentioned in the map
	}
	free(tmp);
}

#ifdef FT_CALLOC_IF_TRAPPED
static void	malloc_failure_recoveries(char *cmd, int mallocs, int from_mallocs)
{
	if (!cmd) return ;
	int out, save, outerr, saveerr;
	if (from_mallocs < TRAP_START) from_mallocs = TRAP_START;
	for (int i = from_mallocs; i < mallocs + 2; i ++)
	{
		system("(rm -r e2e_f testf && rm e2e.stdout e2e.stderr) 2> /dev/null");
		assert(system("mkdir e2e_f") == 0);
		assert(system("cp minishell e2e_f/minishell") == 0);
		#ifdef PRINT_MALLOC_FAILURE_NO
		printf("\t == %i == \n", i);
		#endif
		char *is = ft_itoa(i);
		char *tmp = ft_strjoin_multi_free_outer(ft_s3("cd e2e_f && valgrind --leak-check=full --show-leak-kinds=all --child-silent-after-fork=yes -s -q ./minishell --trap", is, cmd), 3, " ");
		free(is);
		assert(!!tmp);
		catch("e2e.stdout", &out, &save);
		catch_err("e2e.stderr", &outerr, &saveerr);
		system(tmp);
		finally(&out, &save);
		finally_err(&outerr, &saveerr);
		char *err = ft_calloc(sizeof(char *), 256);
		int fd = open("e2e.stderr", O_RDONLY, 0600);
		read(fd, err, 256);
		int i = 0;
		// expected output
	  	// ==130278== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: ... from ...)
		// so we navigate to first colon and check if there is a zero after it
		// (suppressed are the messages from readline and regexp, which are not ours)
		while (err[i] != ':' && i < 256) i ++;
		assert(i < 256 && err[i + 1] == ' ' && err[i + 2] == '0' && err[i + 3] == ' ');
		// TODO: check no files were created
		free(tmp);
		free(err);
		close(fd);
	}
	system("(rm -r e2e_f && rm e2e.stdout e2e.stderr) 2> /dev/null");
}
#endif

int	e2e_tests(void)
{
	t_testcase tests[SZ];
	t_mapss	*m[SZ];
	for (int i = 0; i < SZ; i ++ )
	{
		m[i]= ft_mapss_init();
		assert(!!m[i]);
	}
	t_mapss *empty_m = ft_mapss_init();
	assert(!!empty_m);
	ft_mapss_add(empty_m, "stdout", "exit");
	t_testcase empty_test = (t_testcase){"--command \"exit\"", empty_m};
	ft_mapss_add(m[0], "stdout", "hello world\n");
	ft_mapss_add(m[1], "stdout", "1   2 3\n");
	ft_mapss_add(m[2], "stdout", "1\n11\nf1\n");
	ft_mapss_add(m[3], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[4], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[5], "stdout", "1\n3\n4\n");
	ft_mapss_add(m[6], "stdout", "Linux\n");
	ft_mapss_add(m[7], "stdout", "HOME=/home/ioann\nsome=BODYONCETOLDME\nPATH=/usr/local/bin:/usr/sbin:/usr/bin:/sbin/bin\nPWD=/[^\n]*\none\ntwo   three\nfour\n");
	ft_mapss_add(m[9], "stdout", "HOME=/home/ioann\nfoo=zah\nsome=BODYONCETOLDME\nPATH=/usr/local/bin:/usr/sbin:/usr/bin:/sbin/bin\nPWD=/[^\n]*\none\ntwo   three\nfour\n");
	ft_mapss_add(m[10], "stdout", "/[^\n]*\n");
	ft_mapss_add(m[11], "stdout", "/[^\n]*/testf\n");
	ft_mapss_add(m[12], "stdout", "(/[^\n]*\n){2}");
	ft_mapss_add(m[13], "stdout", "/usr/bin\n");
	ft_mapss_add(m[14], "stdout", "cd: /nope: No such file or directory\n");
	ft_mapss_add(m[15], "stdout", "[^\n]*\ncd: nope: No such file or directory\n");
	ft_mapss_add(m[16], "stdout", "HOME=/home/ioann\nsome=BODYONCETOLDME\nPATH=/usr/local/bin:/usr/sbin:/usr/bin:/sbin/bin\nsome=BODYONCETOLDME\n");
	ft_mapss_add(m[17], "stdout", "1\nexit\n");
	ft_mapss_add(m[18], "stdout", "1\nexit\n");
	ft_mapss_add(m[19], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[20], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[21], "stdout", "1\n");
	ft_mapss_add(m[22], "stdout", "1\n6\n");
	ft_mapss_add(m[23], "stdout", "\\[bar\\] \\[\\$sea\\] \\[\\] \\[\\] \\[\\] \\[\\] \\[\\$\\] \\[/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin/bin\\] \\[BODYONCETOLDME\\]\n");
	ft_mapss_add(m[24], "stdout", "\\$\\(echo \"\\$\\(echo \"\\$\\(echo \"bla\")\")\")\n");
	ft_mapss_add(m[25], "stdout", "1 2");
	ft_mapss_add(m[26], "stdout", "1 -n 2\n3\n");
	ft_mapss_add(m[27], "stdout", "minishell: cd: too many arguments\n");
	tests[0] = (t_testcase){"echo hello world", m[0]};
	tests[1] = (t_testcase){"echo \"1   2\"   3", m[1]};
	tests[2] = (t_testcase){"rm -rf testf && mkdir testf && cd testf && mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -h | grep 1", m[2]};
	//tests[2] = (t_testcase){"--command mkdir testf && cd testf && mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -fh -c | grep 1 >> out.txt", m[2]};
	tests[3] = (t_testcase){"echo 1 || echo 2 && echo 3 && echo 4 || echo 5 && echo 6", m[3]};
	tests[4] = (t_testcase){"echo 1 || echo 2 && (echo 3 && echo 4 || echo 5 && echo 6)", m[4]};
	tests[5] = (t_testcase){"echo 1 || echo 2 && (echo 3 && echo 4 || (echo 5 && echo 6))", m[5]};
	tests[6] = (t_testcase){"uname", m[6]};
	tests[7] = (t_testcase){"pwd", m[7]};
	tests[8] = (t_testcase){"mkdir testf && cd testf && pwd", m[8]};
	tests[9] = (t_testcase){"pwd && mkdir testf && cd ./testf/.. && pwd", m[9]};
	tests[10] = (t_testcase){"cd /bin && pwd", m[10]};
	tests[11] = (t_testcase){"cd /nope && pwd", m[11]};
	tests[12] = (t_testcase){"cd && pwd && cd nope && pwd", m[12]};
	tests[13] = (t_testcase){"echo 1 && exit && echo 2", m[13]};
	tests[14] = (t_testcase){"echo 1 && exit || echo 2", m[14]};
	tests[15] = (t_testcase){"echo 1 || echo 2 && (echo 3 && (echo 4 || echo 5) && echo 6)", m[15]};
	tests[16] = (t_testcase){"echo 1 || echo 2 && (echo 3 && (echo 4) || echo 5 && echo 6)", m[16]};
	tests[17] = (t_testcase){"echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5 && echo 6))", m[17]};
	tests[18] = (t_testcase){"echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5)) && echo 6", m[18]};
	tests[19] = (t_testcase){"export foo=bar sea=$foo say=echo _1=$_1 && $say [$foo] ['$sea'] [\"$sea\"] [$food] [$_1] [$] [$some]", m[19]};
	tests[20] = (t_testcase){"echo '$(echo \"$(echo \"$(echo \"bla\")\")\")'", m[20]};
	tests[21] = (t_testcase){"echo -nn 1 2", m[21]};
	tests[22] = (t_testcase){"echo 1 -n 2&&echo 3||echo 4   ||echo 5 ||   echo 6", m[22]};
	tests[23] = (t_testcase){"cd a b && echo 1", m[23]};
	// multiple pipes (see mocks 29-30) will not be tested here, they produce strange errors in this testing suite, though they run normally when being started as separate commands. something to do with STDOUT being intercepted for tests probably.
	
	int	empty_call_mallocs = 0;
	successful_execution(&empty_test, &empty_call_mallocs);
	#ifdef FT_CALLOC_IF_TRAPPED
	malloc_failure_recoveries(empty_test.cmd, empty_call_mallocs, 0);
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
		#ifndef VANIA
		if (i == 12) // cd without arguments is 'go home'. mocked home /home/ioann only available for vania, so skipping everywhere else. can remove this when envvars will be actually read, not mocked.
		{
			ft_mapss_finalize_i(m[i], 0, 0);
			continue ;
		}
	  	#endif
		int mallocs;
		successful_execution(&tests[i], &mallocs);
		#ifdef FT_CALLOC_IF_TRAPPED
		malloc_failure_recoveries(tests[i].cmd, mallocs, empty_call_mallocs);
		#endif
		ft_mapss_finalize_i(m[i], 0, 0);
	}
	system("(rm -r e2e_f && rm e2e.stdout e2e.stderr) 2> /dev/null");
	return (0);
}
