/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:21:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/02 15:11:15 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	interactive(t_param *param)
{
	int	ret;

	printf("Starting interactive mode\n");
	while (1)
	{
		free(param->cur_command);
		param->cur_command = readline(TXT_INVITATION);
		add_history(param->cur_command);
		ret = input_to_text_tree(param);
		if (ret)
			break ;
		ret = exec_text_tree(param);
		if (ret)
			break ;
	}
	return (0);
}

static int	noninteractive(t_param *param, int sz, const char **ss)
{
	printf("Starting non-interactive mode\n");
	param->cur_command = ft_strjoin_multi(ss, sz, " ");
	input_to_text_tree(param);
	exec_text_tree(param);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_param	*param;

	(void)argv;
	param = init_param();
	if (!param)
		return (1);
	if (argc == 1)
		interactive(param);
	else
		noninteractive(param, argc - 1, &argv[1]);
	finalize(param, 0, 0, 0);
	return (0);
}
