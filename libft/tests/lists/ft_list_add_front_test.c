/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 12:02:42 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 7 
//#define DEBUG

typedef struct s_testcase
{
	int	end_to;
	char	*newnode;
	char	*texts[20];
}	t_testcase;

void	ft_list_add_front_test(void)
{
	t_testcase	t[SZ];
	t[0] = (t_testcase){-1, "", {"hello", "i", "", NULL}};
	t[1] = (t_testcase){0, "5", {"hello", "i", "", NULL}};
	t[2] = (t_testcase){1, "q", {"hello", "i", "", NULL}};
	t[3] = (t_testcase){2, " ", {"hello", "i", "", NULL}};
	t[4] = (t_testcase){-1, "dd", {"hello", NULL}};
	t[5] = (t_testcase){-1, "segfault", {"hello", NULL}};
	t[6] = (t_testcase){-1, "only", {NULL}};
	for (int i = 0; i <  SZ; i ++)
	{
#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
#endif
		t_list *n = ft_list_generate(t[i].texts, t[i].end_to);
		ft_list_add_front(&n, ft_list_new(ft_strdup(t[i].newnode)));
#ifdef DEBUG
		printf("%p [%s] -> ", n, (char*)n->content);
		fflush(stdout);
#endif
		assert(n);
		assert(strcmp(n->content, t[i].newnode) == 0);
		t_list *root = n;
		n = n->next;
		t_list *loop_start = NULL;
		for (int j = 0; t[i].texts[j] != NULL; j ++)
		{
#ifdef DEBUG
		printf("%p [%s] -> ", n, (char*)n->content);
		fflush(stdout);
#endif
			assert(n);
			assert(strcmp(n->content, t[i].texts[j]) == 0);
			if (t[i].end_to == j)
				loop_start = n;
			n = n->next;
		}
		assert((t[i].end_to == -1 && !n) || (t[i].end_to > -1 && n == loop_start));
#ifdef DEBUG
		printf("%p \n", loop_start);
#endif
		ft_list_clear(&root, free);
	}
}
