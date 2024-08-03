/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 20:16:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	*ft_bzero_test_prep(int sz)
{
	char * res = calloc(sz + 2, 1);
	assert(res != NULL);
	for (int j = 0; j < sz + 2; j ++)
		assert(res[j] == 0);
	memset(res, '1', sz + 2);
	for (int j = 0; j < sz + 2; j ++)
		assert(res[j] == '1');
	return (res);
}

# define SZ 3

void	ft_bzero_test(void)
{
	size_t t[SZ] = {3, 1, 0};
	for (int i = 0; i < SZ; i ++)
	{
		char * custom_src = ft_bzero_test_prep(t[i]);
		char * std_src = ft_bzero_test_prep(t[i]);
		ft_bzero(custom_src, t[i]);
		bzero(std_src, t[i]);
		for (size_t j = 0; j < t[i] + 2; j ++)
			assert(custom_src[j] == std_src[j]);
		free(std_src);
		free(custom_src);
	}
   	char * custom_res = 0;
	ft_bzero(custom_res, 0);
	char * std_res = 0;
	bzero(std_res, (0)); // segfault in system bzero if not 0 as second parameter
	assert (custom_res == std_res && custom_res == 0);
}
