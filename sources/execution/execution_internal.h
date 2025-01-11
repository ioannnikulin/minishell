/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:39 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/11 16:07:11 by inikulin         ###   ########.fr       */
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

t_executor	*make_executor(t_treenode *node, t_param *param);
int			executor_finalize(t_executor *e);
int			execute_node(t_executor *executor);
int			execute_text_tree_node(t_executor *executor);
int			exec_rec(t_executor *e);
int			redirections(t_executor *e);
int			takes_part_in_pipe(t_treenode *node);
int			setup_file(t_executor *e, t_treenode *node, int i);
int			close_pipes(t_executor *e);
int			setup_pipe(t_executor *e, int i);
int			fd_ok(int fd);

int			is_pipe_or_redir(char *s);
int			is_pipe(char *s);
int			is_pipe_or_redir(char *c);
int			from_pipe(t_treenode *node);
int			to_pipe(t_treenode *node);
int			takes_part_in_pipe(t_treenode *node);
int			is_file(char *c);
int		 	from_file(t_treenode *node);
int 		to_file(t_treenode *node);
int			takes_part_in_file(t_treenode *node);
#endif
