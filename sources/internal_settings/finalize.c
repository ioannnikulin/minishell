/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:11:19 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 20:23:43 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	finalize(t_param *param, int mode, char *message, int retval)
{
	if (param)
	{
		(void)mode;
		ft_tree_free(&param->text_tree);
		ft_mapss_finalize_i(param->envvars, 0, 0);
		free(param->cur_command);
		ft_dlist_clear_s(&param->envvar_path_head, 0);
		if (param->envvar_pwd)
			ft_dlist_delone(param->envvar_pwd, ft_free_s);
		if (param->envvar_root)
			ft_dlist_delone(param->envvar_root, ft_free_s);
		free(param->opts.file);
		free(param);
	}
	rl_clear_history();
	if (message)
		FT_PRINTF("%s\n", message);
	return (retval);
}
