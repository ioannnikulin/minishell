/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:25:19 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/19 16:16:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_input(char *cur_command, t_param *param)
{
	char	*line;
	int		i;

	free(cur_command);
	rl_outstream = stderr;
	line = readline(TXT_INVITATION);
	rl_outstream = stdin;
	if (!line)
	{
		ERR("\nexit\n");
		param->opts.exiting = 1;
		return (0);
	}
	i = -1;
	while (line[++ i] && (line[i] == ' ' || line[i] == '\t'))
		;
	if (line[i])
		return (line);
	free(line);
	return (NULL);
}

void	usage(void)
{
	FT_PRINTF("minishell usage:\n--interactive\n\tuser types in a command after command.\n\
--debug 1023\n\tbitmask for debug output verbosity.\n\
--command echo hello world\n\trun just one command and exit immediately.\n\
--trap 5\n\tmalloc with given number will fail. debugging option.\n\
--file script.sh\n\trun commands from given file.\n");
}
