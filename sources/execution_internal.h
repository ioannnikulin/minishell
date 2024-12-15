/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:46:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 11:42:50 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_INTERNAL_H
# define EXECUTION_INTERNAL_H

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

t_control	*make_control(t_treenode *node, t_param *param);
int			execute_node(t_param *param, t_treenode *node,
			t_control *ctrl);
#endif
