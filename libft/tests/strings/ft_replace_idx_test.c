/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_idx_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:26:13 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/01 19:07:48 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_internal.h"
#define START 0
#define SZ 13
//#define DEBUG

typedef struct s_testcase
{
	char	*where;
	int		fromIncl;
	int		toExcl;
	char	*with;
	char	*exp;
}	t_testcase;

int	ft_replace_idx_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"abc", 0, 1, "d", "dbc"};
	t[1] = (t_testcase){"abc", 0, 2, "d", "dc"};
	t[2] = (t_testcase){"abc", 0, 1, "dd", "ddbc"};
	t[3] = (t_testcase){"abc", 1, 2, "d", "adc"};
	t[4] = (t_testcase){"abc", 1, 3, "d", "ad"};
	t[5] = (t_testcase){"abc", 1, 2, "dd", "addc"};
	t[6] = (t_testcase){"abc", 1, 1, "dd", "abc"};
	t[7] = (t_testcase){"abc", 1, 0, "dd", "abc"};
	t[8] = (t_testcase){0, 0, 1, "d", 0};
	t[9] = (t_testcase){"abc", -1, 1, "d", 0};
	t[10] = (t_testcase){"abc", 10, 11, "d", 0};
	t[11] = (t_testcase){"abc", 0, 11, "d", 0};
	t[12] = (t_testcase){"abc", 0, 1, 0, 0};
	for (int i = START; i < SZ; i ++)
	{
		#ifdef DEBUG
		FT_PRINTF("%i\n", i);
		#endif
		char	*s = (t[i].where ? ft_strdup(t[i].where) : 0);
		char	**src = &s;
		assert(src);
		char	*act = ft_replace_idx(src, t[i].fromIncl, t[i].toExcl, t[i].with);
		if (t[i].exp)
		{
			assert(act == *src);
			assert(ft_strcmp(act, t[i].exp) == 0);
			free(act);
		}
		else
		{
			assert(!act);
			free(s);
		}
	}
	return (0);
}
