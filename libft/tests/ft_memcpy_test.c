/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/15 12:38:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

typedef struct s_testcase
{
	size_t	sz;
	char	*filler;
	unsigned char	nullify;
	// 0 - as is; 1 - NULL instead of dest; 2 - instead of src; 3 - both
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

# define SZ 9

void	ft_memcpy_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){3, "Q", 0};
	t[1] = (t_testcase){0, "(", 0};
	t[2] = (t_testcase){10, "¤ii", 0};
	char s[3] = "ii";
	s[0] = 0;
	t[3] = (t_testcase){3, s, 0};
	t[4] = (t_testcase){1, "iiiiiii", 0};
	s[0] = -128;
	t[5] = (t_testcase){1, s, 0};
	t[6] = (t_testcase){0, "Qwe", 1};
	t[7] = (t_testcase){0, "Qwe", 2};
	t[8] = (t_testcase){0, "Qwe", 3};
	for (int i = 0; i < SZ; i ++)
	{
		char * custom_src = ft_memcpy_test_prep(t[i].sz, t[i].filler);
		char * custom_res = ft_memcpy( \
			((t[i].nullify & 1) > 0 ? NULL : custom_src), \
			((t[i].nullify & 2) > 0 ? NULL : t[i].filler), \
			t[i].sz);
		char * std_src = ft_memcpy_test_prep(t[i].sz, t[i].filler);
		char * std_res = memcpy( \
			((t[i].nullify & 1) > 0 ? NULL : std_src), \
			((t[i].nullify & 2) > 0 ? NULL : t[i].filler), \
			t[i].sz);
		if (custom_res != std_res)
			for (size_t j = 0; j < t[i].sz + 2; j ++)
				assert(custom_res[j] == std_res[j]);
		if ((t[i].nullify & 1) == 0)
		       	assert(custom_src == custom_res);
		else
			assert(custom_res == NULL);
		free(std_src);
		free(custom_src);
	}
}
