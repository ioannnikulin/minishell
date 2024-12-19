/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:51:11 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/19 12:26:43 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include <stdlib.h>
# include "../../libft/sources/strings/ft_split_structs.h"
# include "../../libft/sources/strings/strings_internal.h"

int		copy_token(char **res, const char *s, size_t len);
void	process_quotes(const char *p, size_t *len);
int		handle_quotes(char **res, const char *s, size_t *len);
int		locate_single_quotes(const char *s, size_t *op_len);
int		locate_double_quotes(const char *s, size_t *len);
void	process_plain_token(const char *p, t_delims arr, size_t *len);
int		locate_plain_token(const char *s, t_delims arr, size_t *len);
void	calc_tokens(const char *p, t_delims arr, int *token_q);
int		if_empty_string(const char *s, char ***p_ss);
char	**ft_split_str(const char *s, t_delims arr, int *sz);

#endif
