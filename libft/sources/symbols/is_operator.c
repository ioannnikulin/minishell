/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:05:21 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/02 20:22:40 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strings/strings_internal.h"

int	is_operator(char *token)
{
	int	sz;

	sz = 0;
	return (ft_strncmp(token, "&&", sz = ft_strlen("&&")) == 0
		|| ft_strncmp(token, "||", sz = ft_strlen("||")) == 0
		|| ft_strncmp(token, ";", sz = ft_strlen(";")) == 0
		|| ft_strncmp(token, "|", sz = ft_strlen("|")) == 0
		|| ft_strncmp(token, "&", sz = ft_strlen("&")) == 0);
}
