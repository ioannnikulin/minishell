/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 12:06:42 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 4
//#define DEBUG

void	ft_list_new_test(void)
{
	char **tests = malloc(SZ * sizeof(char *));
	if (!tests)
		assert(bad_alloc(0));
       	for (int i = 0; i < SZ; i ++)
		tests[i] = malloc(20);
	tests[0] = "hello";
	tests[1] = "¤";
	tests[2] = "";
	tests[3] = NULL;
	for (int i = 0; i <  SZ; i ++)
	{
		t_list *n = ft_list_new(tests[i]);
		assert(n);
#ifdef DEBUG
		printf("%i %p %p [%s] [%s]\n", i, tests[i], n->content, tests[i], (char *)n->content);
#endif
		assert(tests[i] == n->content);
	}
}
