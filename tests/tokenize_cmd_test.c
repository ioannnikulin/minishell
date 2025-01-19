/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:11:45 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/19 13:16:06 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#include "../sources/tokenizing/tokenizing.h"
// #define DEBUG
#define NUM_TEST_CASES 15
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

static t_strings	init_string_array()
{
	t_strings	str_array;
	str_array.count = NUM_TEST_CASES;
	str_array.error = 0;
	str_array.strs = calloc(str_array.count, sizeof(t_string));
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
	str_array.strs[14].str = strdup("(echo 1 && echo 1) | wc | wc");
	return (str_array);
}

void	tokenize_cmd_test()
{
	t_strings	str_arr = init_string_array();
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
		{"(", "echo", "1", "&&", "echo", "1", ")", "|", "wc", "|", "wc", NULL},
	};
	for (int i = START; i < NUM_TEST_CASES; i ++)
	{
		#ifdef DEBUG
		FT_PRINTF("\n=========Test %i=============\n\n", i);
		#endif
		int ret = tokenize_cmd(str_arr.strs[i].str, &tokens);
		#ifdef DEBUG
		FT_PRINTF("ret: %i\n", ret);
		#endif
		if (i == 10)
			assert(ret == 2);
		else
			assert(ret == 0);
		for (int j = 0; tokens[j] != NULL; j++)
		{
			#ifdef DEBUG
			FT_PRINTF("%s\n", tokens[j]);
			#endif
			assert((tokens[j] == NULL) == (t[i][j] == NULL));
			assert(ft_strcmp(tokens[j], t[i][j]) == 0);
		}
		ft_free_ss_uptonull((void **)tokens);
	}
	free_string_array(str_arr.strs, str_arr.count);
}
