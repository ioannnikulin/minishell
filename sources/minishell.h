/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 18:20:51 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "resources.h"
# include "commands/commands.h"

# include "tokenizing/input_processing.h"
# include "tree_make/tree_processing.h"

# define DBG_EXTERNAL_SEARCH_FOLDERS 1
# define DBG_PRINT_TREE_BEFORE_EXEC 2
# define DBG_PRINT_NODE_BEFORE_INSPECTION 4
# define DBG_EXECVE_PREPRINT 8
# define DBG_PRINT_NODE_BEFORE_EXECUTION 16
# define DBG_PRINT_TOKEN_BEFORE_EXPANSION 32
# define DBG_ONE_CMD_ECHO 64
# define DBG_FULL 127

typedef unsigned long long	t_ull;

typedef struct s_opts
{
	char	*file;
	int		calloc_trap;
	int		interactive;
	t_ull	debug_output_level;
	int		exiting;
	int		errno;
	void	(*sigint_handler)(int);
}	t_opts;

typedef struct s_flows
{
	int		pipe_fd;
	int		pipe_res;
}	t_flows;

typedef struct s_param
{
	t_mapss	*envvars;
	t_dlist	*envvar_path_head;
	char	*cur_command;
	t_tree	*text_tree;
	t_opts	opts;
	t_flows	flows;
}	t_param;

# define TEXT_TREE_ROOT "ROOT"

t_param	*param_alloc(void);
int		param_init(t_param *param);
int		opts_fill(int argc, const char **argv, t_param *param);
int		param_get_envvars(t_param *param);
int		finalize(t_param *param, int mode, char *message, int retval);
int		input_to_text_tree(t_param *param);
int		tokenize_cmd(const char *s, int *t_sz, char ***ss);
int		exec_text_tree(t_param *param);
int		execute_text_tree_node(t_param *param, t_treenode *node);
int		param_get_cur_dir(t_param *param);
int		collect_path(t_dlist *head, char **where);
int		unpack_block(t_treenode *node, char *open, char *close);
int		expand(t_treenode *node, t_param *param);
int		w_execve(char *fullpath, char **argv, char **envvars, t_param *param);
void	pre(t_param *param);
void	post(t_param *param);
#endif
