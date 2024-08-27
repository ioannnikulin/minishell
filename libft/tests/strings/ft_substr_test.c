/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:58:05 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 16:55:53 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct	s_testcase
{
	char		*s;
	unsigned int	start;
	size_t		len;
	char		*res;
}	t_testcase;

#define SZ 38

void	ft_substr_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){"", 0, 0, ""};
	t[1] = (t_testcase){"", 0, 1, ""};
	t[2] = (t_testcase){"", 0, 2, ""};
	t[3] = (t_testcase){"", 1, 0, ""};
	t[4] = (t_testcase){"", 1, 1, ""};
	t[5] = (t_testcase){"", 1, 2, ""};
	t[6] = (t_testcase){"", 2, 0, ""};
	t[7] = (t_testcase){"", 2, 1, ""};
	t[8] = (t_testcase){"", 2, 2, ""};
	t[9] = (t_testcase){"Q", 0, 0, ""};
	t[10] = (t_testcase){"Q", 0, 1, "Q"};
	t[11] = (t_testcase){"Q", 0, 2, "Q"};
	t[12] = (t_testcase){"Q", 1, 0, ""};
	t[13] = (t_testcase){"Q", 1, 1, ""};
	t[14] = (t_testcase){"Q", 1, 2, ""};
	t[15] = (t_testcase){"Q", 2, 0, ""};
	t[16] = (t_testcase){"Q", 2, 1, ""};
	t[17] = (t_testcase){"Q", 2, 2, ""};
	t[18] = (t_testcase){"ab", 0, 0, ""};
	t[19] = (t_testcase){"ab", 0, 1, "a"};
	t[20] = (t_testcase){"ab", 0, 2, "ab"};
	t[21] = (t_testcase){"ab", 1, 0, ""};
	t[22] = (t_testcase){"ab", 1, 1, "b"};
	t[23] = (t_testcase){"ab", 1, 2, "b"};
	t[24] = (t_testcase){"ab", 2, 0, ""};
	t[25] = (t_testcase){"ab", 2, 1, ""};
	t[26] = (t_testcase){"ab", 2, 2, ""};
	t[27] = (t_testcase){"1234567890", 0, 0, ""};
	t[28] = (t_testcase){"1234567890", 0, 1, "1"};
	t[29] = (t_testcase){"1234567890", 0, 2, "12"};
	t[30] = (t_testcase){"1234567890", 1, 0, ""};
	t[31] = (t_testcase){"1234567890", 1, 1, "2"};
	t[32] = (t_testcase){"1234567890", 1, 2, "23"};
	t[33] = (t_testcase){"1234567890", 2, 0, ""};
	t[34] = (t_testcase){"1234567890", 2, 1, "3"};
	t[35] = (t_testcase){"1234567890", 2, 2, "34"};
	t[36] = (t_testcase){0, 0, 0, ""};
	t[37] = (t_testcase){0, 1, 0, ""};
	for (int i = 0; i < SZ; i ++)
	{
		char * res = ft_substr(t[i].s, t[i].start, t[i].len);
		#ifdef DEBUG
			printf("%i [%s] from %u len %lu -> [%s] %lu\n", i, t[i].s, t[i].start, t[i].len, res, strlen(res));
		#endif
		assert(strcmp(res, t[i].res) == 0);
		free(res);
	}
}
