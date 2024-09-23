/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/23 23:51:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "resources.h"

# define FREE_ENVVARS_DLISTS 1
# define FREE_ENVVARS_ENTRIES 2
# define FREE_ENVVARS_KEYS 4
# define FREE_ENVVARS_VALUES 8
# define STAGE_FULL 15

typedef struct s_history_entry
{
	char					*text;
	struct s_history_entry	*next;
	struct s_history_entry	*prev;
}	t_history_entry;

typedef struct s_history
{
	t_history_entry	*last;
}	t_history;

typedef struct s_param
{
	int			errno;
	t_mapss		envvars;
	t_history	history;
	t_tree		*text_tree;
}	t_param;

# define TEXT_TREE_ROOT "ROOT"

t_param	*init_param(void);
int		finalize(t_param *param, int mode, char *message, int retval);
//int	ft_free(int choice, void **obj, int bytes, int ret);
int		input_to_text_tree(t_param *param);
int		history_add(t_param *param, char *s);
int		exec_text_tree(t_param *param);
#endif
