/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:08:59 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/28 16:00:49 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

// return value is ignored
int	option_env(t_executor *control, t_treenode *node, t_param *param)
{
	char	**lines;
	int		i;

	control->found = 1;
	(void)node;
	lines = get_envvars_for_execve(param);
	if (!lines)
	{
		w_perror(ft_s4("env: ", ERR_MALLOC, "%s\n", 0));
		return (1);
	}
	i = -1;
	while (lines[++ i])
		FT_PRINTF("%s\n", lines[i]);
	ft_free_ss_uptonull_null((void ***)&lines);
	control->retval = 0;
	return (1);
}
