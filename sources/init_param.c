/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:10:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/22 22:31:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_param	*init_param(void)
{
	t_param	*param;

	param = ft_calloc_if(sizeof(t_param), 1);
	if (!param)
		return (0);
	return (param);
}
