/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:21:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 19:30:53 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	interactive(t_param *param)
{
	int	ret;

	while (1)
	{
		free(param->cur_command);
		param->cur_command = readline(TXT_INVITATION);
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
	input_to_text_tree(param);
	exec_text_tree(param);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_param	*param;

	param = param_init();
	if (!param)
		return (1);
	if (opts_fill(argc - 1, &argv[1], param))
		return (finalize(param, 0, 0, 2));
	pre(param);
	if (param->opts.interactive)
		interactive(param);
	else if (param->cur_command)
		one_cmd(param);
	else if (param->opts.file)
		printf("%s: %s", param->opts.file, ERR_NO_SCRIPT);
	finalize(param, 0, 0, 0);
	post(param);
	return (0);
}
