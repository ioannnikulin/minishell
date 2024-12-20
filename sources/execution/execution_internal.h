/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/19 23:22:43 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_INTERNAL_H
# define EXECUTION_INTERNAL_H

# include "../minishell.h"

typedef struct s_param	t_param;
typedef struct s_executor
{
	int			retval;
	int			found;
	t_dlist		*in_fd;
	t_dlist		*out_fd;
	t_treenode	*node;
	t_param		*param;
}	t_executor;

t_executor	*make_executor(t_treenode *node, t_param *param);
int			set_redirs(t_executor *e);
int			unset_redirs(t_executor *e);
int			execute_node(t_executor *executor);
int			execute_text_tree_node(t_executor *executor);
int			from_pipe(t_executor *e);
int			to_pipe(t_executor *e);
int			exec_rec(t_executor *e);
#endif
