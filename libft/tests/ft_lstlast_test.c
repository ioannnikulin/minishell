/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/21 20:46:15 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 26
//#define DEBUG

typedef struct s_testcase
{
	int	end_to;
	int	sz;
	char	*texts[20];
}	t_testcase;

void	ft_lstlast_test(void)
{
	t_testcase	t[SZ];
	t[0] = (t_testcase){-1, 3, {"hello", "i", "", NULL}};
	t[1] = (t_testcase){0, 3, {"hello", "i", "", NULL}};
	t[2] = (t_testcase){1, 3, {"hello", "i", "", NULL}};
	t[3] = (t_testcase){2, 3, {"hello", "i", "", NULL}};
	t[4] = (t_testcase){-1, 1, {"hello", NULL}};
	t[5] = (t_testcase){0, 1, {"hello", NULL}};
	t[6] = (t_testcase){-1, 0, {NULL}};
	t[7] = (t_testcase){-1, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[8] = (t_testcase){0, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[9] = (t_testcase){1, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[10] = (t_testcase){2, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[11] = (t_testcase){3, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[12] = (t_testcase){4, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[13] = (t_testcase){5, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[14] = (t_testcase){6, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[15] = (t_testcase){7, 8, {"a", "b", "c", "d", "e", "f", "g", "h", NULL}};
	t[16] = (t_testcase){-1, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[17] = (t_testcase){0, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[18] = (t_testcase){1, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[19] = (t_testcase){2, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[20] = (t_testcase){3, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[21] = (t_testcase){4, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[22] = (t_testcase){5, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[23] = (t_testcase){6, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[24] = (t_testcase){7, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	t[25] = (t_testcase){8, 9, {"a", "b", "c", "d", "e", "f", "g", "h", "i", NULL}};
	for (int i = 0; i <  SZ; i ++)
	{
#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
#endif
		t_list *n = ft_lst_generate(t[i].texts, t[i].end_to);
		t_list *root = n;
		t_list *prev = NULL;
		t_list *ans = ft_lstlast(root);
		t_list *loop_start = NULL;
		for (int j = 0; t[i].texts[j] != NULL; j ++)
		{
#ifdef DEBUG
			printf("%p [%s] -> ", n, (char*)n->content);
			fflush(stdout);
#endif
			if (t[i].end_to == j)
				loop_start = n;
			prev = n;
			n = n->next;
		}
		n = root;
#ifdef DEBUG
		printf("%p \n", loop_start);
		printf("%p %p\n\n", prev, ans);
#endif
		assert(prev == ans);
		ft_lstclear(&root, free);
	}
}
