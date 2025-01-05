/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:06:16 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 13:42:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"

// returns 1 if matched
int	opt_debug(const char **act, int *i, t_param *param)
{
	if (ft_strcmp(PARAM_DEBUG_OUTPUT, act[*i]) != 0)
		return (0);
	param->opts.debug_output_level = ft_atoi(act[++ (*i)], &param->opts.errno);
	if (param->opts.errno)
	{
		(*i)--;
		param->opts.debug_output_level = 0;
		return (1);
	}
	return (1);
}

// returns 1 if matched
int	opt_single(const char **act, int *f, int t, t_param *param)
{
	if (ft_strcmp(PARAM_SINGLE_COMMAND, act[*f]) != 0)
		return (0);
	param->cur_command = ft_strjoin_multi(&act[*f + 1], t - *f - 1, " ");
	if (!param->cur_command)
		param->opts.errno = 1;
	*f = t;
	return (1);
}

int	dbg(int argc, const char **argv)
{
	int i;

	i = -1;
	while (++i < argc)
		FT_PRINTF("[%s]\n", argv[i]);
	return (0);
}