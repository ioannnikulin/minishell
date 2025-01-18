/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/18 15:13:41 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "minishell.h"

extern volatile sig_atomic_t	g_interrupt_flag;

static char	*read_input(char *cur_command)
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

/* errno set to 0 in the end - so that the execution continues
* if the parent thread fails to get back a success from child
*/
static int	interactive(t_param *param)
{
	while (1)
	{
		param->cur_command = read_input(param->cur_command);
		if (g_interrupt_flag && ft_assign_i(&g_interrupt_flag, 0, 1))
			continue ;
		if (!param->cur_command)
			break ;
		if (isatty(STDIN) && ft_strlen(param->cur_command) == 0
			&& FT_FPRINTF(STDERR, "\n"))
			continue ;
		if (isatty(STDIN))
			add_history(param->cur_command);
		if (input_to_text_tree(param) == MALFORMED_INPUT
			&& ft_assign_i(&param->opts.retval, 1, 1)
			&& ft_assign_i(&param->opts.errno, 0, 0))
			continue ;
		else if (param->opts.errno)
			break ;
		param->opts.retval = exec_text_tree(param);
		if (ft_assign_i(&param->opts.errno, 0, 1) && param->opts.exiting)
			break ;
	}
	return (param->opts.retval);
}

static int	one_cmd(t_param *param)
{
	if (param->opts.debug_output_level & DBG_ONE_CMD_ECHO)
		FT_PRINTF("[%s]\n", param->cur_command);
	param->opts.retval = input_to_text_tree(param);
	if (param->opts.retval && ft_assign_i(&param->opts.retval, 1, 1))
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
