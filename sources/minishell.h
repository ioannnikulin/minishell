/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/19 13:28:40 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "resources.h"
# include "commands/commands.h"
# include "tokenizing/tokenizing.h"
# include "tree_make/tree_processing.h"
# include "command_validation/command_validation.h"
# include "treenode.h"

# define STDERR STDERR_FILENO
# define STDOUT STDOUT_FILENO
# define STDIN STDIN_FILENO

# define MALFORMED_INPUT -1

# define DBG_EXTERNAL_SEARCH_FOLDERS 1
# define DBG_PRINT_TREE_BEFORE_EXEC 2
# define DBG_PRINT_NODE_BEFORE_INSPECTION 4
# define DBG_EXECVE_PREPRINT 8
# define DBG_PRINT_NODE_BEFORE_EXECUTION 16
# define DBG_PRINT_TOKEN_BEFORE_EXPANSION 32
# define DBG_ONE_CMD_ECHO 64
# define DBG_EXEC_CHAIN_PRINT_FD_OPS 128
# define DBG_PRINT_ARGV 256
# define DBG_FULL 511

typedef unsigned long long	t_ull;

typedef struct s_opts
{
	char	*file;
	int		calloc_trap;
	int		interactive;
	t_ull	debug_output_level;
	int		exiting;
	int		retval;
	int		errno;
	void	(*sigint_handler)(int);
}	t_opts;

typedef struct s_param
{
	t_mapss	*envvars;
	t_dlist	*envvar_path_head;
	t_dlist	*envvar_pwd;
	t_dlist	*envvar_root;
	char	*cur_command;
	t_tree	*text_tree;
	t_opts	opts;
}	t_param;

# define TEXT_TREE_ROOT "ROOT"
# define TEXT_TREE_BLOCK "("

# define TEXT_TREE_BLOCK_REDIR "["

void	usage(void);
char	*read_input(char *cur_command);
t_param	*param_alloc(void);
int		param_init(t_param *param);
int		opts_fill(int argc, const char **argv, t_param *param);
int		param_get_envvars(t_param *param, char **envp);
int		finalize(t_param *param, int mode, char *message, int retval);
int		input_to_text_tree(t_param *param);
int		expand_tree(t_param *param);
int		exec_text_tree(t_param *param);
int		param_get_cur_dir(t_param *param);
int		collect_path(t_dlist *head, char **where);
int		expand(t_treenode *node, t_param *param);
int		w_execve(char *fullpath, char **argv, char **envvars, t_param *param);
void	pre(t_param *param);
void	post(t_param *param);
#endif
