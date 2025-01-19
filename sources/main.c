/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:14:27 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/18 19:11:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_interrupt_flag;

static int	interactive_body(t_param *param)
{
	free(param->cur_command);
	param->cur_command = readline(TXT_INVITATION);
	if (g_interrupt_flag)
	{
		g_interrupt_flag = 0;
		return (0);
	}
	if (!param->cur_command)
		return (1);
	if (isatty(STDIN) && ft_strlen(param->cur_command) == 0
		&& ERR("\n"))
		return (0);
	if (isatty(STDIN))
		add_history(param->cur_command);
	if (input_to_text_tree(param) == MALFORMED_INPUT
		&& ft_assign_i(&param->opts.retval, 1, 1)
		&& ft_assign_i(&param->opts.errno, 0, 0))
		return (0);
	else if (param->opts.errno)
		return (1);
	param->opts.retval = exec_text_tree(param);
	if (ft_assign_i(&param->opts.errno, 0, 1) && param->opts.exiting)
		return (1);
	return (0);
}

/* errno set to 0 in the end - so that the execution continues
* if the parent thread fails to get back a success from child
*/
static int	interactive(t_param *param)
{
	while (1)
	{
		if (interactive_body(param))
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
