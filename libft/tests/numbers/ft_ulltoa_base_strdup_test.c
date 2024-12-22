/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base_strdup_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/22 18:22:50 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "tests.h"
#define SZ 18
#define MX 65
//#define DEBUG
#define START 0

typedef struct s_testcase
{
	long long	val;
	char	*base;
	char	*res;
}	t_testcase;

void	ft_ulltoa_base_strdup_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){12, "0123456789", "12"};
	t[1] = (t_testcase){33, "0123456789", "33"};
	t[2] = (t_testcase){0, "0123456789", "0"};
	t[3] = (t_testcase){ULLONG_MAX, "0123456789", "18446744073709551615"};
	t[4] = (t_testcase){LLONG_MAX, "0123456789", "9223372036854775807"};
	t[5] = (t_testcase){12, "01", "1100"};
	t[6] = (t_testcase){33, "01", "100001"};
	t[7] = (t_testcase){0, "01", "0"};
	t[8] = (t_testcase){ULLONG_MAX, "01", "1111111111111111111111111111111111111111111111111111111111111111"};
	t[9] = (t_testcase){LLONG_MAX, "01", "111111111111111111111111111111111111111111111111111111111111111"};
	t[10] = (t_testcase){12, "0123456789abcdef", "c"};
	t[11] = (t_testcase){33, "0123456789abcdef", "21"};
	t[12] = (t_testcase){0, "0123456789abcdef", "0"};
	t[13] = (t_testcase){ULLONG_MAX, "0123456789abcdef", "ffffffffffffffff"};
	t[14] = (t_testcase){LLONG_MAX, "0123456789abcdef", "7fffffffffffffff"};
	t[15] = (t_testcase){LLONG_MAX, "0123456789abcde0", 0};
	t[16] = (t_testcase){LLONG_MAX, "0123456789abcde+", 0};
	t[17] = (t_testcase){LLONG_MAX, "0", 0};
	for (int i = START; i <  SZ; i ++)
	{
		char *res = ft_ulltoa_base_strdup(t[i].val, t[i].base);
		#ifdef DEBUG
		printf("%i. %s - %s\n\n", i, t[i].res, res);
		#endif
		if (t[i].res)
			assert(strcmp(res, t[i].res) == 0);
		else
			assert(!res);
		free(res);
	}
}
