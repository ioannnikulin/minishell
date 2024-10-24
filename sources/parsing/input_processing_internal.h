/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing_internal.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:56 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/23 11:23:30 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PROCESSING_INTERNAL_H
# define INPUT_PROCESSING_INTERNAL_H

# include <stddef.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include "../../libft/sources/strings/strings.h"
# include "../../libft/sources/memory/memory.h"

char		**parse_command(const char *s);
void		free_str_array(char **arr, int sz);
t_delims	create_operator_array(void);

#endif