/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_buf_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/09 11:54:58 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/strings/strings_internal.h"
#include "tests.h"

#define NUM_TEST_CASES 8
#define MAX_ARGS 10

t_delims create_operator_array()
{
	t_delims delim_array;
	delim_array.count = 10;
	delim_array.delims = (t_delim *)malloc(sizeof(t_delims) * delim_array.count);

	delim_array.delims[0].delim = ">>";
	delim_array.delims[1].delim = ">";
	delim_array.delims[2].delim = "<<";
	delim_array.delims[3].delim = "<";
	delim_array.delims[4].delim = "||";
	delim_array.delims[9].delim = "|";
	delim_array.delims[6].delim = "&&";
	delim_array.delims[7].delim = "&";
	delim_array.delims[8].delim = "(";
	delim_array.delims[5].delim = ")";
	return (delim_array);
}

t_strings	create_string_array()
{
	t_strings	str_array;
	str_array.count = 9;
	str_array.strs = (t_string *)malloc(str_array.count * sizeof(t_string));

	str_array.strs[0].str = "cat ( file1.txt file2.txt ) | grep \"keyword\"";
	str_array.strs[1].str = "cat < input.txt && echo | grep \"Done\"";
	str_array.strs[2].str = "grep \"error\" log.txt || echo \"No errors found\"";
	str_array.strs[3].str = "gcc main.c -o program >> build.log";
	str_array.strs[4].str = "find . -name \"*.txt\" | xargs rm -rf || fer && def & echo \"Hello\"";
	str_array.strs[5].str = "echo \"Compiling...\" && gcc main.c -o program && ./program";
	str_array.strs[6].str = "mkdir new_dir && cd new_dir && touch file.txt";
	str_array.strs[7].str = "mv new_dir old_dir";
	return (str_array);
}

void	ft_split_buf_test(void)
{
	t_delims	op_arr = create_operator_array();
	t_strings	str_arr = create_string_array();

	 char *t[NUM_TEST_CASES][MAX_ARGS] =
	 {
		{"cat ", "(", "file1.txt file2.txt ", ")", "|", "grep \"keyword\"", NULL},
		{"cat ", "<", "input.txt ", "&&", "echo ", "|", "grep \"Done\"", NULL},
		{"grep \"error\" log.txt ", "||", "echo \"No errors found\"", NULL},
		{"gcc main.c -o program ", ">>", "build.log", NULL},
		{"find . -name \"*.txt\" ", "|", "xargs rm -rf ", "||", "fer ", "&&", "def ", "&", "echo \"Hello\"", NULL},
		{"echo \"Compiling...\" ", "&&", "gcc main.c -o program ", "&&", "./program", NULL},
		{"mkdir new_dir ", "&&", "cd new_dir ", "&&", "touch file.txt", NULL},
		{"mv new_dir old_dir", NULL}
	};
	for (int i = 0; i < NUM_TEST_CASES; i ++)
	{
		int sz = 0;
		char **split_op = ft_split_buf(str_arr.strs[i].str, &op_arr, &sz);
		for (int j = 0; j < sz; j ++)
		{
			if (split_op[j] == NULL || t[i][j] == NULL)
			{
				ft_printf("Error: NULL pointer detected in 2\n");
				continue;
			}
			assert((split_op[j] == NULL) == (t[i][j] == NULL));
			if (split_op[j] == NULL)
			{
				break;
			}
			assert(strcmp(split_op[j], t[i][j]) == 0);
		}
	}
}
