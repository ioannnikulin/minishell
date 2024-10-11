/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:44 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/12 01:14:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	option_pwd(t_control control, t_treenode *node, t_param *param)
{
	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	(void)node;
	(void)param;
	*control.retval = 1;
	return (1);
}
