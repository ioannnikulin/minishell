/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:33:55 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/03 13:35:48 by taretiuk         ###   ########.fr       */
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

#endif
