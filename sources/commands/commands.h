/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/02 22:55:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include "../minishell.h"

typedef struct s_param	t_param;
int	option_cd(int choice, t_treenode *node, t_param *param, char **out);
int	option_echo(int choice, t_treenode *node, t_param *param, char **out);
int	option_env(int choice, t_treenode *node, t_param *param, char **out);
int	option_exit(int choice, t_treenode *node, t_param *param, char **out);
int	option_export(int choice, t_treenode *node, t_param *param, char **out);
int	option_pwd(int choice, t_treenode *node, t_param *param, char **out);
int	option_unset(int choice, t_treenode *node, t_param *param, char **out);
int	option_external(int choice, t_treenode *node, t_param *param, char **out);
#endif
