/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:40:54 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/24 17:36:29 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "tests.h"
//#define DEBUG

#define SZ 5

void	ft_putnbr_fd_test(void)
{
	int t[SZ] = {123, 0, -123, 2147483647, -2147483648};
	for (int i = 0; i < SZ; i ++)
	{
		int rm = remove("tmp.tst");
		assert(i == 0 || rm == 0);
		int f = open("tmp.tst", O_WRONLY | O_CREAT, 0600);
		if (f == -1)
			assert(file_not_created(0));
		ft_putnbr_fd(t[i], f);
		close(f);
		f = open("tmp.tst", O_RDONLY);
		if (f == -1)
			assert(file_not_created(0));
		char rdbuf[20];
		char check[20];
		sprintf(check, "%d", t[i]);
		int sz = read(f, rdbuf, 20);
		size_t orig_sz = strlen(check);
		assert(sz > 0);
		#ifdef DEBUG
		printf("%i %i [%s] [%s]\n", i, sz, rdbuf, check);
		#endif
		assert(strncmp(rdbuf, check, orig_sz) == 0);
		close(f);
	}
	remove("tmp.tst");
}
