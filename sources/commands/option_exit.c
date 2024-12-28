/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:09:12 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/28 18:20:12 by inikulin         ###   ########.fr       */
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
		ft_fprintf(STDERR_FILENO,
			"%s: exit: %s\n", TXT_MINISHELL, ERR_EXIT_TOO_MANY_ARGS);
		param->opts.exiting = 1;
		return (1);
	}
	if (node->child)
		control->retval = ft_atoi(node->child->content, &param->opts.errno);
	if (param->opts.errno)
		ft_assign_i(&control->retval, 1, ft_fprintf(STDERR_FILENO,
				"%s: exit: %s\n", TXT_MINISHELL, ERR_EXIT_NO_NUMBER));
	else
		ft_fprintf(STDERR_FILENO, "exit\n");
	control->retval %= 256;
	param->opts.exiting = 1;
	return (1);
}
