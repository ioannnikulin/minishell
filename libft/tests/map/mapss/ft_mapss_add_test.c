/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_add_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 18:17:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss_test.h"

#define SZ 3

typedef struct s_testcase
{
	char	*key;
	char	*value;
	int		size_expected;
	char	*keys_expected[20];
	char	*values_expected[20];
}	t_testcase;

static void	generate_tests(t_testcase *tests)
{/*
	const char *keys[] = {"PATH", "SHELL", "HOME", "USERNAME", "PATH", "SHLVL", "OLDPWD", "DISPLAY", ""};
	const char *values[] = {"/usr/local/sbin", "/bin/bash", "/home/user", "/usr/local/sbin", "1", "/home/taretiuk/42/student", ":0", "X Window", "Error"};
*/
	tests[0] = (t_testcase){"PATH", "/usr/local/sbin", 1, {"PATH"}, {"/usr/local/sbin"}};
	tests[1] = (t_testcase){"SHELL", "/bin/bash", 2, {"PATH", "SHELL"}, {"/usr/local/sbin", "/bin/bash"}};
	tests[2] = (t_testcase){"HOME", "/home/user", 3, {"HOME", "PATH", "SHELL"}, {"/home/user", "/usr/local/sbin", "/bin/bash"}};
}

void	ft_mapss_add_test(void)
{
	t_mapss		*map;
	t_testcase	tests[SZ];

	map = ft_calloc_if(sizeof(t_mapss*), 1);
	if (!map)
		return ;
	generate_tests(tests);
	for (int i = 0; i < SZ; i++)
	{
		ft_mapss_add(map, tests[i].key, tests[i].value);
		assert(map->size == tests[i].size_expected);
		t_dlist *node = map->head;
		for (int j = 0; j < map->size; j ++)
		{
			t_mapss_entry *entry = node->content;
			assert(ft_strcmp(tests[i].keys_expected[j], entry->key) == 0);
			assert(ft_strcmp(tests[i].values_expected[j], entry->value) == 0);
			node = node->next;
		}
	}
}
