/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:10:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/06 21:14:07 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_param	*param_init(void)
{
	t_param	*param;

	param = ft_calloc_if(sizeof(t_param), 1);
	if (!param)
		return (0);
	if (param_get_envvars(param))
		return (0);
	return (param);
}
