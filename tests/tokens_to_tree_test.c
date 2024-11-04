/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_tree_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:22:15 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/04 18:03:31 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#include "../sources/parsing/input_processing.h"

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

t_strings	create_cmd_arr()
{
	t_strings	cmd_arr;
	cmd_arr.count = 11;
	cmd_arr.error = 0;
	cmd_arr.strs = calloc(sizeof(t_string) * cmd_arr.count, 1);
	assert(cmd_arr.strs != NULL);
	for (int i = 0; i < (int)cmd_arr.count; i++)
	{
		cmd_arr.strs[i].str = NULL;
	}
	cmd_arr.strs[0].str = strdup("grep \"error\" log.txt || echo \"No errors    found\"");
	cmd_arr.strs[1].str = strdup("cat ( file1.txt file2.txt ) | grep \"keyword\"");
	cmd_arr.strs[2].str = strdup("cat < input.txt && echo | grep \"Done\"");
	cmd_arr.strs[3].str = strdup("gcc main.c -o program >> build.log");
	cmd_arr.strs[4].str = strdup("find . -name \"*.txt\" | xargs rm -rf || fer && def & echo \"Hello\"");
	cmd_arr.strs[5].str = strdup("echo \"Compiling...\" && gcc main.c -o program && ./program");
	cmd_arr.strs[6].str = strdup("mkdir new_dir && cd new_dir && touch file.txt");
	cmd_arr.strs[7].str = strdup("mv new_dir old_dir");
	cmd_arr.strs[8].str = strdup("&&");
	cmd_arr.strs[9].str = strdup(")(())(");
	cmd_arr.strs[10].str = strdup("");
	return (cmd_arr);
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

void    tokens_to_tree_test()
{
	t_strings	cmd_arr;
 	t_param		param;

	cmd_arr = create_cmd_arr();
    assert(cmd_arr.error == 0 && "Failed to create string array.");
	param.cur_command = NULL;
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
	for (int i = 0; i < NUM_TEST_CASES; i++)
	{
		param.cur_command = cmd_arr.strs[i].str;
		printf("Command: %s\n", param.cur_command);
		if (input_to_text_tree(&param) == 0)
		{
			printf("Root: %s\nToken: %s\n", (char *)param.text_tree->root->content, t[i][0]);
			assert(param.text_tree->root != NULL && "Root node is NULL");
			assert(param.text_tree->root->content != NULL && "Root node data is NULL");
			assert(ft_strcmp(param.text_tree->root->content, t[i][0]) == 0 && "Root node data does not match");
			free(param.text_tree->root->content);
		}
	}
	free_string_array(cmd_arr.strs, cmd_arr.count);
}