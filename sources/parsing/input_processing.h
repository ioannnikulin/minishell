/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:47:07 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/19 15:30:01 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PROCESSING_H
# define INPUT_PROCESSING_H

# include <stddef.h>
# include <stdlib.h>
# include "../../libft/sources/strings/strings.h"
# include "../../libft/sources/memory/memory.h"

char		**parse_command(const char *s);
t_delims	create_operator_array(void);

#endif