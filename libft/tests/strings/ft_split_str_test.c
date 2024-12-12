/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/12 18:14:10 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/strings/strings.h"
#include "tests.h"
#define DEBUG
#define NUM_TEST_CASES 12
#define MAX_ARGS 10

typedef struct s_string
{
	char	*str;
}	t_string;

typedef struct s_string_array
{
	t_string	*strs;
	int			error;
	size_t		count;
}	t_strings;

void	free_string_array(t_strings str_array)
{
	for (int i = 0; i < (int)str_array.count; i++)
	{
		if (str_array.strs[i].str != NULL)
		free(str_array.strs[i].str);
	}
	free(str_array.strs);
}

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
	str_array.strs = ft_calloc_if(sizeof(t_string) * str_array.count, 1);;
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
	str_array.strs[0].str = strdup("echo '$(echo \"$(echo \"$(echo \"bla\")\")\")'");
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
	str_array.strs[11].str = strdup("cat ( file1.txt file2.txt ) | grep \"keyword\"");
	return (str_array);
}

void	ft_split_str_test(void)
{
	t_delims	op_arr;
	t_strings	str_arr;

	op_arr = create_operator_array();
	if (op_arr.error)
		return  ;
	str_arr = create_string_array();
	if (str_arr.error)
	{
		free(op_arr.delims);
		return ;
	}
	char *t[NUM_TEST_CASES][MAX_ARGS] =
	{
		{"echo ", "'$(echo \"$(echo \"$(echo \"bla\")\")\")'", NULL},
		{"cat ", "<", "input.txt ", "&&", "echo ", "|", "grep \"Done\"", NULL},
		{"grep \"error\" log.txt ", "||", "echo \"No errors found\"", NULL},
		{"gcc main.c -o program ", ">>", "build.log", NULL},
		{"find . -name \"*.txt\" ", "|", "xargs rm -rf ", "||", "fer ", "&&", "def ", "&", "echo \"Hello\"", NULL},
		{"echo \"Compiling...\" ", "&&", "gcc main.c -o program ", "&&", "./program", NULL},
		{"mkdir new_dir ", "&&", "cd new_dir ", "&&", "touch file.txt", NULL},
		{"mv new_dir old_dir", NULL},
		{"&&", NULL},
		{"", NULL},
		{")", "(", "(", ")", ")", "(", NULL},
		{"cat ", "(", "file1.txt file2.txt ", ")", "|", "grep \"keyword\"", NULL},
	};
	for (int i = 0; i < NUM_TEST_CASES; i ++)
	{
		int sz = 0;
		char **split_op = ft_split_str(str_arr.strs[i].str, op_arr, &sz);
		for (int j = 0; j < sz; j ++)
		{
			#ifdef DEBUG
			ft_printf("Result: %s\n", split_op[j]);
			ft_printf("Expect: %s\n", t[i][j]);
			ft_printf("Size is: %i\n", sz);
			#endif
			assert((split_op[j] == NULL) == (t[i][j] == NULL));
			if (split_op[j] == NULL)
			{
				break;
			}
			assert(strcmp(split_op[j], t[i][j]) == 0);
		}
		ft_free_ss_uptonull((void **)split_op);
	}
	free(op_arr.delims);
	free_string_array(str_arr);
}
