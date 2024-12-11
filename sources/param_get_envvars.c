/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_get_envvars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:45:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/15 14:53:09 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#ifdef MOCK_TANIA

/* returns error code */
int	param_get_envvars(t_param *param)
{
	if (!ft_dlist_add_back_s(&param->envvar_path_head, "/usr/local/sbin")
		|| !ft_dlist_add_back_s(&param->envvar_path_head, "/usr/local/bin")
		|| !ft_dlist_add_back_s(&param->envvar_path_head, "/usr/sbin")
		|| !ft_dlist_add_back_s(&param->envvar_path_head, "/usr/bin")
		|| !ft_dlist_add_back_s(&param->envvar_path_head, "/sbin/bin")
		|| ft_mapss_add(param->envvars, "HOME", "/home/ioann")
		|| ft_mapss_add(param->envvars, "some", "BODYONCETOLDME")
	)
		return (1);
	return (0);
}

#else

/* returns error code */
int	param_get_envvars(t_param *param)
{
	(void)param;
	return (0);
}

#endif
