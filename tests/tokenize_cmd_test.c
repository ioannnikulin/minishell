/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:11:45 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/29 14:27:39 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#include "../sources/tokenizing/input_processing.h"

#define NUM_TEST_CASES 11
#define MAX_ARGS 16

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

t_strings	create_string_array()
{
	t_strings	str_array;
	str_array.count = 11;
	str_array.error = 0;
	str_array.strs = ft_calloc_if(sizeof(t_string) * str_array.count, 1);
	assert(str_array.strs != NULL);
	for (int i = 0; i < (int)str_array.count; i++)
	{
		str_array.strs[i].str = NULL;
	}
	str_array.strs[0].str = strdup("grep \"error\" log.txt || echo \"No errors    found\"");
	str_array.strs[1].str = strdup("cat ( file1.txt file2.txt ) | grep \"keyword\"");
	str_array.strs[2].str = strdup("cat < input.txt && echo | grep \"Done\"");
	str_array.strs[3].str = strdup("gcc main.c -o program >> build.log");
	str_array.strs[4].str = strdup("find . -name \"*.txt\" | xargs rm -rf || fer && def & echo \"Hello\"");
	str_array.strs[5].str = strdup("echo \"Compiling...\" && gcc main.c -o program && ./program");
	str_array.strs[6].str = strdup("mkdir new_dir && cd new_dir && touch file.txt");
	str_array.strs[7].str = strdup("mv new_dir old_dir");
	str_array.strs[8].str = strdup("&&");
	str_array.strs[9].str = strdup(")(())(");
	str_array.strs[10].str = strdup("");
	return (str_array);
}

static void	free_tokens(char **tokens)
{
	if (!tokens)
		return;
	for (int i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
}

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

void	tokenize_cmd_test()
{
	t_strings	str_arr = create_string_array();
	char		**tokens;

	assert(str_arr.error == 0 && "Failed to create string array.");
	char	*t[NUM_TEST_CASES][MAX_ARGS] =
	{
		{"grep", "\"error\"", "log.txt", "||", "echo", "\"No errors    found\"", NULL},
		{"cat", "(", "file1.txt", "file2.txt", ")", "|", "grep", "\"keyword\"", NULL},
		{"cat", "<", "input.txt", "&&", "echo", "|", "grep", "\"Done\"", NULL},
		{"gcc", "main.c", "-o", "program", ">>", "build.log", NULL},
		{"find", ".", "-name", "\"*.txt\"", "|", "xargs", "rm", "-rf", "||", "fer", "&&", "def", "&", "echo", "\"Hello\"", NULL},
		{"echo", "\"Compiling...\"", "&&", "gcc", "main.c", "-o", "program", "&&", "./program", NULL},
		{"mkdir", "new_dir", "&&", "cd", "new_dir", "&&", "touch", "file.txt", NULL},
		{"mv", "new_dir", "old_dir", NULL},
		{"&&", NULL},
		{")", "(", "(", ")", ")", "(", NULL},
		{NULL}
	};
	for (int i = 0; i < NUM_TEST_CASES; i ++)
	{
		tokens = tokenize_cmd(str_arr.strs[i].str);
		if (tokens == NULL)
		{
			assert(t[i][0] == NULL);
		}
		else
		{
			for (int j = 0; tokens[j] != NULL; j++)
			{
				assert((tokens[j] == NULL) == (t[i][j] == NULL));
				assert(ft_strcmp(tokens[j], t[i][j]) == 0);
			}
			free_tokens(tokens);
		}
	}
	free_string_array(str_arr.strs, str_arr.count);
}
