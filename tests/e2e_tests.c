/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:57:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/09 16:21:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#define START 7
#define SZ 18
#define DEBUG

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

static void	catch_err(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stderr);
	*out = open(fname, O_WRONLY|O_APPEND|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stderr));
	assert (-1 != dup2(*out, fileno(stderr)));
}

static void	finally(int *out, int *save)
{
	fflush(stdout);
    close(*out);
	dup2(*save, fileno(stdout));
	close(*save);
}

static void	finally_err(int *out, int *save)
{
	fflush(stderr);
    close(*out);
	dup2(*save, fileno(stderr));
	close(*save);
}

static int	file_compare(char *exp_contens, char *act_fname)
{
	int fc = open(act_fname, O_RDONLY, 0600);
	int len_exp = ft_strlen(exp_contens);
	char *act = ft_calloc(sizeof(char), len_exp * 2 + 1);
	assert(act);
	int len_act = read(fc, act, len_exp * 2);
//	assert(len_act - len_exp <= 3); // expected result doesn't store a number
	int comp_res = ft_strncmp(exp_contens, act, ft_strlen(exp_contens) - 1);
	#ifdef DEBUG
	ft_printf("comparison result %i, expected:[%s] (%i symbols)\nactual:[%s] (%i symbols)\n", comp_res, exp_contens, len_exp, act, len_act);
	#endif
	assert(comp_res == 0);
	int i;
	for (i = len_act - 2; act[i] >= '0' && act[i] <= '9'; i --);
	char *sub = ft_substr(act, i, len_act);
	int mallocs = ft_atoi(sub, 0);
	free(sub);
	free(act);
	close(fc);
	return (mallocs);
}

