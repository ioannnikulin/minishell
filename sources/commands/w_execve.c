/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_execve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:30:29 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/05 20:30:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/wait.h>

static int	dbg(char *fullpath, char **argv, char **envvars)
{
	int		i;

	FT_FPRINTF(STDERR, "starting: %s\nargs:\n", fullpath);
	i = -1;
	while (argv[++ i])
		FT_FPRINTF(STDERR, "%s ", argv[i]);
	FT_FPRINTF(STDERR, "\nenvvars:\n");
	i = -1;
	while (envvars[++ i])
		FT_FPRINTF(STDERR, "%s ", envvars[i]);
	FT_FPRINTF(STDERR, "\nin status: %i\n", fcntl(STDIN_FILENO, F_GETFD));
	FT_FPRINTF(STDERR, "\nout status: %i\n\n\n", fcntl(STDOUT_FILENO, F_GETFD));
	return (0);
}

int	parent(pid_t pid, int *errno)
{
	int	status;
	int	done;

	while (1)
	{
		done = wait(&status);
		if (done == pid || done == -1)
			break ;
	}
	if (done == -1)
		return (ft_assign_i(errno, 3, 0));
	return (status >> 8);
}

// emulate execve failure to make sure no memory leaks here
// check errno readings outside
// possible data race in child's errno, but can't use mutexes in the task
int	w_execve(char *fullpath, char **argv, char **envvars, t_param *param)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_assign_i(&param->opts.errno, 1, 0));
	if (pid == 0)
	{
		if ((param->opts.debug_output_level & DBG_EXECVE_PREPRINT)
			&& dbg(fullpath, argv, envvars))
			return (ft_assign_i(&param->opts.errno, 3, 0));
		if (param->opts.sigint_handler)
			signal(SIGINT, param->opts.sigint_handler);
		execve(fullpath, argv, envvars);
		return (ft_assign_i(&param->opts.errno, 2, 0));
	}
	else
		return (parent(pid, &param->opts.errno));
	return (1);
}
