/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 12:06:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 14
//#define DEBUG

typedef struct s_testcase
{
	int	end_to;
	void	*(*f)(void*);
	void	(*del)(void*);
	char	*texts[20];
	char	*res[20];
}	t_testcase;

static void	*a(void *oc)
{
	return (ft_strdup((char*)oc));
}

static void	*b(void *oc)
{
	if (ft_isdigit(((char*)oc)[0]))
		return (ft_strdup("0"));
	if (ft_isalpha(((char*)oc)[0]))
		return (ft_strdup("a"));
	return (ft_strdup("."));
}

void	ft_list_map_test(void)
{
	t_testcase	t[SZ];
	t[0] = (t_testcase){-1, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[1] = (t_testcase){0, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[2] = (t_testcase){1, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[3] = (t_testcase){2, a, free, {"hello", "i", "", NULL}, {"hello", "i", "", NULL}};
	t[4] = (t_testcase){-1, a, free, {"hello", NULL}, {"hello", NULL}};
	t[5] = (t_testcase){0, a, free, {"hello", NULL}, {"hello", NULL}};
	t[6] = (t_testcase){-1, a, free, {NULL}, {NULL}};
	t[7] = (t_testcase){-1, b, free, {"hello", "1", "", NULL}, {"a", "0", ".", NULL}};
	t[8] = (t_testcase){0, b, free, {"hello", "2", "", NULL}, {"a", "0", ".", NULL}};
	t[9] = (t_testcase){1, b, free, {"hello", "3", "", NULL}, {"a", "0", ".", NULL}};
	t[10] = (t_testcase){2, b, free, {"hello", "4", "", NULL}, {"a", "0", ".", NULL}};
	t[11] = (t_testcase){-1, b, free, {"hello", NULL}, {"a", NULL}};
	t[12] = (t_testcase){0, b, free, {"hello", NULL}, {"a", NULL}};
	t[13] = (t_testcase){-1, b, free, {NULL}, {NULL}};
	for (int i = 0; i <  SZ; i ++)
	{
#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
#endif
		t_list *src = ft_list_generate(t[i].texts, t[i].end_to);
		t_list *n = ft_list_map(src, t[i].f, t[i].del);
		t_list *loop_start = NULL;
#ifdef DEBUG
		ft_list__print(src);
		ft_list__print(n);
#endif
		for (int j = 0; t[i].res[j] != NULL; j ++)
		{
#ifdef DEBUG
			printf("\t%i [%s] [%s]\n", j, (char*)n->content, t[i].res[j]);
#endif
			assert(n);
			assert(strcmp(n->content, t[i].res[j]) == 0);
			if (t[i].end_to == j)
				loop_start = n;
			n = n->next;
		}
		assert((t[i].end_to == -1 && !n) || (t[i].end_to > -1 && n == loop_start));
		ft_list_clear(&src, free);
		ft_list_clear(&n, free);
	}
}
