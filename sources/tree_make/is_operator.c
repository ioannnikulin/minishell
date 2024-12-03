/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:05:21 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/03 15:28:46 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing_internal.h"

int	is_operator(char *token)
{
	return (ft_strncmp(token, "&&", 2)
		|| ft_strncmp(token, "||", 2)
		|| ft_strncmp(token, ";", 1)
		|| ft_strncmp(token, "|", 1)
		|| ft_strncmp(token, "&", 1));
}
