/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_delim_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:24:51 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/13 14:35:29 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "tests.h"
// #define DEBUG
#define NUM_TEST_CASES 12
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

t_delims	init_delim_arr(void)
{
	t_delims	delim_array;

	delim_array.count = 2;
	delim_array.error = 0;
	delim_array.delims = ft_calloc_if(sizeof(t_delim) * delim_array.count, 1);
	if (delim_array.delims == NULL)
	{
		delim_array.error = 1;
		return (delim_array);
	}
	delim_array.delims[0].delim = " ";
	delim_array.delims[1].delim = "\t";
	return (delim_array);
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

t_strings	init_string_array()
{
	t_strings	str_array;
	str_array.count = 12;
	str_array.error = 0;
	str_array.strs = ft_calloc_if(sizeof(t_string) * str_array.count, 1);
	if (str_array.strs == NULL)
	{
		str_array.error = 1;
		return (str_array);
	}
	assert(str_array.strs != NULL);
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
	str_array.strs[9].str = strdup("echo \"ls -l && cd ..\"");
	str_array.strs[10].str = strdup(")(())(");
	str_array.strs[11].str = strdup("");
	return (str_array);
}

void	ft_split_skip_delim_test()
{
	t_strings		strings_arr;
	t_delims		delim_arr;
	t_skip_chars	ex_arr;
	char			**tokens;
	int				sz = 0;

	strings_arr = init_string_array();
	if (strings_arr.error)
	{
		return ;
	}
	delim_arr = init_delim_arr();
	if (delim_arr.error)
	{
		free_string_array(strings_arr.strs, strings_arr.count);
		return ;
	}
	if (init_ex_arr(&ex_arr) != 0)
	{
		free_string_array(strings_arr.strs, strings_arr.count);
		ft_free_delims_arr(&delim_arr);
		return ;
	}
	char *t[NUM_TEST_CASES][MAX_ARGS] =
	{
		{"cat", "(", "file1.txt", "file2.txt", ")", "|", "grep", "\"keyword\"", NULL},
		{"cat", "<", "input.txt", "&&", "echo", "|", "grep", "\"Done\"", NULL},
		{"grep", "\"error\"", "log.txt", "||", "echo", "\"No errors    found\"", NULL},
		{"gcc", "main.c", "-o", "program", ">>", "build.log", NULL},
		{"find", ".", "-name",  "\"*.txt\"", "|", "xargs", "rm", "-rf", "||", "fer", "&&", "def", "&", "echo", "\"Hello\"", NULL},
		{"echo", "\"Compiling...\"", "&&", "gcc", "main.c", "-o", "program", "&&", "./program", NULL},
		{"mkdir", "new_dir", "&&", "cd", "new_dir", "&&", "touch", "file.txt", NULL},
		{"mv", "new_dir", "old_dir", NULL},
		{"&&", NULL},
		{"echo", "\"ls -l && cd ..\"", NULL},
		{")(())(", NULL},
		{"", NULL},
	};
	for (int i = 0; i < NUM_TEST_CASES; i ++)
	{
		tokens = ft_split_skip_delim(strings_arr.strs[i].str, delim_arr, ex_arr, &sz);
		if (tokens == NULL)
		{
			assert(t[i][0] == NULL);
		}
		else
		{
			for (int j = 0; tokens[j] != NULL; j++)
			{
				#ifdef DEBUG
				FT_PRINTF("%s\n", tokens[j]);
				#endif
				assert((tokens[j] == NULL) == (t[i][j] == NULL));
				if (tokens[j] == NULL)
				{
					break;
				}
				assert(ft_strcmp(tokens[j], t[i][j]) == 0);
			}
		}
		ft_free_ss_sz_null((void *)&(tokens), sz);
		sz = 0;
	}
	free_string_array(strings_arr.strs, strings_arr.count);
	ft_free_delims_arr(&delim_arr);
	ft_free_delim_c(&ex_arr);
	return ;
}
