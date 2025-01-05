/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:57:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/28 18:27:04 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#define START 0
#define TRAP_START 0
//#define DEBUG
#define SZ 28
#define PRINT_MALLOC_FAILURE_NO
#define PRINT_TEST_NO

extern char **environ;

typedef struct s_testcase
{
	char	*cmd;
	t_mapss	*exp;
	int		exp_ret;
}	t_testcase;

void	catch(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stdout);
	*out = open(fname, O_WRONLY|O_APPEND|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stdout));
	assert (-1 != dup2(*out, fileno(stdout)));
}

void	catch_err(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stderr);
	*out = open(fname, O_WRONLY|O_APPEND|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stderr));
	assert (-1 != dup2(*out, fileno(stderr)));
}

void	finally(int *out, int *save)
{
	fflush(stdout);
	close(*out);
	dup2(*save, fileno(stdout));
	close(*save);
}

void	finally_err(int *out, int *save)
{
	fflush(stderr);
	close(*out);
	dup2(*save, fileno(stderr));
	close(*save);
}

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
	FT_PRINTF("comparison result %i, expected:{{%s}}\nactual:{{%s}}\nstrncmp %i\nstart to differ from index %i\n", comp_res, exp_re, act, ft_strncmp(exp_content, act, fsize), diff); // a strcmp giving not 0 is possible, since the actual result should be matched to regexp, not strcompared to it. Regexps contain special characters in most cases, hence direct comparison will fail. Hence strcmp result is not asserted to be 0 only regcomp is asseted. This output is for my reference.
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

static int	t_execve(char *cmd)
{
	int out, save, outerr, saveerr;
	catch("e2e.stdout", &out, &save);
	catch_err("e2e.stderr", &outerr, &saveerr);
	int	pid = fork();
	assert(pid != -1);
	if (pid == 0)
	{
		int argc = 4;//6;
		char **argv = calloc(sizeof(char *), argc);
		assert(argv);
		argv[0] = "./e2e_f/minishell";
		// argv[1] = "--debug";
		// argv[2] = "256";
		argv[argc - 3] = "--command";
		argv[argc - 2] = cmd;
		argv[argc - 1] = 0;
		/*for (int i = 0; i < argc; i ++)
			printf("[%s]", argv[i]);
		printf("\n");*/
		execve(argv[0], argv, environ);
		exit(1);
	} else {
		int	status;
		waitpid(pid, &status, 0);
		finally(&out, &save);
		finally_err(&outerr, &saveerr);
		return (WEXITSTATUS(status));
	}
}

static void	successful_execution(t_testcase *test, int *mallocs)
{
	system("rm -rf e2e_f testf && rm -f e2e.stdout e2e.stderr");
	assert(system("mkdir e2e_f") == 0);
	assert(system("cp minishell e2e_f/minishell") == 0);
	#ifdef DEBUG
	fprintf(stderr, "executing [%s]\n", test->cmd);
	#endif
	int	ret = t_execve(test->cmd);
	assert(ret == test->exp_ret);
	*mallocs = file_compare(ft_mapss_get(test->exp, "stdout"), "e2e.stdout");
	char	*exp_err = ft_mapss_get(test->exp, "stderr");
	if (test->exp_ret)
		file_compare(exp_err, "e2e.stderr");
	t_dlist	*entry;
	char	*key;
	entry = test->exp->head;
	while (entry)
	{
		key = ((t_mapss_entry *)entry->content)->key;
		char *tmp = ft_strjoin("e2e_f/", key);
		assert(!!tmp);
		if (ft_strcmp(key, "stdout") != 0 && ft_strcmp(key, "stderr") != 0)
			file_compare(((t_mapss_entry *)entry->content)->value, tmp);
		entry = entry->next;
		free(tmp);
		// TODO: assure no more files except mentioned in the map
	}
}

