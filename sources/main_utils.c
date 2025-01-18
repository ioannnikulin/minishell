/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:25:19 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/18 15:25:48 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_input(char *cur_command)
{
	char	*line;
	size_t	len;
	ssize_t	nread;

	free(cur_command);
	if (!isatty(STDIN))
	{
		len = 0;
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			return (NULL);
		}
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		return (line);
	}
	FT_FPRINTF(STDERR, "%s", TXT_INVITATION);
	return (readline(0));
}

void	usage(void)
{
	FT_PRINTF("minishell usage:\n--interactive\n\tuser types in a command after command.\n\
--debug 1023\n\tbitmask for debug output verbosity.\n\
--command echo hello world\n\trun just one command and exit immediately.\n\
--trap 5\n\tmalloc with given number will fail. debugging option.\n\
--file script.sh\n\trun commands from given file.\n");
}
