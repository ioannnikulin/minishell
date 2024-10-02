/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_buf_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/02 19:39:34 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

#define NUM_TEST_CASES 8
#define MAX_ARGS 10

t_operator_array create_operator_array()
{
	t_operator_array op_array;
	op_array.count = 10;
	op_array.ops = (t_operator *)malloc(op_array.count * sizeof(t_operator));

	op_array.ops[0].op = ">>";
	op_array.ops[1].op = ">";
	op_array.ops[2].op = "<<";
	op_array.ops[3].op = "<";
	op_array.ops[4].op = "||";
	op_array.ops[9].op = "|";
	op_array.ops[6].op = "&&";
	op_array.ops[7].op = "&";
	op_array.ops[8].op = "(";
	op_array.ops[5].op = ")";
	return (op_array);
}

t_string_array	create_string_array()
{
	t_string_array	str_array;
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
	t_operator_array	op_arr = create_operator_array();
	t_string_array		str_arr = create_string_array();

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
				printf("Error: NULL pointer detected in 2\n");
				continue;
			}
			assert((split_op[j] == NULL) == (t[i][j] == NULL));
			if (split_op[j] == NULL)
				break;
			assert(strcmp(split_op[j], t[i][j]) == 0);
		}
	}
}
