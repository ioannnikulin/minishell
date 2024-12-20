/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:44 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 23:22:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
int	option_pwd(t_control control, t_treenode *node, t_param *param)
{
	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	printf("%s\n", (char *)param->envvar_path_head->content);
	(void)node;
	*control.retval = 0;
	return (1);
}
