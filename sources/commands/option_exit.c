/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:12 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 18:47:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
int	option_exit(t_executor *control, t_treenode *node, t_param *param)
{
	control->found = 1;
	control->retval = 0;
	if (node->child && node->child->sibling_next)
	{
		ERR("%s: exit: %s\n", TXT_MINISHELL,
			ERR_EXIT_TOO_MANY_ARGS);
		param->opts.exiting = 1;
		return (1);
	}
	if (node->child)
		control->retval = ft_atoi(*get_node_txt(node->child),
				&param->opts.errno);
	if (param->opts.errno)
		ft_assign_i(&control->retval, 1, ERR(
				"%s: exit: %s", TXT_MINISHELL, ERR_EXIT_NO_NUMBER));
	else
		ERR("exit\n");
	control->retval %= 256;
	param->opts.exiting = 1;
	return (1);
}
