/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/15 21:36:19 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/split/split.h"
#include "../sources/tokenizing/tokenizing_internal.h"
#include "tests_internal.h"
// #define DEBUG
#define DO_ASSERT
#define NUM_TEST_CASES 14
#define MAX_ARGS 15
#define START 0
#define STOP NUM_TEST_CASES

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

static void	free_string_array(t_strings str_array)
{
	for (int i = 0; i < (int)str_array.count; i++)
	{
		if (str_array.strs[i].str != NULL)
			free(str_array.strs[i].str);
	}
	free(str_array.strs);
}

static void	print_array(char **res, int act_sz, char **exp, int exp_sz)
{
	if (!res)
		return ;
	int	i = 0;
	FT_PRINTF("Result:\n");
	while (i < act_sz)
	{
		FT_PRINTF("%s\n", res[i]);
		i++;
	}

	i = 0;
	FT_PRINTF("\nExpected:\n");
	while (i < exp_sz)
	{
		FT_PRINTF("%s\n", exp[i]);
		i++;
	}
	FT_PRINTF("\n");
}

static t_strings	create_string_array()
{
	t_strings	str_array;
	str_array.count = NUM_TEST_CASES;
	str_array.error = 0;
	str_array.strs = ft_calloc_if(sizeof(t_string) * str_array.count, 1);
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
	str_array.strs[0].str = strdup("echo \"&&\"");
	str_array.strs[1].str = strdup("echo '$(echo \"$(echo \"$(echo \"bla\")\")\")'");
	str_array.strs[2].str = strdup("cat < input.txt && echo | grep \"Done\"");
	str_array.strs[3].str = strdup("grep \"error\" log.txt || echo \"No errors found\"");
	str_array.strs[4].str = strdup("gcc main.c -o program >> build.log");
	str_array.strs[5].str = strdup("find -name \"*.txt\" | xargs rm -rf || fer && def & echo \"Hello\"");
	str_array.strs[6].str = strdup("echo \"Compiling...\" && gcc main.c -o program && ./program");
	str_array.strs[7].str = strdup("mkdir new_dir && cd new_dir && touch file.txt");
	str_array.strs[8].str = strdup("mv new_dir old_dir");
	str_array.strs[9].str = strdup("&&");
	str_array.strs[10].str = strdup("");
	str_array.strs[11].str = strdup(")(())(");
	str_array.strs[12].str = strdup("cat ( file1.txt file2.txt ) | grep \"keyword\"");
	str_array.strs[13].str = strdup("[\"a\"]");
	return (str_array);
}

void	ft_split_str_test(void)
{
	t_delims	op_arr;
	t_strings	str_arr;

	op_arr = create_operator_array();
	if (op_arr.error)
		return ;
	str_arr = create_string_array();
	if (str_arr.error)
	{
		free(op_arr.delims);
		return ;
	}
	char *t[NUM_TEST_CASES][MAX_ARGS] =
	{
		{"echo", "\"&&\"", NULL},
		{"echo", "'$(echo \"$(echo \"$(echo \"bla\")\")\")'", NULL},
		{"cat", "<", "input.txt", "&&", "echo", "|", "grep", "\"Done\"", NULL},
		{"grep", "\"error\"", "log.txt", "||", "echo", "\"No errors found\"", NULL},
		{"gcc", "main.c", "-o", "program", ">>", "build.log", NULL},
		{"find", "-name", "\"*.txt\"", "|", "xargs", "rm", "-rf", "||", "fer", "&&", "def", "&", "echo", "\"Hello\"", NULL},
		{"echo", "\"Compiling...\"", "&&", "gcc", "main.c", "-o", "program", "&&", "./program", NULL},
		{"mkdir", "new_dir", "&&", "cd", "new_dir", "&&", "touch", "file.txt", NULL},
		{"mv", "new_dir", "old_dir", NULL},
		{"&&", NULL},
		{"", NULL},
		{")", "(", "(", ")", ")", "(", NULL},
		{"cat", "(", "file1.txt", "file2.txt", ")", "|", "grep", "\"keyword\"", NULL},
		{"[\"a\"]", NULL},
	};
	for (int i = START; i < STOP; i ++)
	{
		#ifdef DEBUG
		FT_PRINTF("\n=========Test %i=============\n\n", i);
		#endif
		int act_sz = 0;
		char **split_op = ft_split_str(str_arr.strs[i].str, op_arr, &act_sz);
		int exp_sz = 0;
		while (t[i][exp_sz]) exp_sz ++;
		#ifdef DEBUG
		print_array(split_op, act_sz, t[i], exp_sz);
		#endif
		for (int j = 0; j < act_sz; j ++)
		{
			#ifdef DO_ASSERT
			assert((split_op[j] == NULL) == (t[i][j] == NULL));
			if (split_op[j] == NULL)
			{
				break;
			}
			assert(strcmp(split_op[j], t[i][j]) == 0);
			#endif
		}
		ft_free_ss_uptonull((void **)split_op);
	}
	free(op_arr.delims);
	free_string_array(str_arr);
	print_array(0, 0, 0, 0);//to avoid unused function warning
}
