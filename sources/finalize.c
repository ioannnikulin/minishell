/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:11:19 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 19:35:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	finalize(t_param *param, int mode, char *message, int retval)
{
	if (param)
	{
		(void)mode;
		ft_tree_free(&param->text_tree);
		free(param->cur_command);
		ft_dlist_clear_s(&param->envvar_path_head, 0);
		free(param->opts.file);
		free(param);
	}
	if (message)
		printf("%s\n", message);
	return (retval);
}
