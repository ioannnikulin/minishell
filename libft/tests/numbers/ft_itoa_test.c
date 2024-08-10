/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/18 14:51:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 5
//#define DEBUG

typedef struct s_testcase
{
	int	val;
	char	*res;
}	t_testcase;

void	ft_itoa_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){-12, "-12"};
	t[1] = (t_testcase){33, "33"};
	t[2] = (t_testcase){0, "0"};
	t[3] = (t_testcase){2147483647, "2147483647"};
	t[4] = (t_testcase){-2147483648, "-2147483648"};
	for (int i = 0; i <  SZ; i ++)
	{
		char *r = ft_itoa(t[i].val);
		#ifdef DEBUG
		printf("%i %s %lu\n\n", i, r, strlen(r));
		#endif
		assert(strcmp(r, t[i].res) == 0);
		free(r);
	}
}
