/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:39 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 11:38:08 by inikulin         ###   ########.fr       */
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
	t_treenode	*node;
	t_param		*param;
	int			orig_stdout;
	int			errno;
}	t_executor;

# define IN 0
# define OUT 1

# define COMMAND 1
# define TO_PIPE 2
# define FROM_PIPE 4
# define TO_OUT_FILE 8
# define FROM_IN_FILE 16
# define OUT_FILE 32
# define IN_FILE 64
# define ANY_FILE 96
# define IGNORED_FILE 128
# define CHAIN_START 256
# define CHAIN_END 512
# define FROM_DEV_NULL 1024
# define FROM_HEREDOC 2048
# define HEREDOC 4096

# define NO_IN_FILE 104

t_executor	*make_executor(t_treenode *node, t_param *param);
int			executor_finalize(t_executor *e);
int			markup(t_executor *e);
int			execute_node(t_executor *executor);
int			execute_text_tree_node(t_executor *executor);
int			exec_rec(t_executor *e);
int			redirections(t_executor *e);
int			fd_info(t_executor *e);

int			child(t_executor *e, int tgt);
int			chain_parent(t_executor *e);

int			setup_out_file(t_executor *e, t_treenode *node);
int			setup_in_file(t_executor *e, t_treenode *node);
int			setup_pipe(t_executor *e, t_treenode *node, int i);
int			setup_dev_null(t_executor *e, t_treenode *node);

int			fd_ok(int fd);
int			close_fds(t_executor *e, int msg_src);
int			scroll_chain(t_executor *e, int tgt);
int			rollback_input_files_fds(t_executor *e, t_treenode *node);

// operator strings
int			is_pipe_or_redir(char *s);
int			is_pipe(char *s);
int			is_to_out_redir(char *c);
int			is_from_in_redir(char *c);
int			is_heredoc(char *c);

// redirection nodes
int			is_out_file(t_treenode *node);
int			is_in_file(t_treenode *node);
int			is_file(t_treenode *node);
int			is_heredoc_eof(t_treenode *node);

// supposedly command nodes
int			from_pipe(t_treenode *node);
int			to_pipe(t_treenode *node);
int			takes_part_in_pipe(t_treenode *node);
int			sends_to_out_file(t_treenode *node);
int			reads_from_in_file(t_treenode *node);
int			takes_part_in_file(t_treenode *node);
int			takes_part_in_pipe(t_treenode *node);
int			reads_from_heredoc(t_treenode *node);
int			takes_part_in_pipe_or_file(t_treenode *node);

t_treenode	*next_command(t_treenode *node);
t_treenode	*prev_command(t_treenode *node);
t_treenode	*next_node(t_treenode *node);
t_treenode	*prev_node(t_treenode *node);
#endif
