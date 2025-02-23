/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:39 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/17 23:56:37 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
// is there a way for echo to fail?
static int	arg_n(const char *s1, char c)
{
	size_t	i;

	i = 1;
	if (!s1 || s1[0] != '-' || s1[1] == '\0')
		return (0);
	while (s1[i] && s1[i] == c)
		i ++;
	return (s1[i] == '\0');
}

int	option_echo(t_executor *control, t_treenode *node, t_param *param)
{
	int			n;
	t_treenode	*child;

	control->found = 1;
	(void)param;
	n = 0;
	child = node->child;
	while (child && arg_n(*get_node_txt(child), 'n'))
	{
		n = 1;
		child = child->sibling_next;
	}
	while (child && child->sibling_next)
	{
		FT_PRINTF("%s ", *get_node_txt(child));
		child = child->sibling_next;
	}
	if (child)
		FT_PRINTF("%s", *get_node_txt(child));
	if (!n)
		FT_PRINTF("\n");
	return (ft_assign_i(&control->retval, 0, 1));
}
