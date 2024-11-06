/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:56 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/05 10:44:07 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PROCESSING_H
# define INPUT_PROCESSING_H

# include "../../libft/libft.h"
# include "../../libft/sources/memory/memory.h"

char		**parse_command(const char *s, int *total_sz);
t_delims	create_operator_array(void);
void		cleanup(t_delims *op_arr, char ***tok_oper, int sz);

#endif