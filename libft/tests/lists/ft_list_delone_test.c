/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delone_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 12:05:38 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 13 
//#define DEBUG

typedef struct s_testcase
{
	int	end_to;
	int	todel;
	char	*texts[20];
}	t_testcase;

void	ft_list_delone_test(void)
{
	t_testcase	t[SZ];
	t[0] = (t_testcase){-1, 0, {"hello", "i", "", NULL}};
	t[1] = (t_testcase){0, 0, {"hello", "i", "", NULL}};
	t[2] = (t_testcase){1, 0, {"hello", "i", "", NULL}};
	t[3] = (t_testcase){2, 0, {"hello", "i", "", NULL}};
	t[4] = (t_testcase){-1, 1, {"hello", "i", "", NULL}};
	t[5] = (t_testcase){0, 1, {"hello", "i", "", NULL}};
	t[6] = (t_testcase){1, 1, {"hello", "i", "", NULL}};
	t[7] = (t_testcase){2, 1, {"hello", "i", "", NULL}};
	t[8] = (t_testcase){-1, 2, {"hello", "i", "", NULL}};
	t[9] = (t_testcase){0, 2, {"hello", "i", "", NULL}};
	t[10] = (t_testcase){1, 2, {"hello", "i", "", NULL}};
	t[11] = (t_testcase){2, 2, {"hello", "i", "", NULL}};
	t[12] = (t_testcase){-1, 0, {"hello", NULL}};
	for (int i = 0; i <  SZ; i ++)
	{
#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
#endif
		t_list *root = ft_list_generate(t[i].texts, t[i].end_to);
		t_list *todel = root;
		t_list *prev = NULL;
		for (int j = 0; j < t[i].todel; j ++)
		{
			prev = todel;
			todel = todel->next;
		}
		t_list *next = todel->next;
		t_list *cur = root;
#ifdef DEBUG
		ft_list_print(root);
		printf("[%s] [%s] [%s]\n", (prev ? (char*)prev->content : "NULL"), (char*)todel->content, (next ? (char*)next->content : "NULL"));
#endif
		ft_list_delone(todel, free);
		if (prev)
			prev->next = NULL;
		for (int j = 0; j < t[i].todel; j ++)
		{
#ifdef DEBUG
			printf("[%s] [%s]\n", (char*)cur->content, t[i].texts[j]);
			fflush(stdout);
#endif
			assert(cur);
			assert(strcmp((char*)cur->content, t[i].texts[j]) == 0);
			cur = cur->next;
		}
		cur = next;
#ifdef DEBUG
		printf("\n");
#endif
		for (int j = t[i].todel + 1; t[i].texts[j]; j ++)
		{
#ifdef DEBUG
			printf("[%s] [%s]\n", (char*)cur->content, t[i].texts[j]);
#endif
			assert(cur);
			assert(strcmp(cur->content, t[i].texts[j]) == 0);
			prev = cur;
			cur = cur->next;
		}
		assert((t[i].end_to == -1 && !cur) || t[i].end_to > -1);
		if (t[i].todel != 0)
			ft_list_clear(&root, free);
		if (next && t[i].end_to > t[i].todel)
			ft_list_clear(&next, free);
	}
}
