/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_perror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:05:24 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/05 17:05:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	w_perror(char **src)
{
    int		i;
    t_sbuf *buf;
    char    *txt;

    buf = ft_sbuf_make(src[0]);
    i = 0;
    while (src[++i])
        ft_sbuf_append(buf, src[i]);
    txt = ft_sbuf_get(buf);
    perror(txt);
    free(txt);
    ft_sbuf_finalize(&buf);
    free(src);
	return (0);
}