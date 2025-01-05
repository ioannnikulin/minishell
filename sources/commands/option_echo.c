/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/28 19:46:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
// is there a way for echo to fail?
int	option_echo(t_executor *control, t_treenode *node, t_param *param)
{
	int			n;
	t_treenode	*child;

	control->found = 1;
	(void)param;
	n = 0;
	child = node->child;
	while (child && ft_strcmp(child->content, "-n") == 0)
	{
		n = 1;
		child = child->sibling_next;
	}
	while (child && child->sibling_next)
	{
		FT_PRINTF("%s ", (char *)child->content);
		child = child->sibling_next;
	}
	if (child)
		FT_PRINTF("%s", (char *)child->content);
	if (!n)
		FT_PRINTF("\n");
	return (ft_assign_i(&control->retval, 0, 1));
}
