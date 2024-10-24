/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_buf_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/09 18:12:59 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/strings/strings_internal.h"
#include "tests.h"

#define NUM_TEST_CASES 11
#define MAX_ARGS 10

t_delims create_operator_array()
{
	t_delims delim_array;
	delim_array.count = 10;
	delim_array.error = 0;
	delim_array.delims = (t_delim *)malloc(sizeof(t_delim) * delim_array.count);
	if (delim_array.delims == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		delim_array.error = 1;
		return (delim_array);
	}
	delim_array.delims[0].delim = ">>";
	delim_array.delims[1].delim = ">";
	delim_array.delims[2].delim = "<<";
	delim_array.delims[3].delim = "<";
	delim_array.delims[4].delim = "||";
	delim_array.delims[5].delim = ")";
	delim_array.delims[6].delim = "&&";
	delim_array.delims[7].delim = "&";
	delim_array.delims[8].delim = "(";
	delim_array.delims[9].delim = "|";
	return (delim_array);
}

t_strings	create_string_array()
{
	t_strings	str_array;
	str_array.count = 11;
	str_array.error = 0;
	str_array.strs = (t_string *)malloc(str_array.count * sizeof(t_string));
	if (str_array.strs == NULL)
	{
		fprintf(stderr, "Memory allocation failed for str_array.strs\n");
		str_array.error = 1;
		str_array.strs = NULL;
		return (str_array);
	}
	for (int i = 0; i < (int)str_array.count; i++)
	{
		str_array.strs[i].str = NULL;
	}

	str_array.strs[0].str = strdup("cat ( file1.txt file2.txt ) | grep \"keyword\"");
	str_array.strs[1].str = strdup("cat < input.txt && echo | grep \"Done\"");
	str_array.strs[2].str = strdup("grep \"error\" log.txt || echo \"No errors found\"");
	str_array.strs[3].str = strdup("gcc main.c -o program >> build.log");
	str_array.strs[4].str = strdup("find . -name \"*.txt\" | xargs rm -rf || fer && def & echo \"Hello\"");
	str_array.strs[5].str = strdup("echo \"Compiling...\" && gcc main.c -o program && ./program");
	str_array.strs[6].str = strdup("mkdir new_dir && cd new_dir && touch file.txt");
	str_array.strs[7].str = strdup("mv new_dir old_dir");
	str_array.strs[8].str = strdup("&&");
	str_array.strs[9].str = strdup("");
	str_array.strs[10].str = strdup(")(())(");
	return (str_array);
}


void	free_split_op(char **split_op, int sz)
{
	for (int j = 0; j < sz; j++)
	{
		if(split_op[j] != NULL)
			free(split_op[j]);
	}
	if (split_op != NULL)
		free(split_op);
}

void	free_string_array(t_strings str_array)
{
	for (int i = 0; i < (int)str_array.count; i++)
	{
		if (str_array.strs[i].str != NULL)
		free(str_array.strs[i].str);
	}
	free(str_array.strs);
}

void	ft_split_buf_test(void)
{
	t_delims	op_arr = create_operator_array();
	t_strings	str_arr = create_string_array();

	 if (str_arr.error || op_arr.error)
	 {
		fprintf(stderr, "Failed to create string array.\n");
		exit(1);
	}

	 char *t[NUM_TEST_CASES][MAX_ARGS] =
	 {
		{"cat ", "(", "file1.txt file2.txt ", ")", "|", "grep \"keyword\"", NULL},
		{"cat ", "<", "input.txt ", "&&", "echo ", "|", "grep \"Done\"", NULL},
		{"grep \"error\" log.txt ", "||", "echo \"No errors found\"", NULL},
		{"gcc main.c -o program ", ">>", "build.log", NULL},
		{"find . -name \"*.txt\" ", "|", "xargs rm -rf ", "||", "fer ", "&&", "def ", "&", "echo \"Hello\"", NULL},
		{"echo \"Compiling...\" ", "&&", "gcc main.c -o program ", "&&", "./program", NULL},
		{"mkdir new_dir ", "&&", "cd new_dir ", "&&", "touch file.txt", NULL},
		{"mv new_dir old_dir", NULL},
		{"&&", NULL},
		{"", NULL},
		{")", "(", "(", ")", ")", "(", NULL}
	};
	for (int i = 0; i < NUM_TEST_CASES; i ++)
	{
		int sz = 0;
		char **split_op = ft_split_buf(str_arr.strs[i].str, &op_arr, &sz);
		for (int j = 0; j < sz; j ++)
		{
			assert((split_op[j] == NULL) == (t[i][j] == NULL));
			if (split_op[j] == NULL)
			{
				break;
			}
			assert(strcmp(split_op[j], t[i][j]) == 0);
		}
		free_split_op(split_op, sz);
	}
	free(op_arr.delims);
	free_string_array(str_arr);
}
