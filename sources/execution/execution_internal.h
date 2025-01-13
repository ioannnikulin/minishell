/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:39 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 18:23:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_INTERNAL_H
# define EXECUTION_INTERNAL_H

# include <fcntl.h>
# include "../minishell.h"
# include "../tree_make/tree_processing_internal.h"

typedef struct s_param	t_param;
typedef struct s_executor
{
	int			retval;
	int			found;
	int			**fds;
	int			chain_length;
	t_treenode	*node;
	t_param		*param;
	int			orig_stdout;
	pid_t		*pids;
	int			errno;
}	t_executor;

# define IN 0
# define OUT 1
# define TYPE 2
# define COMMAND 1
# define TO_PIPE 2
# define FROM_PIPE 4
# define TO_OUT_FILE 8
# define FROM_IN_FILE 16
# define OUT_FILE 32
# define IN_FILE 64
# define IGNORED_FILE 128

t_executor	*make_executor(t_treenode *node, t_param *param);
int			executor_finalize(t_executor *e);
int			execute_node(t_executor *executor);
int			execute_text_tree_node(t_executor *executor);
int			exec_rec(t_executor *e);
int			redirections(t_executor *e);

int			setup_out_file(t_executor *e, t_treenode *node, int i);
int			setup_in_file(t_executor *e, t_treenode *node, int i);
int			setup_pipe(t_executor *e, t_treenode *node, int i);

int			fd_ok(int fd);
int			close_fds(t_executor *e, int tgt);
int			scroll_chain(t_executor *e, int tgt);
int			rollback_input_files_fds(t_executor *e, t_treenode *node, int i);

int			takes_part_in_pipe(t_treenode *node);
int			is_pipe_or_redir(char *s);
int			is_pipe(char *s);
int			is_pipe_or_redir(char *c);
int			from_pipe(t_treenode *node);
int			to_pipe(t_treenode *node);
int			takes_part_in_pipe(t_treenode *node);
int			is_to_out_redir(char *c);
int			is_from_in_redir(char *c);
int			is_out_file(t_treenode *node);
int			is_in_file(t_treenode *node);
int			sends_to_out_file(t_treenode *node);
int			reads_from_in_file(t_treenode *node);
int			takes_part_in_file(t_treenode *node);
#endif
