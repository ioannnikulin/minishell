/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closing_parenthesis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:03:46 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/02 20:22:28 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strings/strings_internal.h"

int	is_closing_parenthesis(char *token)
{
	int	sz;

	sz = 0;
	return (ft_strncmp(token, ")", sz = ft_strlen(")")) == 0);
}
