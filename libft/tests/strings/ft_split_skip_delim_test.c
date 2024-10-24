/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_delim_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:24:51 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/23 18:03:26 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources/strings/strings.h"
#include "tests.h"

#define NUM_TEST_CASES 2
#define MAX_ARGS 9


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

static t_strings	create_string_array(void)
{
	t_strings	str_array;
	str_array.count = 1;
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
	str_array.strs[0].str = strdup("echo hello world");
    str_array.strs[1].str = strdup("cat ( file1.txt file2.txt ) | grep \"keyword\"");
    return (str_array);
}

void ft_split_skip_delim_test()
{
    t_strings	strings_arr = create_string_array();
    char	**tokens;
    int     sz;
    
	if (strings_arr.error)
	{
	    fprintf(stderr, "Failed to create string array.\n");
	    exit(1);
	}
	char *t[NUM_TEST_CASES][MAX_ARGS] =
	{
		{"echo", "hello", "world", NULL},
        {"cat", "(", "file1.txt", "file2.txt", ")", "|", "grep", "\"keyword\"", NULL},
    };
    for (int i = 0; i < NUM_TEST_CASES; i ++)
    {
        tokens = ft_split_skip_delim(strings_arr.strs[i].str, ' ', '"', &sz);
        ft_printf("Size of array: %d\n", sz);
        for (int j = 0; j < sz; j++)
        {
            ft_printf("Token is: %s\n", tokens[j]);
            if (t[i][j] != NULL)
                ft_printf("Example string is: %s\n", t[i][j]);
            else
                ft_printf("Example string is: NULL\n");
        }
    }
    ft_free_ss_null((void *)&strings_arr, (int)strings_arr.count);
    return ;
}