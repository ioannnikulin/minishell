/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:05:54 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/02 20:22:36 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strings/strings_internal.h"

int	is_redirection(char *token)
{
	int	sz;

	sz = 0;
	return (ft_strncmp(token, ">", sz = ft_strlen(">")) == 0
		|| ft_strncmp(token, ">>", sz = ft_strlen(">>")) == 0
		|| ft_strncmp(token, "<", sz = ft_strlen("<")) == 0
		|| ft_strncmp(token, "2>", sz = ft_strlen("2>")) == 0
		|| ft_strncmp(token, "&>", sz = ft_strlen("&>")) == 0);
}
