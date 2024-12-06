/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_execve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:30:29 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/29 18:31:04 by inikulin         ###   ########.fr       */
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

// dup2 to self is a fflush
static int	parent(pid_t pid, int *errno)
{
	int	status;
	int	done;

	while (1)
	{
		done = wait(&status);
		if (done == pid || done == -1)
			break ;
	}
	dup2(STDOUT_FILENO, STDOUT_FILENO);
	if (done == -1)
		return (ft_assign_i(errno, 3, 0));
	return (status >> 8);
}

// dup2 to self is a fflush
// emulate execve failure to make sure no memory leaks here
// check errno readings outside
int	w_execve(char *fullpath, char **argv, char **envvars, t_param *param)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_assign_i(&param->opts.errno, 1, 0));
	if (pid == 0)
	{
		if (param->opts.debug_output_level & DBG_EXECVE_PREPRINT)
			dbg(fullpath, argv, envvars);
		if (param->opts.sigint_handler)
			signal(SIGINT, param->opts.sigint_handler);
		dup2(STDOUT_FILENO, STDOUT_FILENO);
		execve(fullpath, argv, envvars);
		return (ft_assign_i(&param->opts.errno, 2, 0));
	}
	else
		return (parent(pid, &param->opts.errno));
	return (1);
}
