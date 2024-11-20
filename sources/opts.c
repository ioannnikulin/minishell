/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:06:16 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 19:46:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"

// returns non-0 on error and sets found if matched
int	opt_debug(const char **act, int *i, t_param *param, int *found)
{
	if (ft_strcmp(PARAM_DEBUG_OUTPUT, act[*i]) != 0)
		return (0);
	*found = 1;
	param->opts.debug_output_level = ft_atoi(act[++ (*i)], &param->opts.errno);
	if (param->opts.errno)
	{
		(*i)--;
		param->opts.debug_output_level = 0;
		return (1);
	}
	return (0);
}

// returns 0 if matched
int	opt_single(const char **act, int f, int t, t_param *param)
{
	if (ft_strcmp(PARAM_SINGLE_COMMAND, act[f]) != 0)
		return (1);
	param->cur_command = ft_strjoin_multi(&act[f + 1], t - f - 1, " ");
	return (0);
}
