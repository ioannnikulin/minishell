/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:21 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/09 18:14:13 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

//#define DEBUG

typedef struct s_testcase
{
	size_t	global_sz;
	char	*src;
	size_t	src_start;
	size_t	tocopy;
	size_t	dst_start;
}	t_testcase;

void	*ft_memmove_test_prep(t_testcase t)
{
	assert(t.global_sz >= t.src_start + t.tocopy);
	assert(t.global_sz >= t.dst_start + t.tocopy);
	char * res = calloc(t.global_sz, 1);
	assert(res != NULL);
	memmove(&res[t.src_start], t.src, t.tocopy);
	for (size_t j = 0; j < t.src_start; j ++)
		assert(res[j] == 0);
	assert(strncmp(&res[t.src_start], t.src, t.tocopy) == 0);
	for (size_t j = t.src_start + t.tocopy; j < t.global_sz; j ++)
		assert(res[j] == 0);
	return (res);
}

#define SZ 7

void	ft_memmove_test(void)
{
	t_testcase t[SZ];
	t[0] = (t_testcase){10, "abc", 1, 2, 6}; // 01234567890
	t[1] = (t_testcase){10, "abc", 1, 0, 6}; // .abc..+++..
	t[2] = (t_testcase){10, "abc", 1, 4, 6};
	t[3] = (t_testcase){10, "abc", 1, 4, 2};
	t[4] = (t_testcase){10, "abc", 4, 4, 2};
	t[5] = (t_testcase){10, "", 4, 4, 2};
	t[6] = (t_testcase){10, "abc", 1, 0, 6};
	for (int i = 0; i < SZ; i ++)
	{
	  #ifdef DEBUG
		printf("%i\n", i);
	  #endif
		char * custom_src = ft_memmove_test_prep(t[i]);
		char * custom_res = ft_memmove( \
			&custom_src[t[i].dst_start], \
			&custom_src[t[i].src_start], \
			t[i].tocopy);
		char * std_src = ft_memmove_test_prep(t[i]);
		char * std_res = memmove( \
			&std_src[t[i].dst_start], \
			&std_src[t[i].src_start], \
			t[i].tocopy);
		if (custom_res == std_res) // NULL
		{
			free(custom_src);
			free(std_src);
			continue;
		}
		for (size_t j = 0; j < t[i].global_sz; j ++)
			assert(custom_src[j] == std_src[j]);
		free(std_src);
		free(custom_src);
	}
}
