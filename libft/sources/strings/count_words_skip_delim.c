/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_skip_delim.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:52:17 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/30 16:27:12 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_internal.h"

static void	process_char(const char **p, t_delims arr, const char ex,
					int *word_qtty)
{
	size_t		match_len;
	static int	in_quotes;

	is_in_quotes(p, ex, &in_quotes);
	if (!in_quotes && ft_is_delim(*p, arr.delims, arr.count, &match_len))
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

int	count_words_skip_delim(const char *pp, t_delims arr, const char ex)
{
	const char	*p;
	int			word_qtty;

	p = pp;
	word_qtty = 0;
	while (*p)
	{
		process_char(&p, arr, ex, &word_qtty);
	}
	if (word_qtty < 0)
		return (-word_qtty);
	return (word_qtty);
}
