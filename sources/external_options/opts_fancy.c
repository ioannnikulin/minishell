/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_fancy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:24:06 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 15:37:51 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"

#ifdef FANCY_IFACE
// returns 1 if matched
static int	opt_interactive(const char *act, t_param *param)
{
	if (ft_strcmp(PARAM_INTERACTIVE, act) != 0)
		return (0);
	param->opts.interactive = 1;
	return (1);
}

// returns 1 if matched
static int	opt_trap(const char **act, int *i, t_param *param)
{
	if (ft_strcmp(PARAM_CALLOC_TRAP, act[*i]) != 0)
		return (0);
	param->opts.calloc_trap = ft_atoi(act[++ (*i)], &param->opts.errno);
	if (param->opts.errno)
	{
		(*i)--;
		param->opts.calloc_trap = 0;
		return (1);
	}
	return (1);
}

// check no file or no rights
// returns 1 if matched
static int	opt_file(const char **act, int *i, t_param *param)
{
	if (ft_strcmp(PARAM_FILE, act[*i]) != 0)
		return (0);
	param->opts.file = ft_strdup(act[++ (*i)]);
	if (!param->opts.file)
		param->opts.errno = 1;
	return (1);
}

/*
* regarding return 2:
* if current argument is the last, and it isn't opt_interactive,
* this means that command line is malformed.
* only interactive can have no arguments after it
*/
static int	one_opt(const char **argv, int *i, int argc, t_param *param)
{
	if (param->opts.errno)
		return (1);
	if (opt_interactive(argv[*i], param))
		return (0);
	if (*i == argc - 1)
	{
		FT_PRINTF("%s: %s\n", argv[*i], ERR_CMD_ARG_MISSING);
		return (2);
	}
	if (opt_trap(argv, i, param))
		return (0);
	if (opt_file(argv, i, param))
		return (0);
	if (opt_debug(argv, i, param))
		return (0);
	if (opt_single(argv, i, argc, param))
		return (0);
	FT_PRINTF("%s: %s\n", argv[*i], ERR_CMD_ARG_UNKNOWN);
	return (3);
}

int	opts_fill(int argc, const char **argv, t_param *param)
{
	int	i;

	i = -1;
	if (argc == 0)
		return (ft_assign_i(&param->opts.interactive, 1, 0));
	while (++ i < argc)
	{
		if (one_opt(argv, &i, argc, param))
			return (2);
	}
	if (param->opts.errno)
		return (1);
	if (param->opts.debug_output_level & DBG_PRINT_ARGV)
		dbg(argc, argv);
	return (0);
}
#endif