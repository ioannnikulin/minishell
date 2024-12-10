/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:40:11 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/10 15:16:20 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_INTERNAL_H
# define STRINGS_INTERNAL_H

# include "strings.h"

int		find_delimiter(const char *s, t_delims arr, size_t *op_len);
int		extract_plain_token(char **res, const char **s,
			t_delims arr, int cwi);
int		extract_delimiter(char **res, const char **s,
			size_t op_len, int cwi);
int		copy_word(char **res, const char *from, int length);
bool	is_in_quotes(const char p, t_skip_chars ex_arr, int *in_quotes,
			int *quote_type);
bool	ft_is_quote(const char p, t_skip_chars ex_arr);
int		check_edges(char **res, int *cwi);
int		ft_is_delim(const char *s, t_delim *delims, int count,
			size_t *match_len);
int		count_words_skip_delim(const char *pp, t_delims arr,
			t_skip_chars ex_arr);

#endif
