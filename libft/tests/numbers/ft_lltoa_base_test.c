/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 19:04:55 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h> 
#include "tests.h"
#define SZ 18
#define MX 65
//#define DEBUG

typedef struct s_testcase
{
	long long	val;
	char	*base;
	char	*res;
}	t_testcase;

void	ft_lltoa_base_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){-12, "0123456789", "-12"};
	t[1] = (t_testcase){33, "0123456789", "33"};
	t[2] = (t_testcase){0, "0123456789", "0"};
	t[3] = (t_testcase){9223372036854775807, "0123456789", "9223372036854775807"};
	t[4] = (t_testcase){LLONG_MIN, "0123456789", "-9223372036854775808"};
	t[5] = (t_testcase){-12, "01", "-1100"};
	t[6] = (t_testcase){33, "01", "100001"};
	t[7] = (t_testcase){0, "01", "0"};
	t[8] = (t_testcase){9223372036854775807, "01", "111111111111111111111111111111111111111111111111111111111111111"};
	t[9] = (t_testcase){LLONG_MIN, "01", "-1000000000000000000000000000000000000000000000000000000000000000"};
	t[10] = (t_testcase){-12, "0123456789abcdef", "-c"};
	t[11] = (t_testcase){33, "0123456789abcdef", "21"};
	t[12] = (t_testcase){0, "0123456789abcdef", "0"};
	t[13] = (t_testcase){9223372036854775807, "0123456789abcdef", "7fffffffffffffff"};
	t[14] = (t_testcase){LLONG_MIN, "0123456789abcdef", "-8000000000000000"};
	t[15] = (t_testcase){LLONG_MIN, "0123456789abcde0", ""};
	t[16] = (t_testcase){LLONG_MIN, "0123456789abcde+", ""};
	t[17] = (t_testcase){LLONG_MIN, "0", ""};
	for (int i = 0; i <  SZ; i ++)
	{
		char res[MX];
		size_t sz = ft_lltoa_base(t[i].val, t[i].base, res);
		#ifdef DEBUG
		printf("%i. %s %lu - %s %lu\n\n", i, t[i].res, strlen(t[i].res), &res[MX - sz], sz);
		#endif
		assert(strncmp(&res[MX - sz], t[i].res, sz) == 0);
	}
}
