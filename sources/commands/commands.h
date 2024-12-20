/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 15:42:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include "../minishell.h"
# include "../execution/execution_internal.h"

typedef struct s_param		t_param;
typedef struct s_executor	t_executor;

int		option_cd(t_executor *ctrl, t_treenode *node, t_param *param);
int		option_echo(t_executor *ctrl, t_treenode *node, t_param *param);
int		option_env(t_executor *ctrl, t_treenode *node, t_param *param);
int		option_exit(t_executor *ctrl, t_treenode *node, t_param *param);
int		option_export(t_executor *ctrl, t_treenode *node, t_param *param);
int		option_pwd(t_executor *ctrl, t_treenode *node, t_param *param);
int		option_unset(t_executor *ctrl, t_treenode *node, t_param *param);
int		option_external(t_executor *ctrl, t_treenode *node, t_param *param);

char	**get_envvars_for_execve(t_param *param);
int		parent(pid_t pid, int *errno);
#endif
