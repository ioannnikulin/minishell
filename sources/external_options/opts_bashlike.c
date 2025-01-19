/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_bashlike.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:27:11 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 15:46:55 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opts.h"

#ifndef FANCY_IFACE

int	opts_fill(int argc, const char **argv, t_param *param)
{
	if (argc == 0)
		return (ft_assign_i(&param->opts.interactive, 1, 0));
	param->cur_command = ft_strjoin_multi(argv, argc, " ");
	if (!param->cur_command)
		return (ft_assign_i(&param->opts.errno, 1, 1));
	if (param->opts.debug_output_level & DBG_PRINT_ARGV)
		dbg(argc, argv);
	return (0);
}
#endif