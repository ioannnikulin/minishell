/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:33:55 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/09 12:56:08 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_delim
{
	char	*delim;
}	t_delim;

typedef struct s_delims
{
	t_delim		*delims;
	int			error;
	size_t		count;
}	t_delims;

typedef struct s_skip_char
{
	char	ex;
}	t_skip_char;

typedef struct s_skip_chars
{
	t_skip_char	*exs;
	int			error;
	size_t		count;
}	t_skip_chars;

#endif
