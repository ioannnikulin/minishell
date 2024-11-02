/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 22:58:49 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
// is there a way for echo to fail?
int	option_echo(t_control control, t_treenode *node, t_param *param)
{
	int			n;
	t_treenode	*child;

	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	(void)param;
	n = 0;
	child = node->child;
	while (child && ft_strncmp(child->content, "-n", 2) == 0)
	{
		n = 1;
		child = child->sibling_next;
	}
	while (child && child->sibling_next)
	{
		printf("%s ", (char *)child->content);
		child = child->sibling_next;
	}
	printf("%s", (char *)child->content);
	if (!n)
		printf("\n");
	*control.retval = 0;
	return (1);
}
