/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:11:45 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/15 21:56:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#include "../sources/tokenizing/tokenizing.h"
// #define DEBUG
#define TEST
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

static void	free_string_array(t_string *strs, size_t count)
{
	if (!strs)
		return;

	for (size_t i = 0; i < count; i++)
	{
		free(strs[i].str);
	}
	free(strs);
}

static int	init_ex_arr(t_skip_chars *ex_arr)
{
	ex_arr->count = 2;
	ex_arr->error = 0;
	ex_arr->exs = ft_calloc_if(sizeof(t_skip_chars) * ex_arr->count, 1);
	if (ex_arr->exs == NULL)
	{
		ex_arr->error = 1;
		return (ex_arr->error);
	}
	ex_arr->exs[0].ex = '"';
	ex_arr->exs[1].ex = '\'';
	return (0);
}

static t_strings	init_string_array()
{
	t_strings	str_array;
	str_array.count = NUM_TEST_CASES;
	str_array.error = 0;
	str_array.strs = ft_calloc_if(sizeof(t_string) * str_array.count, 1);
	assert(str_array.strs != NULL);
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

void	tokenize_cmd_test()
{
	t_strings	str_arr = init_string_array();
	t_skip_chars	ex_arr;

	if (init_ex_arr(&ex_arr) != 0)
	{
		free_string_array(str_arr.strs, str_arr.count);
		return ;
	}
	char		**tokens;

	tokens = NULL;
	assert(str_arr.error == 0 && "Failed to create string array.");
	char	*t[NUM_TEST_CASES][MAX_ARGS] =
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
	for (int i = START; i < NUM_TEST_CASES; i ++)
	{
		#ifdef DEBUG
		ft_printf("\n=========Test %i=============\n\n", i);
		#endif
		int ret = tokenize_cmd(str_arr.strs[i].str, &tokens);
		#ifdef DEBUG
		ft_printf("ret: %i\n", ret);
		#endif
		assert(ret == 0);
		for (int j = 0; tokens[j] != NULL; j++)
		{
			#ifdef DEBUG
			ft_printf("%s\n", tokens[j]);
			#endif
			assert((tokens[j] == NULL) == (t[i][j] == NULL));
			assert(ft_strcmp(tokens[j], t[i][j]) == 0);
		}
		ft_free_ss_uptonull((void **)tokens);
	}
	free_string_array(str_arr.strs, str_arr.count);

}
