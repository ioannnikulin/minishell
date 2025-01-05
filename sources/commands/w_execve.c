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
	char	*status[2];

	w_perror(ft_s4("starting: ", fullpath, "\nargs:\n", 0));
	i = -1;
	while (argv[++ i])
		w_perror(ft_s3(" ", argv[i], 0));
	perror("\nenvvars:\n");
	i = -1;
	while (envvars[++ i])
		w_perror(ft_s3(" ", envvars[i], 0));
	status[0] = ft_itoa(fcntl(STDIN_FILENO, F_GETFD));
	status[1] = ft_itoa(fcntl(STDOUT_FILENO, F_GETFD));
	if (!status[0] || !status[1])
		return (1);
	w_perror(ft_s4("\nin status: ", status[0], "\n", 0));
	w_perror(ft_s4("\nout status: ", status[1], "\n", 0));
	perror("\n\n");
	free(status[0]);
	free(status[1]);
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
