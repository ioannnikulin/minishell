/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:08:59 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/27 15:36:26 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_processing.h"

static int	split_excluding_quotes(char **s, t_delims *arr, char ***p_ss)
{
	int		i;
	int		j;
	int		sz;
	int		res_i;
	char	**temp_split;

	i = 0;
	res_i = 0;
	while (s[i] != NULL)
	{
		temp_split = ft_split_skip_delim(s[i], arr, '"', &sz);
		j = 0;
		while (j < sz)
		{
			(*p_ss)[res_i++] = ft_strdup(temp_split[j++]);
		}
		ft_free_ss_sz_null((void *)&(temp_split), sz);
		i++;
	}
	(*p_ss)[res_i] = NULL;
	return (0);
}

static int	split_by_spcs_tabs(char **ss, t_delims *arr, int *t_sz, char ***p_ss)
{

	*p_ss = ft_calloc_if((*t_sz + 1) * sizeof(char *), 1);
	if (*p_ss == NULL)
		return (1);
	split_excluding_quotes(ss, arr, p_ss);
	if (*p_ss == NULL)
		return (cleanup(0, p_ss, *t_sz + 1, 2));
	return (0);
}

static int	split_by_operators(const char *s, int *sz, char ***p_ss)
{
	t_delims	op_arr;

	*p_ss = NULL;
	op_arr = create_operator_array();
	if (op_arr.error)
		return (1);
	*p_ss = ft_split_str(s, &op_arr, sz);
	if (*p_ss == NULL || (*p_ss)[0] == NULL)
		cleanup(&op_arr, p_ss, *sz, 2);
	cleanup(&op_arr, 0, 0, 0);
	return (0);
}

int	tokenize_cmd(const char *s, int *t_sz, char ***ss)
{
	int			s_sz;
	char		**tok_oper;
	t_delims	delim_arr;

	s_sz = 0;
	delim_arr = create_delim_arr();
	if (delim_arr.error)
		return (cleanup(0, 0, 0, 1));
	*t_sz =  count_words_skip_delim(s, &delim_arr, '"');
	if (*t_sz == 0)
		return (cleanup(&delim_arr, 0, 0, 2));
	if (split_by_operators(s, &s_sz, &tok_oper) != 0)
		return (cleanup(0, &tok_oper, s_sz, 2));
	if (split_by_spcs_tabs(tok_oper, &delim_arr, t_sz, ss) != 0)
		return(cleanup(&delim_arr, &tok_oper, s_sz, 3));
	cleanup(&delim_arr, &tok_oper, s_sz, 0);
	return (0);
}
