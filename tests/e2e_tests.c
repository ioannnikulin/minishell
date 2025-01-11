/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@stiudent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:57:54 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/11 20:22:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#define START 0
#define TRAP_START 0
//#define DEBUG
#define SZ 25
#define PRINT_MALLOC_FAILURE_NO
#define PRINT_TEST_NO

extern char **environ;

typedef struct s_testcase
{
	char	*cmd;
	t_mapss	*exp;
	int		exp_ret;
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

static void finally(int *out, int *save)
{
	fflush(stdout);
	close(*out);
	dup2(*save, fileno(stdout));
	close(*save);
}

static void check_stderr(char *fname)
{
	FILE *file = fopen(fname, "r");
	assert(file);
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int found_text1 = 0;
	int found_text2 = 0;

	while ((read = getline(&line, &len, file)) != -1) {
		printf("%s", line);
		if (strstr(line, "All heap blocks were freed -- no leaks are possible")) {
			found_text1 = 1;
		}
		if (strstr(line, "FILE DESCRIPTORS: 3 open (3 std) at exit.")) {
			found_text2 = 1;
		}
		if (found_text1 && found_text2) {
			break;
		}
	}
	free(line);
	fclose(file);
	assert(found_text1 && "leaks detected");
	assert(found_text2 && "open file descriptors detected");
}

static void finally_err(int *out, int *save)
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
	char *act = calloc(fsize + 1, sizeof(char));
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

static int	valgrind(char *cmd, int trap)
{
	system("rm -rf e2e_f testf && rm -f e2e.stdout e2e.stderr test.stdout test.stderr");
	assert(system("mkdir e2e_f") == 0);
	assert(system("cp minishell e2e_f/minishell") == 0);
	char *s_trap = ft_itoa(trap);
	assert(!!s_trap);
	char *tmp = ft_strjoin_multi_free_outer(ft_s5(ft_s4("bash -c 'cd e2e_f && valgrind --leak-check=full --show-leak-kinds=all --child-silent-after-fork=yes --track-fds=yes -s ./minishell --trap", s_trap, "--command", cmd), "' 1>test.stdout 2>test.stderr"), 5, " ");
	free(s_trap);
	assert(!!tmp);
	system(tmp);
	free(tmp);
	check_stderr("test.stderr");
	return (0);
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
	valgrind(test->cmd, -1);
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
static void	malloc_failure_recoveries(char *cmd, int mallocs, int from_mallocs)
{
	if (!cmd) return ;
	if (from_mallocs < TRAP_START) from_mallocs = TRAP_START;
	for (int i = from_mallocs; i < mallocs + 2; i ++)
	{
		system("rm -rf e2e_f testf && rm -f e2e.stdout e2e.stderr");
		assert(system("mkdir e2e_f") == 0);
		assert(system("cp minishell e2e_f/minishell") == 0);
		#ifdef PRINT_MALLOC_FAILURE_NO
		printf("\t == %i == \n", i);
		#endif
		valgrind(cmd, i);	
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
	t_mapss *empty_m = ft_mapss_init();
	assert(!!empty_m);
	ft_mapss_add(empty_m, "stdout", "");
	ft_mapss_add(empty_m, "stderr", "exit");
	t_testcase empty_test = (t_testcase){"exit", empty_m, 0};
	ft_mapss_add(m[0], "stdout", "hello world\n");
	ft_mapss_add(m[1], "stdout", "1   2 3\n");
	ft_mapss_add(m[2], "stdout", "1\n11\nf1\n");
	ft_mapss_add(m[3], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[4], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[5], "stdout", "1\n3\n4\n");
	ft_mapss_add(m[6], "stdout", "Linux\n");
	ft_mapss_add(m[7], "stdout", "/[^\n]*\n");
	ft_mapss_add(m[8], "stdout", "/[^\n]*/testf\n");
	ft_mapss_add(m[9], "stdout", "(/[^\n]*\n){2}");
	ft_mapss_add(m[10], "stdout", "/usr/bin\n");
	ft_mapss_add(m[11], "stdout", "");
	ft_mapss_add(m[11], "stderr", "cd: /nope: No such file or directory\n");
	ft_mapss_add(m[12], "stdout", "/home/.*");
	ft_mapss_add(m[13], "stdout", "1\n");
	ft_mapss_add(m[13], "stderr", "exit\n");
	ft_mapss_add(m[14], "stdout", "1\n");
	ft_mapss_add(m[14], "stderr", "exit\n");
	ft_mapss_add(m[15], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[16], "stdout", "1\n3\n4\n6\n");
	ft_mapss_add(m[17], "stdout", "1\n");
	ft_mapss_add(m[18], "stdout", "1\n6\n");
	ft_mapss_add(m[19], "stdout", "\\[bar\\] \\[\\$sea\\] \\[\\] \\[\\] \\[\\] \\[\\$\\]\n");
	ft_mapss_add(m[20], "stdout", "\\$\\(echo \"\\$\\(echo \"\\$\\(echo \"bla\")\")\")\n");
	ft_mapss_add(m[21], "stdout", "1 2");
	ft_mapss_add(m[22], "stdout", "1 -n 2\n3\n");
	ft_mapss_add(m[23], "stderr", "minishell: cd: too many arguments\n");
	ft_mapss_add(m[23], "stdout", "");
	ft_mapss_add(m[24], "stdout", "      1       3      24");
	tests[0] = (t_testcase){"echo hello world", m[0], 0};
	tests[1] = (t_testcase){"echo \"1   2\"   3", m[1], 0};
	tests[2] = (t_testcase){"rm -rf testf && mkdir testf && cd testf && mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -h | grep 1", m[2], 0};
	//tests[2] = (t_testcase){"--command mkdir testf && cd testf && mkdir f1 f2 && touch 1 && touch 11 2 && ls -a -fh -c | grep 1 >> out.txt", m[2], 0};
	tests[3] = (t_testcase){"echo 1 || echo 2 && echo 3 && echo 4 || echo 5 && echo 6", m[3], 0};
	tests[4] = (t_testcase){"echo 1 || echo 2 && (echo 3 && echo 4 || echo 5 && echo 6)", m[4], 0};
	tests[5] = (t_testcase){"echo 1 || echo 2 && (echo 3 && echo 4 || (echo 5 && echo 6))", m[5], 0};
	tests[6] = (t_testcase){"uname", m[6], 0};
	tests[7] = (t_testcase){"pwd", m[7], 0};
	tests[8] = (t_testcase){"mkdir testf && cd testf && pwd", m[8], 0};
	tests[9] = (t_testcase){"pwd && mkdir testf && cd ./testf/.. && pwd", m[9], 0};
	tests[10] = (t_testcase){"cd /bin && pwd", m[10], 0};
	tests[11] = (t_testcase){"cd /nope && pwd", m[11], 1};
	tests[12] = (t_testcase){"cd && pwd && cd nope && pwd", m[12], 1};
	tests[13] = (t_testcase){"echo 1 && exit 300 && echo 2", m[13], 44};
	tests[14] = (t_testcase){"echo 1 && exit || echo 2", m[14], 0};
	tests[15] = (t_testcase){"echo 1 || echo 2 && (echo 3 && (echo 4 || echo 5) && echo 6)", m[15], 0};
	tests[16] = (t_testcase){"echo 1 || echo 2 && (echo 3 && (echo 4) || echo 5 && echo 6)", m[16], 0};
	tests[17] = (t_testcase){"echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5 && echo 6))", m[17], 0};
	tests[18] = (t_testcase){"echo 1 || (echo 2 && (echo 3 && (echo 4) || echo 5)) && echo 6", m[18], 0};
	tests[19] = (t_testcase){"export foo=bar sea=$foo say=echo _1=$_1 && $say [$foo] ['$sea'] [\"$sea\"] [$food] [$_1] [$]", m[19], 0};
	tests[20] = (t_testcase){"echo '$(echo \"$(echo \"$(echo \"bla\")\")\")'", m[20], 0};
	tests[21] = (t_testcase){"echo -nn 1 2", m[21], 0};
	tests[22] = (t_testcase){"echo 1 -n 2&&echo 3||echo 4   ||echo 5 ||   echo 6", m[22], 0};
	tests[23] = (t_testcase){"cd a b && echo 1", m[23], 1};
	tests[24] = (t_testcase){"echo 1 | wc | wc", m[24], 0};
	// multiple pipes (see mocks 29-30) will not be tested here, they produce strange errors in this testing suite, though they run normally when being started as separate commands. something to do with STDOUT being intercepted for tests probably.
	
	int	empty_call_mallocs = 0;
	#ifdef PRINT_TEST_NO
	printf("\t ======== preliminary empty start ======== \n");
	#endif
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
		malloc_failure_recoveries(tests[i].cmd, mallocs, empty_call_mallocs);
		#endif
		ft_mapss_finalize_i(m[i], 0, 0);
	}
	system("rm -rf e2e_f && rm -f e2e.stdout e2e.stderr");
	return (0);
}
