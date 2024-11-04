/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:56 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/04 06:15:06 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PROCESSING_H
# define INPUT_PROCESSING_H

# include "../../libft/libft.h"

char		**tokenize_cmd(const char *s);
t_delims	create_operator_array(void);
void		cleanup(t_delims *op_arr, char ***tok_oper, int sz);

#endif