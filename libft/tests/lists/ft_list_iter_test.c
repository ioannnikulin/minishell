/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:40:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 12:06:12 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "tests.h"
//#define DEBUG

#define SZ 5

static void	a(void *c)
{
	char *cc;

	cc = c;
	int f = open("tmp.tst", O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (f == -1)
		assert(file_not_created(0));
	while (*cc)
	{
		write(f, cc++, 1);
	}
	write(f, "\n", 1);
	close(f);
}

typedef struct	s_testcase
{
	int	end_to;
	char	*texts[20];
}	t_testcase;

void	ft_list_iter_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){-1, {"abc", "def", "gh", NULL}};
	t[1] = (t_testcase){0, {"abc", "def", "gh", NULL}};
	t[2] = (t_testcase){1, {"abc", "def", "gh", NULL}};
	t[3] = (t_testcase){2, {"abc", "def", "gh", NULL}};
	t[4] = (t_testcase){-1, {NULL}};
	for (int i = 0; i < SZ; i ++)
	{
	#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
	#endif
		int rm = remove("tmp.tst");
		assert(i == 0 || rm == 0);
		t_list *root = ft_list_generate(t[i].texts, t[i].end_to);
		ft_list_iter(root, a);
		int f = open("tmp.tst", O_RDONLY);
		if (!t[i].texts[0] && !root && f == -1)
			continue;
		if (f == -1)
			assert(file_not_created(0));
		char rdbuf[200];
		int sz = read(f, rdbuf, 200);
		char *check = ft_strjoin(t[i].texts[0], "\n");
		for (int j = 1; t[i].texts[j]; j ++)
		{
			char *ncheck = ft_strjoin(check, t[i].texts[j]);
			free(check);
			check = ncheck;
			ncheck = ft_strjoin(check, "\n");
			free(check);
			check = ncheck;
		}
		#ifdef DEBUG
		printf("%i [%s] [%s]\n", sz, rdbuf, check);
		#endif
		assert(sz >= 0);
		int orig_sz = ft_strlen(check);
		assert(sz == orig_sz);
		assert(strncmp(rdbuf, check, orig_sz) == 0);
		close(f);
	}
	remove("tmp.tst");
}
