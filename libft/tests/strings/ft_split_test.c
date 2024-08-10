/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:24:25 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 12:21:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
//#define DEBUG

typedef struct s_testcase
{
	char	*what;
	char	delim;
	char	**res;
}	t_testcase;

#define SZ 9

void	ft_split_test(void)
{
	t_testcase t[SZ];
	char *empty[] = {0};
	t[0] = (t_testcase){NULL, 'i', empty};
	t[1] = (t_testcase){"i", 0, (char *[]){"i", 0}};
	t[2] = (t_testcase){"i", 'i', empty};
	t[3] = (t_testcase){"a1a2a3a", 'a',(char *[]) {"1","2","3",0}};
	t[4] = (t_testcase){" \t   what -shall we/do  )()with \\a_drunken\nsailor ", '%', (char *[]){" \t   what -shall we/do  )()with \\a_drunken\nsailor ", 0}};
	t[5] = (t_testcase){" \t   what -shall we/do  )()with \\a_drunken\nsailor ", ' ', (char *[]){"\t", "what", "-shall", "we/do", ")()with", "\\a_drunken\nsailor", 0}};
	t[6] = (t_testcase){"rum", 'r', (char *[]){"um", 0}};
	t[7] = (t_testcase){"", 'r', empty};
	t[8] = (t_testcase){"rum", '!', (char *[]){"rum", 0}};
	for (int i = 0; i < SZ; i ++)
	{
		int sz = 0;
		char **res = ft_split(t[i].what, t[i].delim, &sz);
		for (int j = 0; j < sz; j ++)
		{
			#ifdef DEBUG
			printf("%i [%p] [%p]\t\t", i, t[i].res[j], res[j]);
			fflush(stdout);
			#endif
			assert((res[j] == NULL) == (t[i].res[j] == NULL));
			if (res[j] == NULL)
				break;
			#ifdef DEBUG
			printf("[%s] [%s]\t\t", t[i].res[j], res[j]);
			fflush(stdout);
			#endif
			assert(strcmp(res[j], t[i].res[j]) == 0);
			free(res[j]);
		}
		#ifdef DEBUG
		printf("\n");
		#endif
		free(res);
	}
}
