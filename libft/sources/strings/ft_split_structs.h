/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:33:55 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/15 20:59:52 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_STRUCTS_H
# define FT_SPLIT_STRUCTS_H

# include <stdlib.h>

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
