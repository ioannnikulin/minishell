/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:10:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/04 14:29:49 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_param(t_param *param)
{
	if (insert_envvar(param, "PATH", "/usr/local/sbin"))
		finalize(0, 0, ERR_ENVVAR_INSERT, 1);
	return (0);
}
