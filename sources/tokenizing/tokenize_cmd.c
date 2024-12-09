/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:08:59 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/09 16:28:40 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_processing.h"

static int	process_temp_split(char ***p_ss, char **temp_split,
			int sz, int *res_i)
{
	int	j;

	j = 0;
	while (j < sz)
	{
		(*p_ss)[(*res_i)++] = temp_split[j++];
		if (!(*p_ss)[(*res_i) - 1])
		{
			ft_free_ss_uptonull((void **)temp_split);
			return (1);
		}
	}
	return (0);
}

static int	split_excluding_quotes(char **s, t_delims delim_arr,
			t_skip_chars ex_arr, char ***p_ss)
{
	int				i;
	int				sz;
	int				res_i;
	char			**temp_split;

	ft_assign_i(&i, -1, ft_assign_i(&res_i, 0, 0));
	while (s[++i] != NULL)
	{
		temp_split = ft_split_skip_delim(s[i], delim_arr, ex_arr, &sz);
		if (temp_split == NULL)
		{
			ft_free_ss_uptonull((void **)temp_split);
			return (1);
		}
		if (process_temp_split(p_ss, temp_split, sz, &res_i))
			return (1);
		free(temp_split);
	}
	(*p_ss)[res_i] = NULL;
	return (0);
}

static int	split_by_spcs_tabs(char **ss, t_delims arr, t_skip_chars ex_arr,
				char ***p_ss)
{
	int	t_sz;

	t_sz = 0;
	if (count_tokens(ss, arr, ex_arr, &t_sz) != 0)
		return (cleanup(&arr, &ex_arr, 0, 3));
	*p_ss = (char **)ft_calloc_if((t_sz + 1) * sizeof(char *), 1);
	if (*p_ss == NULL)
		return (1);
	if (split_excluding_quotes(ss, arr, ex_arr, p_ss) != 0)
		return (1);
	if (*p_ss == NULL)
		return (cleanup(0, 0, *p_ss, 2));
	return (0);
}

static int	split_by_operators(const char *s, char ***p_ss)
{
	int			sz;
	t_delims	op_arr;

	sz = 0;
	if (s == NULL)
		return (1);
	op_arr = create_operator_array();
	if (op_arr.error)
		return (1);
	*p_ss = ft_split_str(s, op_arr, &sz);
	if (*p_ss == NULL)
		return (cleanup(&op_arr, 0, *p_ss, 2));
	return (cleanup(&op_arr, 0, 0, 0));
}

int	tokenize_cmd(const char *s, char ***p_ss)
{
	char			**tok_oper;
	t_delims		delim_arr;
	t_skip_chars	ex_arr;

	tok_oper = NULL;
	if (check_empty_string(s, p_ss) != 0)
		return (0);
	delim_arr = create_delim_arr();
	if (delim_arr.error)
		return (cleanup(0, 0, 0, 1));
	if (create_ex_arr(&ex_arr) != 0)
		return (cleanup(&delim_arr, 0, 0, 2));
	if (split_by_operators(s, &tok_oper) != 0)
		return (cleanup(&delim_arr, &ex_arr, tok_oper, 2));
	if (split_by_spcs_tabs(tok_oper, delim_arr, ex_arr, p_ss) != 0)
		return (cleanup(&delim_arr, &ex_arr, tok_oper, 4));
	cleanup(&delim_arr, &ex_arr, tok_oper, 0);
	return (0);
}
