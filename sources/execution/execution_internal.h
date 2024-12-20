/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 18:19:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_INTERNAL_H
# define EXECUTION_INTERNAL_H

#include <fcntl.h>
# include "../minishell.h"

typedef struct s_param	t_param;
typedef struct s_executor
{
	int			retval;
	int			found;
	int			**fds;
	int			chain_length;
	t_treenode	*node;
	t_param		*param;
	int			errno;
}	t_executor;

# define IN 0
# define OUT 1

t_executor	*make_executor(t_treenode *node, t_param *param);
int			execute_node(t_executor *executor);
int			execute_text_tree_node(t_executor *executor);
int			exec_rec(t_executor *e);
int			redirections(t_executor *e);
int			is_pipe_or_redir(char *s);
int			is_pipe(char *s);
int			takes_part_in_pipe(t_treenode *node);
#endif
