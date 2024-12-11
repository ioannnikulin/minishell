/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closing_parenthesis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:03:46 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/05 12:44:13 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_processing_internal.h"

int	is_closing_parenthesis(char *token)
{
	return (!ft_strncmp(token, ")", 1));
}
