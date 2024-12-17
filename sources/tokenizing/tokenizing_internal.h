/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:56 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/15 21:33:13 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_INTERNAL_H
# define TOKENIZING_INTERNAL_H

# include "../../libft/libft.h"
# include "../split/split.h"

int			create_ex_arr(t_skip_chars *ex_arr);
t_delims	create_operator_array(void);
t_delims	create_delim_arr(void);
int			cleanup(t_delims *arr, t_skip_chars *ex_arr, char **ss, int retval);
int			count_tokens(char **ss, t_delims arr, t_skip_chars ex_arr,
				int *t_sz);
int			check_empty_string(const char *s, char ***p_ss);

#endif
