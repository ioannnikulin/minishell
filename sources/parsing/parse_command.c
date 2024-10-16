/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:11:49 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/16 19:04:21 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	**split_excluding_quotes(char **result, char **s, int sz)
{
	int		i;
	int		j;
	int		res_i;
	char 	**temp_split;
	
	i = 0;
	res_i = 0;
	while(s[i] != NULL)
	{
		temp_split = ft_split_ex(s[i++], ' ', &sz);
		j = 0;
		while (j < sz)
		{
			result[res_i++] = temp_split[j++];
		}
		free(temp_split);
	}
	result[res_i] = NULL;
	return (result);
}

static void	calculate_spaces(char **s, int *sz, int *total_sz)
{
	int		i;
    int		j;
    char	**tok_space;

	i = 0;
	*total_sz = 0;
	while (s[i] != NULL)
	{
		tok_space = ft_split_ex(s[i], ' ', sz);
		if (tok_space == NULL)
			return ;
		*total_sz += *sz;
		j = 0;
		while (j < *sz)
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
	int		total_sz;
	char	**result;
	
	calculate_spaces(s, &sz, &total_sz);
	result = malloc(sizeof(char *) * (total_sz + 1));
	if (!result)
		return (NULL);
	result = split_excluding_quotes(result, s, sz);
	free(s);
	return (result);
}

char	**split_by_operators(char *s, t_delims *arr)
{
	char	    **tok_oper;
	int 	    sz;

    tok_oper = ft_split_str(s, arr, &sz);
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