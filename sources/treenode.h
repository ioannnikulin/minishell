/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treenode.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:53:47 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 12:45:57 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREENODE_H
# define TREENODE_H
# include "minishell.h"

typedef struct s_command
{
	char	*txt;
	int		in_fd;
	int		out_fd;
	pid_t	pid;
	int		type;
	void	(*free_txt)(void **data);
}	t_command;

t_treenode	*treenode_make(char *token, t_treenode *p,
				void (*free_token)(void **));
int			treenode_insert_dup(t_treenode *parent, char *token, int idx);
int			treenode_insert_nop(t_treenode *parent, char *token, int idx);
int			*get_node_type(t_treenode *node);
int			add_node_type(t_treenode *node, int type);
int			*get_node_in_fd(t_treenode *node);
int			*get_node_out_fd(t_treenode *node);
pid_t		*get_node_pid(t_treenode *node);
char		**get_node_txt(t_treenode *node);
char		*cmd_txt(void *content);
int			cmd_cmp(void *a, void *b);
#endif