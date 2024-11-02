/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:59 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/25 01:05:51 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
int	option_env(t_control control, t_treenode *node, t_param *param)
{
	char	**lines;
	int		i;

	if (*control.found || !control.choice)
		return (0);
	*control.found = 1;
	(void)node;
	lines = get_envvars_for_execve(param);
	if (!lines)
	{
		printf("env: %s\n", ERR_MALLOC);
		return (1);
	}
	i = -1;
	while (lines[++ i])
		printf("%s\n", lines[i]);
	*control.retval = 0;
	return (1);
}
