/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 12:41:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_testcase
{
	size_t	sz;
	char	*filler;
}	t_testcase;

void	*ft_memcpy_test_prep(size_t sz, char *filler)
{
	sz = (sz + 2 > strlen(filler) ? sz + 2 : strlen(filler));
	char * res = calloc(sz, 1);
	assert(res != NULL);
	for (size_t j = 0; j < sz; j ++)
		assert(res[j] == 0);
	return (res);
}

# define SZ 5

void	ft_memcpy_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){3, "Q"};
	t[1] = (t_testcase){0, "("};
	t[2] = (t_testcase){10, "¤ii"};
	t[3] = (t_testcase){1, "iiiiiii"};
	t[4] = (t_testcase){0, "Qwe"};
	for (int i = 0; i < SZ; i ++)
	{
		char * custom_src = ft_memcpy_test_prep(t[i].sz, t[i].filler);
		char * custom_res = ft_memcpy( \
			custom_src, \
			t[i].filler, \
			t[i].sz);
		char * std_src = ft_memcpy_test_prep(t[i].sz, t[i].filler);
		char * std_res = memcpy( \
			std_src, \
			t[i].filler, \
			t[i].sz);
		if (custom_res != std_res)
			for (size_t j = 0; j < t[i].sz + 2; j ++)
				assert(custom_res[j] == std_res[j]);
		free(std_src);
		free(custom_src);
	}
}