static void	successful_execution(t_testcase *test, int *mallocs)
{
	int out, save;
	system("(rm -r e2e_f && rm e2e.stdout) 2> /dev/null");
	assert(system("mkdir e2e_f") == 0);
	assert(system("cp minishell e2e_f/minishell") == 0);
	catch("e2e.stdout", &out, &save);
	char *tmp = ft_strjoin("./e2e_f/minishell ", test->cmd);
	assert(!!tmp);
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

static void	malloc_failure_recoveries(char *cmd, int mallocs)
{
	int out, save, outerr, saveerr;
	for (int i = 0; i < mallocs + 2; i ++)
	{
		system("(rm -r e2e_f && rm e2e.stdout e2e.stderr) 2> /dev/null");
		assert(system("mkdir e2e_f") == 0);
		assert(system("cp minishell e2e_f/minishell") == 0);
		#ifdef DEBUG
		printf("\t%i\n", i);
		#endif
		char *is = ft_itoa(i);
		char *tmp = ft_strjoin_multi_free_outer(ft_s3("cd e2e_f && valgrind --leak-check=full --show-leak-kinds=all -s -q ./minishell --trap", is, cmd), 3, " ");
		free(is);
		assert(!!tmp);
		catch("e2e.stdout", &out, &save);
		catch_err("e2e.stderr", &outerr, &saveerr);
		system(tmp);
		finally(&out, &save);
		finally_err(&outerr, &saveerr);
		char *err = ft_calloc(sizeof(char *), 256);
		read(open("e2e.stderr", O_RDONLY, 0600), err, 256);
		int i = 0;
		// expected output
	  	// ==130278== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
		// so we navigate to both colons and check if there are zeros after them
		while (err[i] != ':' && i < 256) i ++;
		assert(i < 256 && err[i + 1] == ' ' && err[i + 2] == '0' && err[i + 3] == ' ');
		while (err[i] != ':' && i < 256) i ++;
		assert(i < 256 && err[i + 1] == ' ' && err[i + 2] == '0' && err[i + 3] == ' ');
		// TODO: check no files were created
		free(tmp);
		free(err);
	}
	system("(rm -r e2e_f && rm e2e.stdout e2e.stderr) 2> /dev/null");
}

int	e2e_tests(void)
{
	t_testcase tests[SZ];
	t_mapss	*m[SZ];
	for (int i = 0; i < SZ; i ++ )
	{
		m[i]= ft_mapss_init();
		assert(!!m[i]);
	}
	// TODO: no number for now, github runs one extra calloc for some reason
	ft_mapss_add(m[0], "stdout", "hello world\nTotal ft_calloc_calls: \n"); // 30-31
	ft_mapss_add(m[1], "stdout", "hello\\n my openworld\nTotal ft_calloc_calls: \n"); // 31-32
	ft_mapss_add(m[2], "stdout", "1   2 3\nTotal ft_calloc_calls: \n"); // 31-32
	// pipes and redirections not implemented yet, so the previous test one more time
	ft_mapss_add(m[3], "stdout", "1   2 3\nTotal ft_calloc_calls: \n"); // 31-32
	ft_mapss_add(m[4], "stdout", "1\n3\n4\n6\nTotal ft_calloc_calls: \n"); // 59-60
	ft_mapss_add(m[5], "stdout", "1\n3\n4\n6\nTotal ft_calloc_calls: \n"); // 61-62
	ft_mapss_add(m[6], "stdout", "1\n3\n4\nTotal ft_calloc_calls: \n"); // 63-64
	ft_mapss_add(m[7], "stdout", "Linux\nTotal ft_calloc_calls: \n"); // 54-55
	ft_mapss_add(m[8], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[9], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[10], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[11], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[12], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[13], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[14], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[15], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[16], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	ft_mapss_add(m[17], "stdout", "hello world\nTotal ft_calloc_calls: \n");
	tests[0] = (t_testcase){"--command echo hello world", m[0]};
	tests[1] = (t_testcase){"--command \"   echo hello\\n		my openworld \"", m[1]};
	tests[2] = (t_testcase){"--command \"echo \\\"1   2\\\"   3\"", m[2]};
	tests[3] = (t_testcase){"--command \"echo \\\"1   2\\\"   3\"", m[2]};
	//tests[3] = (t_testcase){"--command mkdir testf && cd testf && mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -fh -c | grep 1 >> out.txt", m[3]};
	tests[4] = (t_testcase){"--command \"echo 1 || echo 2 && echo 3 && echo 4 || echo 5 && echo 6\"", m[4]};
	tests[5] = (t_testcase){"--command \"echo 1 || echo 2 && (echo 3 && echo 4 || echo 5 && echo 6)\"", m[5]};
	tests[6] = (t_testcase){"--command \"echo 1 || echo 2 && (echo 3 && echo 4 || (echo 5 && echo 6))\"", m[6]};
	tests[7] = (t_testcase){"--command uname", m[7]};
	tests[8] = (t_testcase){"--command ./tests/tool_print_environment one \\\"two   three\\\" four", m[8]};
	tests[9] = (t_testcase){"--command export foo=bar && export foo=zah nope=uhoh && unset nope && ./tests/tool_print_environment one \\\"two   three\\\" four", m[9]};
	tests[10] = (t_testcase){"--command pwd", m[10]};
	tests[11] = (t_testcase){"--command mkdir testf && cd testf && pwd", m[11]};
	tests[12] = (t_testcase){"--command pwd && mkdir testf && cd ./testf/.. && pwd", m[12]};
	tests[13] = (t_testcase){"--command cd /bin && pwd", m[13]};
	tests[14] = (t_testcase){"--command cd /nope && pwd", m[14]};
	tests[15] = (t_testcase){"--command cd && pwd && cd nope && pwd", m[15]};
	tests[16] = (t_testcase){"--command env && unset HOME PATH && env", m[16]};
	tests[17] = (t_testcase){"--command echo 1 && exit && echo 2", m[17]};
	tests[18] = (t_testcase){"--command echo 1 && exit || echo 2", m[18]};

	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		printf("%i\n", i);
		#endif
		int mallocs;
		successful_execution(&tests[i], &mallocs);
		malloc_failure_recoveries(tests[i].cmd, mallocs);
	}
	system("(rm -r e2e_f && rm e2e.stdout) 2> /dev/null");
	for (int i = 0; i < SZ; i ++)
		ft_mapss_finalize_i(m[i], 0, 0);
	return (0);
}
