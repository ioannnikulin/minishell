/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_print_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 10:45:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tests_internal.h"

#define START 0
#define SZ 1
//#define DEBUG

static void	catch(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stdout);
	*out = open(fname, O_RDWR|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stdout));
	assert (-1 != dup2(*out, fileno(stdout)));
}

static void	finally(int *out, int *save)
{
	fflush(stdout);
	close(*out);
	dup2(*save, fileno(stdout));
	close(*save);
}

typedef struct s_testcase
{
	char	***content;
	int		sz;
	char	*exp_res;
}	t_testcase;

int	ft_mapss_print_test(void)
{
	int out, save;
	remove("custom.tmp");
	t_testcase tests[SZ];
	char **a = ft_s2("a", "aaa");
	char **b = ft_s2("b", "");
	char **c = ft_s2("", "ccc");
	char ***t1 = ft_ss3(a, b, c);
	tests[0] = (t_testcase){t1, 3, "Map size: [3]\nkey: [], value: [ccc]\nkey: [a], value: [aaa]\nkey: [b], value: []\n"};

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
		catch("custom.tmp", &out, &save);
		ft_mapss_print(map);
		finally(&out, &save);
		int fc = open("custom.tmp", O_RDONLY, 0600);
		int len_exp = ft_strlen(tests[i].exp_res);
		char *act = ft_calloc(sizeof(char) * (len_exp * 2 + 1), 1);
		assert(act);
		int len_act = read(fc, act, len_exp * 2);
		assert(len_act == len_exp);
		int comp_res = ft_strcmp(tests[i].exp_res, act);
		#ifdef DEBUG
		if (comp_res)
			printf("expected:[%s] (%i symbols)\nactual:[%s] (%i symbols)\n", tests[i].exp_res, len_exp, act, len_act);
		#endif
		assert(comp_res == 0);
		free(act);
		ft_mapss_finalize_i(map, 0, 0);
		close(fc);
	}
	remove("custom.tmp");
	free(a);
	free(b);
	free(c);
	free(t1);
	return (0);
}
