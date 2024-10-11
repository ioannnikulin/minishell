/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/10 01:55:21 by inikulin         ###   ########.fr       */
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
# include "commands/commands.h"

# define FREE_ENVVARS_DLISTS 1
# define FREE_ENVVARS_ENTRIES 2
# define FREE_ENVVARS_KEYS 4
# define FREE_ENVVARS_VALUES 8
# define STAGE_FULL 15

# define DBG_EXTERNAL_SEARCH_FOLDERS 1

typedef unsigned long long	t_ull;

typedef struct s_param
{
	int			errno;
	t_mapss		envvars;
	t_dlist		*envvar_path_head;
	char		*cur_command;
	t_tree		*text_tree;
	t_ull		debug_output_level;
}	t_param;

# define TEXT_TREE_ROOT "ROOT"

t_param	*param_init(void);
int		param_get_envvars(t_param *param);
int		finalize(t_param *param, int mode, char *message, int retval);
int		input_to_text_tree(t_param *param);
int		exec_text_tree(t_param *param);
#endif
