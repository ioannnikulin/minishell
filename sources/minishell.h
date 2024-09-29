/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/30 00:24:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "resources.h"

# define FREE_ENVVARS_DLISTS 1
# define FREE_ENVVARS_ENTRIES 2
# define FREE_ENVVARS_KEYS 4
# define FREE_ENVVARS_VALUES 8
# define STAGE_FULL 15

typedef struct s_param
{
	int			errno;
	t_mapss		envvars;
	char		*cur_command;
	t_tree		*text_tree;
}	t_param;

# define TEXT_TREE_ROOT "ROOT"

t_param	*init_param(void);
int		finalize(t_param *param, int mode, char *message, int retval);
//int	ft_free(int choice, void **obj, int bytes, int ret);
int		input_to_text_tree(t_param *param);
int		exec_text_tree(t_param *param);
// ==============================================
int		option_cd(int choice, t_treenode *node, t_param *param, char **out);
int		option_echo(int choice, t_treenode *node, t_param *param, char **out);
int		option_env(int choice, t_treenode *node, t_param *param, char **out);
int		option_exit(int choice, t_treenode *node, t_param *param, char **out);
int		option_export(int choice, t_treenode *node, t_param *param, char **out);
int		option_pwd(int choice, t_treenode *node, t_param *param, char **out);
int		option_unset(int choice, t_treenode *node, t_param *param, char **out);
int		option_external(int choice, t_treenode *node, t_param *param, char **out);
#endif
