/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:40:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 18:36:42 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../tests_internal.h"
//#define DEBUG

#define SZ 5

void	ft_putstr_fd_test(void)
{
	char * t[] = {"abc", "", "!", "ab\ncd\t\r\vefg\0hij", 0};
	for (int i = 0; i < SZ; i ++)
	{
		int rm = remove("tmp.tst");
		assert(i == 0 || rm == 0);
		int f = open("tmp.tst", O_WRONLY | O_CREAT, 0600);
		if (f == -1)
			assert(file_not_created(0));
		ft_putstr_fd(t[i], f);
		close(f);
		f = open("tmp.tst", O_RDONLY);
		if (f == -1)
			assert(file_not_created(0));
		char rdbuf[20];
		int sz = read(f, rdbuf, 20);
		if ((!t[i] || !t[i][0]) && sz == 0)
		{
			close(f);
			continue;
		}
		size_t orig_sz = strlen(t[i]);
		assert(sz >= 0);
		assert((size_t)sz == orig_sz);
		#ifdef DEBUG
		printf("%i %i [%s] [%s]\n", i, sz, rdbuf, t[i]);
		#endif
		assert(strncmp(rdbuf, t[i], orig_sz) == 0);
		close(f);
	}
}
