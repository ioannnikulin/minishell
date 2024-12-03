/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:05:54 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/03 16:01:13 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing_internal.h"

int	is_redirection(char *token)
{
	return (ft_strncmp(token, ">", 1)
		|| ft_strncmp(token, ">>", 2)
		|| ft_strncmp(token, "<", 1)
		|| ft_strncmp(token, "2>", 2)
		|| ft_strncmp(token, "&>", 2));
}
