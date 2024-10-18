/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing_internal.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:56 by taretiuk          #+#    #+#             */
/*   Updated: 2024/10/17 19:54:17 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PROCESSING_INTERNAL_H
# define INPUT_PROCESSING_INTERNAL_H

# include <stddef.h>
# include <stdlib.h>
# include "../../libft/sources/strings/strings.h"
# include "../../libft/sources/memory/memory.h"

char		**parse_command(const char *s);
t_delims	create_operator_array(void);

#endif