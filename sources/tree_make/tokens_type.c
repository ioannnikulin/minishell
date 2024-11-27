/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:45:09 by taretiuk          #+#    #+#             */
/*   Updated: 2024/11/26 12:05:47 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing_internal.h"

int	is_operator(char *token)
{
	return (ft_strcmp(token, "&&") == 0
		|| ft_strcmp(token, "||") == 0
		|| ft_strcmp(token, ";") == 0
		|| ft_strcmp(token, "|") == 0
		|| ft_strcmp(token, "&") == 0);
}

int	is_redirection(char *token)
{
	return (ft_strcmp(token, ">") == 0
		|| ft_strcmp(token, ">>") == 0
		|| ft_strcmp(token, "<") == 0
		|| ft_strcmp(token, "2>") == 0
		|| ft_strcmp(token, "&>") == 0);
}
