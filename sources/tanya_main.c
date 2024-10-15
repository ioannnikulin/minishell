/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tanya_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:41:54 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/15 17:06:09 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	interactive(t_param *param)
{
	int		ret;
	char	**tokens;
	
	while (1)
	{
		free(param->cur_command);
		param->cur_command = readline(TXT_INVITATION);
		tokens = parse_command(param->cur_command);
		if (tokens == NULL)
			break ;
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

int	main(int argc, const char **argv)
{
	printf("tanya works here\n");

	t_param	*param;

	(void)argv;
	param = param_init();
	if (!param)
		return (1);
	if (argc == 1)
		interactive(param);
	finalize(param, 0, 0, 0);
	return (0);
}
