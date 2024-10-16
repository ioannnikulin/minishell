/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:11:49 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/16 16:34:06 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_delims create_operator_array()
{
	t_delims delim_array;
	delim_array.count = 10;
	delim_array.error = 0;
	delim_array.delims = (t_delim *)malloc(sizeof(t_delim) * delim_array.count);
	if (delim_array.delims == NULL)
	{
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

static void calculate_spaces(char **s, int *total_sz)
{
    int i = 0;
    int j;
    int sz;
    char **tok_space;

    *total_sz = 0;

    while (s[i] != NULL)
    {
        tok_space = ft_split(s[i], ' ', &sz);
        if (tok_space == NULL)
            return;
        
        *total_sz += sz;
        j = 0;
        while (j < sz)
        {
            free(tok_space[j++]);
        }
        free(tok_space);
        i++;
    }
}

char	**split_by_space(char **s)
{
	int		sz;
	int		i;
	int		j;
	int		res_i;
	int		total_sz;
	char 	**temp_split;
	char	**result;
	
	calculate_spaces(s, &total_sz);
	result = malloc(sizeof(char *) * (total_sz + 1));
	if (!result)
		return (NULL);
	i = 0;
	res_i = 0;
	while(s[i] != NULL)
	{
		temp_split = ft_split(s[i++], ' ', &sz);
		j = 0;
		while (j < sz)
		{
			result[res_i++] = temp_split[j++];
		}
		free(temp_split);
	}
	result[res_i] = NULL;
	free(s);
	return (result);
}

char	**split_by_operators(char *s, t_delims *arr)
{
	char	    **tok_oper;
	int 	    sz;

    tok_oper = ft_split_buf(s, arr, &sz);
    if (!tok_oper)
    {
        free(arr->delims);
        return (NULL);
    }
	return(tok_oper);	
}

char    **parse_command(char *s)
{
    t_delims	op_arr;
    char	    **tok_oper;
	char	    **tok_space;

	op_arr = create_operator_array();
    if (op_arr.error)
	{
		return (NULL);
	}
	tok_oper = split_by_operators(s, &op_arr);
	if (!tok_oper)
    {
        free(op_arr.delims);
        return NULL;
    }
	tok_space = split_by_space(tok_oper);
	free(op_arr.delims);
    return (tok_space);
}