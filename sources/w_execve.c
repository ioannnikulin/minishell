/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_execve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:30:29 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/22 23:02:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>

// emulate execve failure to make sure no memory leaks here
// check errno readings outside
int	w_execve(char *fullpath, char **argv, char **envvars, int *errno)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
		return (ft_assign_i(errno, 1, 0));
	if (pid == 0)
	{
		execve(fullpath, argv, envvars);
		return (ft_assign_i(errno, 2, 0));
	}
	if (wait(&ret) == -1)
		return (ft_assign_i(errno, 3, 0));
	return (ret);
}
