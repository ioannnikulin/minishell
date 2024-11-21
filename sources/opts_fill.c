/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:24:06 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 19:44:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "opts.h"

// returns non-0 on error and sets found if matched
static int	opt_interactive(const char *act, t_param *param, int *found)
{
	if (ft_strcmp(PARAM_INTERACTIVE, act) != 0)
		return (0);
	*found = 1;
	param->opts.interactive = 1;
	return (0);
}

// returns non-0 on error and sets found if matched
static int	opt_trap(const char **act, int *i, t_param *param, int *found)
{
	if (ft_strcmp(PARAM_CALLOC_TRAP, act[*i]) != 0)
		return (0);
	*found = 1;
	param->opts.calloc_trap = ft_atoi(act[++ (*i)], &param->opts.errno);
	if (param->opts.errno)
	{
		(*i)--;
		param->opts.calloc_trap = 0;
		return (1);
	}
	return (0);
}

// check no file or no rights
// returns non-0 on error and sets found if matched
static int	opt_file(const char **act, int *i, t_param *param, int *found)
{
	if (ft_strcmp(PARAM_FILE, act[*i]) != 0)
		return (0);
	*found = 1;
	param->opts.file = ft_strdup(act[++ (*i)]);
	return (0);
}

/*
* regarding return 2:
* if current argument is the last, and it isn't opt_interactive,
* this means that command line is malformed.
* only interactive can have no arguments after it
*/
int	opts_fill(int argc, const char **argv, t_param *param)
{
	int	i;
	int	found;

	i = -1;
	while (++ i < argc)
	{
		found = 0;
		if (opt_interactive(argv[i], param, &found) == 0 && found)
			continue ;
		if (i == argc - 1)
			return (2);
		if (opt_trap(argv, &i, param, &found) == 0 && found)
			continue ;
		if (opt_file(argv, &i, param, &found) == 0 && found)
			continue ;
		if (opt_debug(argv, &i, param, &found) == 0 && found)
			continue ;
		if (opt_single(argv, i, argc, param) == 0)
			break ;
		if (!found)
			return (1);
	}
	return (0);
}
