/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:44 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 13:57:31 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
int	option_pwd(t_executor *control, t_treenode *node, t_param *param)
{
	control->found = 1;
	FT_PRINTF("%s\n", (char *)param->envvar_path_head->content);
	(void)node;
	control->retval = 0;
	return (1);
}
