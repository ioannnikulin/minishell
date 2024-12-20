/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:29 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/20 15:40:54 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_interrupt_flag;

static char	*read_input(void)
{
	char	*line;
	size_t	len;
	ssize_t	nread;

	if (!isatty(STDIN_FILENO))
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
	return (readline(TXT_INVITATION));
}

static int	interactive(t_param *param)
{
	int	ret;

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
		if (isatty(STDIN_FILENO))
			add_history(param->cur_command);
		ret = input_to_text_tree(param);
		if (ret)
			break ;
		ret = exec_text_tree(param);
		if (ret || param->opts.exiting)
			break ;
	}
	return (0);
}

static int	one_cmd(t_param *param)
{
	int	ret;

	if (param->opts.debug_output_level & DBG_ONE_CMD_ECHO)
		ft_printf("[%s]\n", param->cur_command);
	ret = input_to_text_tree(param);
	if (ret != 0)
		return (1);
	exec_text_tree(param);
	return (0);
}

static void	usage(void)
{
	ft_printf("minishell usage:\n--interactive\n\tuser types in a command after command.\n\
--debug 1023\n\tbitmask for debug output verbosity.\n\
--command echo hello world\n\trun just one command and exit immediately.\n\
--trap 5\n\tmalloc with given number will fail. debugging option.\n\
--file script.sh\n\trun commands from given file.\n");
}

int	main(int argc, const char **argv, char **envp)
{
	t_param	*param;

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
		ft_printf("%s: %s\n", param->opts.file, ERR_NO_SCRIPT);
	else
		usage();
	finalize(param, 0, 0, 0);
	post(param);
	return (0);
}
