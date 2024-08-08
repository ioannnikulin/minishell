/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:10:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/08 11:06:28 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

int	init_params(t_params *params)
{
	if (insert_envvar(params, "PATH", "/usr/local/sbin"))
		finalize(0, 0, "Error initializing shell parameters\n", 1);
	return (0);
}
