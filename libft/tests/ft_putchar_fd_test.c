/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:40:54 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/18 16:57:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "tests.h"
//#define DEBUG

#define SZ 4

void	ft_putchar_fd_test(void)
{
	char * t[] = {"abc", "", "!", "ab\ncd\t\r\vefg\0hij"};
	for (int i = 0; i < SZ; i ++)
	{
		remove("tmp.tst");
		int f = open("tmp.tst", O_WRONLY | O_CREAT, 0600);
		if (f == -1)
			assert(file_not_created(0));
		ft_putchar_fd(t[i][0], f);
		close(f);
		f = open("tmp.tst", O_RDONLY);
		if (f == -1)
			assert(file_not_created(0));
		char rdbuf[20];
		int sz = read(f, rdbuf, 20);
		assert(sz == 1);
		assert(rdbuf[0] == t[i][0]);
		close(f);
	}
}
