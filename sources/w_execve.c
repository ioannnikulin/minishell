/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_execve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:30:29 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/09 15:47:42 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>

static void	dbg(char *fullpath, char **argv, char **envvars)
{
	int	i;

	ft_printf("starting: %s", fullpath);
	ft_printf("\nargs:\n");
	i = -1;
	while (argv[++ i])
		ft_printf(" %s", argv[i]);
	ft_printf("\nenvvars:\n");
	i = -1;
	while (envvars[++ i])
		ft_printf(" %s", envvars[i]);
	ft_printf("\n\n");
}

// emulate execve failure to make sure no memory leaks here
// check errno readings outside
int	w_execve(char *fullpath, char **argv, char **envvars, t_param *param)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (ft_assign_i(&param->opts.errno, 1, 0));
	if (pid == 0)
	{
		if (param->opts.debug_output_level & DBG_EXECVE_PREPRINT)
			dbg(fullpath, argv, envvars);
		execve(fullpath, argv, envvars);
		return (ft_assign_i(&param->opts.errno, 2, 0));
	}
	else if (wait(&ret) == -1)
		return (ft_assign_i(&param->opts.errno, 3, 0));
	return (ret >> 8);
}