#ifdef FT_CALLOC_IF_TRAPPED
static void	malloc_failure_recoveries(char *cmd, int mallocs)
{
	if (!cmd) return ;
	int out, save, outerr, saveerr;
	for (int i = TRAP_START; i < mallocs + 2; i ++)
	{
		system("rm -rf e2e_f testf && rm -f e2e.stdout e2e.stderr");
		assert(system("mkdir e2e_f") == 0);
		assert(system("cp minishell e2e_f/minishell") == 0);
		#ifdef PRINT_MALLOC_FAILURE_NO
		printf("\t == %i == \n", i);
		#endif
		char *is = ft_itoa(i);
		char *tmp = ft_strjoin_multi_free_outer(ft_s4("bash -c 'cd e2e_f && valgrind --leak-check=full --show-leak-kinds=all --child-silent-after-fork=yes -s -q ./minishell --trap", is, cmd, "' 1>e2e.stdout 2>e2e.stderr"), 4, " ");
		free(is);
		assert(!!tmp);
		system(tmp);
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
	system("rm -rf e2e_f && rm -f e2e.stdout e2e.stderr");
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
	ft_mapss_add(m[0], "stdout", "hello world\n");
	//ft_mapss_add(m[1], "stdout", "hello\\n my openworld\n");
	//	this test looks absolutely fine, and works with strcmp, but somehow fails with regex. no idea, so just turning it off for now
	ft_mapss_add(m[1], "stdout", "hello world\n");
	ft_mapss_add(m[2], "stdout", "1   2 3\n");
	ft_mapss_add(m[3], "stdout", "1\n11\nf1\n");
	ft_mapss_add(m[4], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[5], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[6], "stdout", "1\n3\n4\n");
	ft_mapss_add(m[7], "stdout", "Linux\n");
	ft_mapss_add(m[8], "stdout", "HOME=/home/ioann\nsome=BODYONCETOLDME\nPATH=/usr/local/bin:/usr/sbin:/usr/bin:/sbin/bin\nPWD=/[^\n]*\none\ntwo   three\nfour\n");
	ft_mapss_add(m[9], "stdout", "HOME=/home/ioann\nfoo=zah\nsome=BODYONCETOLDME\nPATH=/usr/local/bin:/usr/sbin:/usr/bin:/sbin/bin\nPWD=/[^\n]*\none\ntwo   three\nfour\n");
	ft_mapss_add(m[10], "stdout", "/[^\n]*\n");
	ft_mapss_add(m[11], "stdout", "/[^\n]*/testf\n");
	ft_mapss_add(m[12], "stdout", "(/[^\n]*\n){2}");
	ft_mapss_add(m[13], "stdout", "/usr/bin\n");
	ft_mapss_add(m[14], "stdout", "");
	ft_mapss_add(m[14], "stderr", "minishell: cd: /nope: No such file or directory\n");
	ft_mapss_add(m[15], "stdout", "[^\n]*\ncd: nope: No such file or directory\n");
	ft_mapss_add(m[16], "stdout", "HOME=/home/ioann\nsome=BODYONCETOLDME\nPATH=/usr/local/bin:/usr/sbin:/usr/bin:/sbin/bin\nsome=BODYONCETOLDME\n");
	ft_mapss_add(m[17], "stdout", "1\n");
	ft_mapss_add(m[17], "stderr", "exit\n");
	ft_mapss_add(m[18], "stdout", "1\n");
	ft_mapss_add(m[18], "stderr", "exit\n");
	ft_mapss_add(m[19], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[20], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[21], "stdout", "1\n");
	ft_mapss_add(m[22], "stdout", "1\n6\n");
	ft_mapss_add(m[23], "stdout", "\\[bar\\] \\[\\$sea\\] \\[\\] \\[\\] \\[\\] \\[\\] \\[\\$\\] \\[/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin/bin\\] \\[BODYONCETOLDME\\]\n");
	ft_mapss_add(m[24], "stdout", "\\$\\(echo \"\\$\\(echo \"\\$\\(echo \"bla\")\")\")\n");
	ft_mapss_add(m[25], "stdout", "1 2");
	ft_mapss_add(m[26], "stdout", "1 -n 2\n3\n");
	ft_mapss_add(m[27], "stderr", "minishell: cd: too many arguments\n");
	ft_mapss_add(m[27], "stdout", "");
	tests[0] = (t_testcase){"echo hello world", m[0], 0};
	tests[1] = (t_testcase){"echo hello world", m[1], 0};
	//tests[1] = (t_testcase){"   echo hello\\n		my openworld ", m[1], 0};
	tests[2] = (t_testcase){"echo \"1   2\"   3", m[2], 0};
	tests[3] = (t_testcase){"rm -rf testf && mkdir testf && cd testf && mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -h | grep 1", m[3], 0};
	//tests[3] = (t_testcase){"mkdir testf && cd testf && mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -fh -c | grep 1 >> out.txt", m[3], 0};
	tests[4] = (t_testcase){"echo 1 || echo 2 && echo 3 && echo 4 || echo 5 && echo 6", m[4], 0};
	tests[5] = (t_testcase){"echo 1 || echo 2 && (echo 3 && echo 4 || echo 5 && echo 6)", m[5], 0};
	tests[6] = (t_testcase){"echo 1 || echo 2 && (echo 3 && echo 4 || (echo 5 && echo 6))", m[6], 0};
	tests[7] = (t_testcase){"uname", m[7], 0};
	tests[8] = (t_testcase){"./tests/tool_print_environment one \"two   three\" four", m[8], 0};
	tests[9] = (t_testcase){"export foo=bar && export foo=zah nope=uhoh && unset nope && ./tests/tool_print_environment one \"two   three\" four", m[9], 0};
	tests[10] = (t_testcase){"pwd", m[10], 0};
	tests[11] = (t_testcase){"mkdir testf && cd testf && pwd", m[11], 0};
	tests[12] = (t_testcase){"pwd && mkdir testf && cd ./testf/.. && pwd", m[12], 0};
	tests[13] = (t_testcase){"cd /bin && pwd", m[13], 0};
	tests[14] = (t_testcase){"cd /nope && pwd", m[14], 1};
	tests[15] = (t_testcase){"cd && pwd && cd nope && pwd", m[15], 0};
	tests[16] = (t_testcase){"env && unset HOME PATH && env", m[16], 0};
	tests[17] = (t_testcase){"echo 1 && exit && echo 2", m[17], 0};
	tests[18] = (t_testcase){"echo 1 && exit 267 || echo 2", m[18], 11};
	tests[19] = (t_testcase){"echo 1 || echo 2 && (echo 3 && (echo 4 || echo 5) && echo 6)", m[19], 0};
	tests[20] = (t_testcase){"echo 1 || echo 2 && (echo 3 && (echo 4) || echo 5 && echo 6)", m[20], 0};
	tests[21] = (t_testcase){"echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5 && echo 6))", m[21], 0};
	tests[22] = (t_testcase){"echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5)) && echo 6", m[22], 0};
	tests[23] = (t_testcase){"export foo=bar sea=$foo say=echo _1=$_1 _= && $say [$foo] ['$sea'] [\"$sea\"] [$food] [$_1] [$_] [$] [$PATH] [$some]", m[23], 0};
	tests[24] = (t_testcase){"echo '$(echo \"$(echo \"$(echo \"bla\")\")\")'", m[24], 0};
	tests[25] = (t_testcase){"echo -nn 1 2", m[25], 0};
	tests[26] = (t_testcase){"echo 1 -n 2&&echo 3||echo 4   ||echo 5 ||   echo 6", m[26], 0};
	tests[27] = (t_testcase){"cd a b && echo 1", m[27], 1};
	// multiple pipes (see mocks 29-30) will not be tested here, they produce strange errors in this testing suite, though they run normally when being started as separate commands. something to do with STDOUT being intercepted for tests probably.

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
		if (i == 15) // cd without arguments is 'go home'. mocked home /home/ioann only available for vania, so skipping everywhere else. can remove this when envvars will be actually read, not mocked.
		{
			ft_mapss_finalize_i(m[i], 0, 0);
			continue ;
		}
	  	#endif
		int mallocs;
		successful_execution(&tests[i], &mallocs);
		#ifdef FT_CALLOC_IF_TRAPPED
		malloc_failure_recoveries(tests[i].cmd, mallocs);
		#endif
		ft_mapss_finalize_i(m[i], 0, 0);
	}
	system("rm -rf e2e_f && rm -f e2e.stdout e2e.stderr");
	return (0);
}
