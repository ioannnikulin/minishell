/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_skip_delim.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:52:17 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/10 16:53:50 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

static void	process_char(const char **p, t_delims delim_arr,
			t_skip_chars ex_arr, int *word_qtty)
{
	size_t		match_len;
	static int	in_quotes;
	static int	quote_type;

	if (!p || !*p)
		return ;
	is_in_quotes(**p, ex_arr, &in_quotes, &quote_type);
	if (!in_quotes && ft_is_delim(*p, delim_arr.delims, delim_arr.count,
			&match_len))
	{
		if (*word_qtty > 0)
			*word_qtty = -*word_qtty;
		(*p) += match_len;
	}
	else
	{
		if (*word_qtty <= 0)
			*word_qtty = -*word_qtty + 1;
		(*p)++;
	}
}

int	count_words_skip_delim(const char *pp, t_delims delim_arr,
			t_skip_chars ex_arr)
{
	const char	*p;
	int			word_qtty;

	p = pp;
	word_qtty = 0;
	while (*p)
	{
		process_char(&p, delim_arr, ex_arr, &word_qtty);
	}
	if (word_qtty < 0)
		return (-word_qtty);
	return (word_qtty);
}
