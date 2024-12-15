/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_delim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:50:43 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/13 13:07:50 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

static void	parse_word(char **res, const char **f,
					t_delims arr, t_skip_chars ex_arr)
{
	int			cwlen;
	const char	*start;
	int			in_quotes;
	int			quote_type;
	size_t		match_len;

	in_quotes = 0;
	quote_type = 0;
	while (**f && ft_is_delim(*f, arr.delims, arr.count, &match_len))
		(*f)++;
	start = *f;
	cwlen = 0;
	is_in_quotes(**f, ex_arr, &in_quotes, &quote_type);
	while ((**f) && (in_quotes || !ft_is_delim(*f, arr.delims,
				arr.count, &match_len)))
	{
		cwlen++;
		(*f)++;
		is_in_quotes(**f, ex_arr, &in_quotes, &quote_type);
	}
	if (cwlen == 0)
		return ;
	if ((copy_word(res, start, cwlen) != 0))
		*res = NULL;
}

char	**ft_split_set_skip_delim(const char *str, t_delims arr,
					t_skip_chars ex_arr, int *sz)
{
	char		**res;
	const char	*current;
	int			word_qtty;
	int			cwi;

	word_qtty = count_words_skip_delim(str, arr, ex_arr);
	res = (char **) ft_calloc_if((word_qtty + 1) * sizeof(char *), 1);
	if (!res)
		return (0);
	res[word_qtty] = 0;
	if (word_qtty == 0)
		return (res);
	cwi = 0;
	current = str;
	while (*current && cwi < word_qtty)
	{
		parse_word(&res[cwi], &current, arr, ex_arr);
		if (check_edges(res, &cwi))
			return (NULL);
		cwi ++;
	}
	if (sz)
		*sz = word_qtty;
	return (res);
}

/*delim_arr " "*/
char	**ft_split_skip_delim(const char *str, t_delims delim_arr,
					t_skip_chars ex_arr, int *sz)
{
	if (sz)
		*sz = -1;
	return (ft_split_set_skip_delim(str, delim_arr, ex_arr, sz));
}
