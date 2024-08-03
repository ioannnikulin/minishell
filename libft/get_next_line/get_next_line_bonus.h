/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:29:00 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/17 17:29:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

typedef struct s_lefts
{
	char	left[BUFFER_SIZE];
	size_t	len;
}	t_lefts;

typedef struct s_bufs
{
	char	rdbuf[BUFFER_SIZE];
	char	*res;
	char	*misc;
	int		tlen;
	int		rdjn;
	int		msz;
}	t_bufs;
#endif
