/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:12 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 12:46:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
int	option_exit(t_control control, t_treenode *node, t_param *param)
{
	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	(void)node;
	printf("exit\n");
	param->exiting = 1;
	*control.retval = 0;
	return (1);
}
