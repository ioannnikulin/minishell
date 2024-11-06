/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:57:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 12:18:19 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#define START 0
#define SZ 1
//#define DEBUG

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

static void	finally(int *out, int *save)
{
	fflush(stdout);
    close(*out);
	dup2(*save, fileno(stdout));
	close(*out);
}

static void	file_compare(char *exp_contens, char *act_fname)
{
	int fc = open(act_fname, O_RDONLY, 0600);
	int len_exp = ft_strlen(exp_contens);
	char *act = ft_calloc(sizeof(char), len_exp * 2 + 1);
	assert(act);
	int len_act = read(fc, act, len_exp * 2);
	assert(len_act == len_exp);
	int comp_res = ft_strcmp(exp_contens, act);
	#ifdef DEBUG
	if (comp_res)
		printf("expected:[%s] (%i symbols)\nactual:[%s] (%i symbols)\n", exp_contens, len_exp, act, len_act);
	#endif
	assert(comp_res == 0);
	free(act);
	close(fc);
}

int	e2e_tests(void)
{
	int out, save;
	t_testcase tests[SZ];
	t_mapss	*m0 = ft_mapss_init();
	assert(!!m0);
	ft_mapss_add(m0, "stdout", "hello world\nTotal ft_calloc_calls: 30\n");
	tests[0] = (t_testcase){"./minishell --command echo hello world", m0};
	char	*tmp = 0;

	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		printf("%i\n", i);
		#endif
		system("(rm -r e2e_f && rm e2e.stdout) 2> /dev/null");
		assert(system("mkdir e2e_f") == 0);
		assert(system("cp minishell e2e_f/minishell") == 0);
		catch("e2e.stdout", &out, &save);
		free(tmp);
		tmp = ft_strjoin("./e2e_f/", tests[i].cmd);
		assert(!!tmp);
		assert(system(tmp) == 0);
		finally(&out, &save);
		file_compare(ft_mapss_get(tests[i].exp, "stdout"), "e2e.stdout");
		t_dlist	*entry;
		char	*key;
		entry = tests[i].exp->head;
		while (entry)
		{
			key = ((t_mapss_entry *)entry->content)->key;
			free(tmp);
			tmp = ft_strjoin("e2e_f/", key);
			assert(!!tmp);
			if (ft_strcmp(key, "stdout") != 0)
				file_compare(((t_mapss_entry *)entry->content)->value, tmp);
			entry = entry->next;
		}
	}
	system("(rm -r e2e_f && rm e2e.stdout) 2> /dev/null");
	free(tmp);
	ft_mapss_finalize_i(m0, 0, 0);
	return (0);
}
