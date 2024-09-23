/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:21:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/23 23:53:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* didn't use printf because can't force to flush */
static int	interactive(t_param *param)
{
	int	ret;

	printf("Starting interactive mode\n");
	while (1)
	{
		write(1, TXT_INVITATION, ft_strlen(TXT_INVITATION));
		ret = history_add(param, get_next_line(0));
		if (ret)
			break ;
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
	history_add(param, ft_strjoin_multi(ss, sz, " "));
	input_to_text_tree(param);
	exec_text_tree(param);
	finalize(param, 0, 0, 0);
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
	return (0);
}
