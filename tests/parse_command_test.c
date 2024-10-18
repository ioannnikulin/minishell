/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:50:45 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/17 22:49:33 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#include "../sources/parsing/input_processing_internal.h"

#define NUM_TEST_CASES 11
#define MAX_ARGS 16

t_strings	create_string_array()
{
	t_strings	str_array;
	str_array.count = 11;
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

	str_array.strs[0].str = strdup("cat ( file1.txt file2.txt ) | grep \"keyword\"");
	str_array.strs[1].str = strdup("cat < input.txt && echo | grep \"Done\"");
	str_array.strs[2].str = strdup("grep \"error\" log.txt || echo \"No errors    found\"");
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

void	free_string_array(t_strings str_array)
{
	for (int i = 0; i < (int)str_array.count; i++)
	{
		if (str_array.strs[i].str != NULL)
		free(str_array.strs[i].str);
	}
	free(str_array.strs);
}

void    parse_command_test()
{
    t_strings	str_arr = create_string_array();
    char	**tokens;
    
	if (str_arr.error)
	{
	    fprintf(stderr, "Failed to create string array.\n");
	    exit(1);
	}
	char *t[NUM_TEST_CASES][MAX_ARGS] =
	{
		{"cat", "(", "file1.txt", "file2.txt", ")", "|", "grep", "\"keyword\"", NULL},
		{"cat", "<", "input.txt", "&&", "echo", "|", "grep", "\"Done\"", NULL},
		{"grep", "\"error\"", "log.txt", "||", "echo", "\"No errors    found\"", NULL},
		{"gcc", "main.c", "-o", "program", ">>", "build.log", NULL},
		{"find", ".", "-name", "\"*.txt\"", "|", "xargs", "rm", "-rf", "||", "fer", "&&", "def", "&", "echo", "\"Hello\"", NULL},
		{"echo", "\"Compiling...\"", "&&", "gcc", "main.c", "-o", "program", "&&", "./program", NULL},
		{"mkdir", "new_dir", "&&", "cd", "new_dir", "&&", "touch", "file.txt", NULL},
		{"mv", "new_dir", "old_dir", NULL},
		{"&&", NULL},
		{"", NULL},
		{")", "(", "(", ")", ")", "(", NULL}
	};
    for (int i = 0; i < NUM_TEST_CASES; i ++)
	{
		tokens = parse_command(str_arr.strs[i].str);
		for (int j = 0; tokens[j] != NULL; j ++)
		{
			assert((tokens[j] == NULL) == (t[i][j] == NULL));
			if (tokens[j] == NULL)
			{
				break;
			}
			assert(strcmp(tokens[j], t[i][j]) == 0);
		}
	}
	free_string_array(str_arr);
}