/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_comparing_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:16:14 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 15:46:18 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e2e_internal.h"
#define PRINT_MALLOC_FAILURE_NO
#define TRAP_START 0

extern char **environ;

static void check_stderr(char *fname)
{
	FILE *file = fopen(fname, "r");
	assert(file);
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int no_leaks = 0;
	int fds_3 = 0, fds_5 = 0, inherited = 0, pipe = 0;

	while ((read = getline(&line, &len, file)) != -1) {
		//fprintf(stderr, "[echo]%s", line);
		if (strstr(line, "All heap blocks were freed -- no leaks are possible"))
			no_leaks = 1;
		// this is for local starts
		if (strstr(line, "FILE DESCRIPTORS: 3 open (3 std) at exit."))
			fds_3 = 1;
		// these three conditions are for github starts;
		// somehow github adds two file descriptors, but they are not marked as spawned in the program by pipe(),
		// so I think we can skip them, this is something technical about github
		if (strstr(line, "FILE DESCRIPTORS: 5 open (3 std) at exit."))
			fds_5 = 1;
		if (strstr(line, "<inherited from parent>"))
			inherited ++;
		if (strstr(line, "pipe.c"))
			pipe ++;
		if (no_leaks && (fds_3 || (fds_5 && inherited == 2 && pipe == 0)))
			break;
	}
	free(line);
	fclose(file);
	assert(no_leaks);
	assert(fds_3 || (fds_5 && inherited == 2 && pipe == 0));
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
    #ifdef FT_CALLOC_IF_TRAPPED
    int i;
    for (i = fsize - 2; i >= 0 && act[i] >= '0' && act[i] <= '9'; i --); // When started with traps, the output always ends in a number. Counter of callocs. Here I navigate fron the end of file to the last non-digit to find the start of this number to parse it out.
    char *sub = ft_substr(act, i, fsize - i);
    int mallocs = ft_atoi(sub, 0);
    free(sub);
    free(act);
    return (mallocs);
    #else
    return (0);
    #endif
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
	char *tmp = ft_strjoin_multi_free_outer(ft_s5(ft_s4("bash -c 'cd e2e_f && valgrind --leak-check=full --show-leak-kinds=all --child-silent-after-fork=yes --track-fds=yes -s ./minishell --trap", s_trap, "--command \"", cmd), "\"' 1>test.stdout 2>test.stderr"), 5, " ");
	free(s_trap);
	assert(!!tmp);
	system(tmp);
	free(tmp);
	check_stderr("test.stderr");
	return (0);
}

void	successful_execution(t_testcase *test, int *mallocs)
{
	system("rm -rf e2e_f testf && rm -f e2e.stdout e2e.stderr");
	assert(system("mkdir e2e_f") == 0);
	assert(system("cp minishell e2e_f/minishell") == 0);
	#ifdef DEBUG
	fprintf(stderr, "executing [%s]\n", test->cmd);
	#endif
	int	ret = t_execve(test->cmd);
	#ifdef DEBUG
    if (test->exp_ret == UNSTABLE_RETURN_0_1)
        fprintf(stderr, "expecting return 0 or 1, got %i\n", ret);
    else
        fprintf(stderr, "expecting return %i, got %i\n", test->exp_ret, ret);
    #endif
    assert(test->exp_ret == UNSTABLE_RETURN_0_1 || ret == test->exp_ret);
    assert(test->exp_ret != UNSTABLE_RETURN_0_1 || (ret == 0 || ret == 1));
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
void	malloc_failure_recoveries(char *cmd, int mallocs, int from_mallocs)
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
