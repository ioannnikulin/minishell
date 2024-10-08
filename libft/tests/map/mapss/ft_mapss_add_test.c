/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapss_add_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:36 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/23 23:28:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapss_test.h"

#define SZ 9
#undef DEBUG

typedef struct s_testcase
{
	char	*key;
	char	*value;
	int		size_expected;
	char	*keys_expected[20];
	char	*values_expected[20];
}	t_testcase;

static void	generate_tests(t_testcase *tests)
{
	/*
	const char *keys[] = {	"PATH", 			"SHELL", 		"HOME", 		"USERNAME", 		"PATH", 			"SHLVL", 	"OLDPWD", 	"DISPLAY", 	"", };
	const char *values[] = {"/usr/local/sbin", 	"/bin/bash", 	"/home/user", 	"/usr/local/sbin", 	"/usr/local/sbin",	"1", 		":0", 		"X Window", "Empty_sring"};
*/
	tests[0] = (t_testcase){"PATH", "/usr/local/sbin", 1, {"PATH"}, {"/usr/local/sbin"}};
	tests[1] = (t_testcase){"SHELL", "/bin/bash", 2, {"PATH", "SHELL"}, {"/usr/local/sbin", "/bin/bash"}};
	tests[2] = (t_testcase){"HOME", "/home/user", 3, {"HOME", "PATH", "SHELL"}, {"/home/user", "/usr/local/sbin", "/bin/bash"}};
	tests[3] = (t_testcase){"USERNAME", "/usr/local/sbin", 4, {"HOME", "PATH", "SHELL", "USERNAME"}, {"/home/user", "/usr/local/sbin", "/bin/bash", "/usr/local/sbin"}};
	tests[4] = (t_testcase){"PATH", "/usr/local/sbin", 4, {"HOME", "PATH", "SHELL", "USERNAME"}, {"/home/user", "/usr/local/sbin", "/bin/bash", "/usr/local/sbin"}};
	tests[5] = (t_testcase){"SHLVL", "1", 5, {"HOME", "PATH", "SHELL", "SHLVL", "USERNAME"}, {"/home/user", "/usr/local/sbin", "/bin/bash", "1", "/usr/local/sbin"}};
	tests[6] = (t_testcase){"OLDPWD", ":0", 6, {"HOME", "OLDPWD", "PATH", "SHELL", "SHLVL", "USERNAME"}, {"/home/user", ":0", "/usr/local/sbin", "/bin/bash", "1", "/usr/local/sbin"}};
	tests[7] = (t_testcase){"DISPLAY", "X Window", 7, {"DISPLAY", "HOME", "OLDPWD", "PATH", "SHELL", "SHLVL", "USERNAME"}, {"X Window", "/home/user", ":0", "/usr/local/sbin", "/bin/bash", "1", "/usr/local/sbin"}};
	tests[8] = (t_testcase){"", "Empty_sring", 8, {"", "DISPLAY", "HOME", "OLDPWD", "PATH", "SHELL", "SHLVL", "USERNAME"}, {"Empty_sring", "X Window", "/home/user", ":0", "/usr/local/sbin", "/bin/bash", "1", "/usr/local/sbin"}};
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
		#ifdef DEBUG
		ft_printf("%i\n", i);
		#endif
		ft_mapss_add(map, tests[i].key, tests[i].value);
		assert(map->size == tests[i].size_expected);
		t_dlist *node = map->head;
		for (int j = 0; j < map->size; j ++)
		{
			#ifdef DEBUG
			ft_printf("%i ", j);
			#endif
			t_mapss_entry *entry = node->content;
			assert(ft_strcmp(tests[i].keys_expected[j], entry->key) == 0);
			assert(ft_strcmp(tests[i].values_expected[j], entry->value) == 0);
			node = node->next;
		}
		#ifdef DEBUG
		ft_printf("\n");
		#endif
	}
}
