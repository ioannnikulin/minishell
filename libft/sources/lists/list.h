/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:01:18 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/10 00:31:07 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_list_new(void *content);
t_list	*ft_list_generate(char *texts[], int end_to);
void	ft_list_add_front(t_list **lst, t_list *new);
int		ft_list_size(t_list *lst);
t_list	*ft_list_last(t_list *lst);
void	ft_list_add_back(t_list **lst, t_list *new);
void	ft_list_delone(t_list *lst, void (*del)(void *));
void	ft_list_clear(t_list **lst, void (*del)(void *));
void	ft_list_iter(t_list *lst, void (*f)(void *));
t_list	*ft_list_map(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
