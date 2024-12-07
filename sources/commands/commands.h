/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/07 18:57:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include "../minishell.h"

typedef struct s_param	t_param;
typedef struct s_control
{
	int	retval;
	int	found;
	int	in_fd;
	int	out_fd;
}	t_control;

int		option_cd(t_control *ctrl, t_treenode *node, t_param *param);
int		option_echo(t_control *ctrl, t_treenode *node, t_param *param);
int		option_env(t_control *ctrl, t_treenode *node, t_param *param);
int		option_exit(t_control *ctrl, t_treenode *node, t_param *param);
int		option_export(t_control *ctrl, t_treenode *node, t_param *param);
int		option_pwd(t_control *ctrl, t_treenode *node, t_param *param);
int		option_unset(t_control *ctrl, t_treenode *node, t_param *param);
int		option_external(t_control *ctrl, t_treenode *node, t_param *param);

char	**get_envvars_for_execve(t_param *param);
#endif
