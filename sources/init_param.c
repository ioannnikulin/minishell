/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:10:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 17:41:37 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_param(t_param *param)
{
	if (insert_envvar(param, "PATH", "/usr/local/sbin"))
		finalize(0, 0, "Error initializing shell parameters\n", 1);
	return (0);
}
