/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:21 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/21 21:20:29 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <bsd/string.h>

typedef struct s_testcase
{
	size_t	global_sz;
	char	*src;
	size_t	src_start;
	size_t	tocopy;
	char	*dst;
	size_t	dst_start;
}	t_testcase;

void	*ft_strlcat_test_prep(t_testcase t)
{
	size_t dst_end = t.dst_start + strlen(t.dst); 
	size_t src_end = t.src_start + strlen(t.src); 
	assert(t.global_sz >= t.src_start + t.tocopy);
	//printf("%lu %lu %lu\n", t.global_sz, dst_end, t.tocopy);
	assert(t.global_sz >= dst_end + t.tocopy);
	assert(t.global_sz >= src_end);
	char * res = calloc(t.global_sz, 1);
	assert(res != NULL);
	strncpy(&res[t.dst_start], t.dst, strlen(t.dst));
	strncpy(&res[t.src_start], t.src, strlen(t.src));
	/*printf("ends %lu %lu\n", dst_end, src_end);
	for (size_t i = 0; i < t.global_sz; i ++)
		printf("[%i] ", res[i]);
	printf("\n");*/
	assert(res[dst_end] == 0);
	assert(res[src_end] == 0);
	for (size_t j = 0; j < t.src_start && j < t.dst_start; j ++)
		assert(res[j] == 0);
	for (size_t j = src_end; j < t.dst_start; j ++)
		assert(res[j] == 0);
	for (size_t j = dst_end; j < t.src_start; j ++)
		assert(res[j] == 0);
	assert(strncmp(&res[t.src_start], t.src, strlen(t.src)) == 0);
	assert(strncmp(&res[t.dst_start], t.dst, strlen(t.dst)) == 0);
	for (size_t j = (dst_end < src_end ? src_end : dst_end); j < t.global_sz; j ++)
		assert(res[j] == 0);
	return (res);
}

#define SZ 16

void	ft_strlcat_test(void)
{
	t_testcase t[SZ];
       	// 			sz - 	src and pos - 	copy -	dest and pos -	null
	t[0] = (t_testcase){10, 	"012", 6, 	3, 	"abc", 1};
	t[1] = (t_testcase){12,		"01234", 5,	5,	"abc", 1};
	t[2] = (t_testcase){12,		"defgh", 6, 	5, 	"abcd", 1};
	t[3] = (t_testcase){13, 	"012", 1, 	3, 	"abc", 6};
	t[4] = (t_testcase){14, 	"0123", 2,	4, 	"abc", 7};

	t[5] = (t_testcase){20, 	"012", 6,	10, 	"abc", 1};
	t[6] = (t_testcase){22, 	"01234", 5, 	10, 	"abc", 1};
	t[7] = (t_testcase){22, 	"defgh", 6, 	10, 	"abcd", 1};
	t[8] = (t_testcase){23, 	"012", 1, 	10, 	"abc", 6};
	t[9] = (t_testcase){24, 	"0123", 1, 	10, 	"abc", 7};

	t[10] = (t_testcase){10, 	"012", 6, 	2, 	"abc", 1};
	t[11] = (t_testcase){12, 	"01234", 5, 	3, 	"abc", 1};
	t[12] = (t_testcase){12, 	"defgh", 6, 	4, 	"abcd", 1};
	t[13] = (t_testcase){13, 	"012", 1, 	2, 	"abc", 6};
	t[14] = (t_testcase){14, 	"0123", 1, 	2, 	"abc", 7};

	t[15] = (t_testcase){10, 	"0123", 1, 	0, 	"abc", 6};
	for (int i = 0; i < SZ; i ++)
	{
//		printf("%i\n", i);
		char * custom_src = ft_strlcat_test_prep(t[i]);
		char * std_src = ft_strlcat_test_prep(t[i]);
		int custom_res = ft_strlcat( \
			&custom_src[t[i].dst_start], \
			&custom_src[t[i].src_start], \
			t[i].tocopy);
		int std_res = strlcat( \
			&std_src[t[i].dst_start], \
			&std_src[t[i].src_start], \
			t[i].tocopy);
/*		printf("%p\n%p\n", std_src, custom_src);
		for (size_t j = 0; j < t[i].global_sz; j ++)
			printf("[%i] ", std_src[j]);
		printf("\n");
		for (size_t j = 0; j < t[i].global_sz; j ++)
			printf("[%i] ", custom_src[j]);
		printf("\n");
		printf("%d %d\n", std_res, custom_res);*/
		for (size_t j = 0; j < t[i].global_sz; j ++)
			assert(custom_src[j] == std_src[j]);
		assert(std_res == custom_res);
		free(std_src);
		free(custom_src);
	}
}
