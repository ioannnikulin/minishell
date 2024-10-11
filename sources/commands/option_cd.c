/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:15 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/12 01:10:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	option_cd(t_control control, t_treenode *node, t_param *param)
{
	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	(void)node;
	(void)param;
	*control.retval = 1;
	return (1);
}
