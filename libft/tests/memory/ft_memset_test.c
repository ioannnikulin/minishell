/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:58:05 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 12:15:21 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct	s_testcase
{
	size_t	sz;
	int	filler;
}	t_testcase;

void	*ft_memset_test_prep(size_t sz, int filler)
{
	char * res = calloc(sz + 2, 1);
	assert(res != NULL);
	for (size_t j = 0; j < sz + 2; j ++)
		assert(res[j] == 0);
	char empty = (filler + 1) % 256;
	memset(res, empty, sz + 2);
	for (size_t j = 0; j < sz + 2; j ++)
		assert(res[j] == empty);
	return (res);
}

# define SZ 8

void	ft_memset_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){3, 'Q'};
	t[1] = (t_testcase){0, '('};
	t[2] = (t_testcase){10, 2147483647};
	t[3] = (t_testcase){1, 0};
	t[4] = (t_testcase){0, ' '};
	t[5] = (t_testcase){1, 128};
	t[6] = (t_testcase){0, 'Q'};
	t[7] = (t_testcase){10, 263};
	for (int i = 0; i < SZ; i ++)
	{
		char * custom_src = ft_memset_test_prep(t[i].sz, t[i].filler);
		char * custom_res = ft_memset( \
			custom_src, \
			t[i].filler, t[i].sz);
		char * std_src = ft_memset_test_prep(t[i].sz, t[i].filler);
		char * std_res = memset( \
			std_src, \
			t[i].filler, t[i].sz);
		if (custom_res == std_res) // NULL
		{
			free(custom_src);
			free(std_src);
			continue;
		}
		for (size_t j = 0; j < t[i].sz + 2; j ++)
			assert(custom_res[j] == std_res[j]);
		assert(custom_src == custom_res);
		free(std_src);
		free(custom_src);
	}
}
