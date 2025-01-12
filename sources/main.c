/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@stiudent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:21:17 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/12 12:07:18 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_interrupt_flag;

static char	*read_input(void)
{
	char	*line;
	size_t	len;
	ssize_t	nread;

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

static int	interactive(t_param *param)
{
	while (1)
	{
		free(param->cur_command);
		param->cur_command = read_input();
		if (g_interrupt_flag)
		{
			g_interrupt_flag = 0;
			continue ;
		}
		if (!param->cur_command)
			break ;
		if (ft_strlen(param->cur_command) == 0)
			continue ;
		if (isatty(STDIN))
			add_history(param->cur_command);
		if (input_to_text_tree(param))
			break ;
		param->opts.retval = exec_text_tree(param);
		if (param->opts.exiting)
			break ;
	}
	return (param->opts.retval);
}

static int	one_cmd(t_param *param)
{
	if (param->opts.debug_output_level & DBG_ONE_CMD_ECHO)
		FT_PRINTF("[%s]\n", param->cur_command);
	param->opts.retval = input_to_text_tree(param);
	if (param->opts.retval)
		return (1);
	param->opts.retval = exec_text_tree(param);
	return (param->opts.retval);
}

static void	usage(void)
{
	FT_PRINTF("minishell usage:\n--interactive\n\tuser types in a command after command.\n\
--debug 1023\n\tbitmask for debug output verbosity.\n\
--command echo hello world\n\trun just one command and exit immediately.\n\
--trap 5\n\tmalloc with given number will fail. debugging option.\n\
--file script.sh\n\trun commands from given file.\n");
}

int	main(int argc, const char **argv, char **envp)
{
	t_param	*param;
	int		ret;

	param = param_alloc();
	if (!param)
		return (finalize(0, 0, ERR_MALLOC, 1));
	if (opts_fill(argc - 1, &argv[1], param))
		return (finalize(param, 0, 0, 2));
	pre(param);
	if (param_init(param) || param_get_cur_dir(param)
		|| param_get_envvars(param, envp))
		return (finalize(param, 0, ERR_MALLOC, 3));
	if (param->opts.interactive)
		interactive(param);
	else if (param->cur_command)
		one_cmd(param);
	else if (param->opts.file)
		FT_PRINTF("%s: %s\n", param->opts.file, ERR_NO_SCRIPT);
	else
		usage();
	ret = param->opts.retval;
	finalize(param, 0, 0, 0);
	post(param);
	exit(ret);
	return (ret);
}
