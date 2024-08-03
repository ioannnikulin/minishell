/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:40:54 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/18 17:51:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "tests.h"
//#define DEBUG

#define SZ 5 

void	ft_putendl_fd_test(void)
{
	char * t[] = {"abc", "", "!", "ab\ncd\t\r\vefg\0hij", 0};
	for (int i = 0; i < SZ; i ++)
	{
		remove("tmp.tst");
		int f = open("tmp.tst", O_WRONLY | O_CREAT, 0600);
		if (f == -1)
			assert(file_not_created(0));
		ft_putendl_fd(t[i], f);
		close(f);
		f = open("tmp.tst", O_RDONLY);
		if (f == -1)
			assert(file_not_created(0));
		char rdbuf[20];
		int sz = read(f, rdbuf, 20);
		if (sz == 0 && (!t[i] || !t[i][0]))
		{
			close(f);
			continue ;
		}
		#ifdef DEBUG
		printf("%i %i [%s] [%s]\n", i, sz, rdbuf, t[i]);
		#endif
		size_t orig_sz = strlen(t[i]);
		assert(sz >= 0 && (size_t)sz == orig_sz + 1);
		assert(strncmp(rdbuf, t[i], orig_sz) == 0);
		assert(rdbuf[orig_sz] == 10);
		close(f);
	}
}
