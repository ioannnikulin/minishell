/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/23 23:27:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 36
//#define DEBUG

typedef struct s_testcase
{
	int	end_to;
	int	sz;
	char	*toadd;
	char	*texts[20];
}	t_testcase;

void	ft_list_add_back_test(void)
{
	t_testcase	t[SZ];
	t[0] = (t_testcase){-1, 3, "s", {"hello", "i", "", NULL}};
	t[1] = (t_testcase){0, 3, "w", {"hello", "i", "", NULL}};
	t[2] = (t_testcase){1, 3, "", {"hello", "i", "", NULL}};
	t[3] = (t_testcase){2, 3, NULL, {"hello", "i", "", NULL}};
	t[4] = (t_testcase){-1, 1, "@@", {"hello", NULL}};
	t[5] = (t_testcase){0, 1, " ", {"hello", NULL}};
	t[6] = (t_testcase){-1, 0, "]", {NULL}};
	t[7] = (t_testcase){-1, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[8] = (t_testcase){0, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[9] = (t_testcase){1, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[10] = (t_testcase){2, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[11] = (t_testcase){3, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[12] = (t_testcase){4, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[13] = (t_testcase){5, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[14] = (t_testcase){6, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[15] = (t_testcase){7, 8, "z", {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[16] = (t_testcase){-1, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[17] = (t_testcase){0, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[18] = (t_testcase){1, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[19] = (t_testcase){2, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[20] = (t_testcase){3, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[21] = (t_testcase){4, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[22] = (t_testcase){5, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[23] = (t_testcase){6, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[24] = (t_testcase){7, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[25] = (t_testcase){8, 9, "z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[26] = (t_testcase){-1, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[27] = (t_testcase){0, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[28] = (t_testcase){1, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[29] = (t_testcase){2, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[30] = (t_testcase){3, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[31] = (t_testcase){4, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[32] = (t_testcase){5, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[33] = (t_testcase){6, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[34] = (t_testcase){7, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[35] = (t_testcase){8, 9, NULL, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	for (int i = 0; i <  SZ; i ++)
	{
#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
#endif
		t_list *n = ft_list_generate(t[i].texts, t[i].end_to);
		t_list *root = n;
		t_list *nnode = (t[i].toadd ? ft_list_new(ft_strdup(t[i].toadd)) : NULL);
		ft_list_add_back(&n, nnode);
		t_list *orig = ft_list_generate(t[i].texts, t[i].end_to);
		t_list *origroot = orig;
#ifdef DEBUG
		t_list* loop_start;
#endif
		for (int j = 0; t[i].texts[j] != NULL; j ++)
		{
#ifdef DEBUG
			printf("%p [%s] -> ", n, (char*)n->content);
			fflush(stdout);
			if (t[i].end_to == j)
				loop_start = n;
#endif
			assert(strcmp(n->content, orig->content) == 0);
			orig = orig->next;
			n = n->next;
		}
#ifdef DEBUG
		printf("%p \n", loop_start);
		printf("%p %p\n\n", nnode, n);
		fflush(stdout);
#endif
		assert(nnode == n);
		assert(!t[i].toadd || !n->next);
		ft_list_clear(&root, free);
		ft_list_clear(&origroot, free);
	}
}
