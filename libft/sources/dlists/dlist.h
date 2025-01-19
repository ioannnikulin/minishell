/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:49:23 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/05 18:08:13 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# define ADDR 1
# define PREV 2
# define NEXT 4
# define ANGLES 8
# define CHECK 16
# define NEWLINE_BEFORE_CHECK 32

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;
t_dlist	*ft_dlist_new(void *content);
t_dlist	*ft_dlist_generate(char *texts[], int end_to);
t_dlist	*ft_dlist_generate_int(int nums[], int sz, int end_to);
void	ft_dlist_add_front(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlist_add_front_i(t_dlist **lst, int value);
int		ft_dlist_size(t_dlist *lst);
t_dlist	*ft_dlist_last(t_dlist *lst);
void	ft_dlist_add_back(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlist_add_back_s(t_dlist **lst, char *new);
void	ft_dlist_delone(t_dlist *lst, void (*del)(void *));
int		ft_dlist_clear(t_dlist **lst, void (*del)(void *), int ret);
int		ft_dlist_clear_s(t_dlist **lst, int ret);
int		ft_dlist_clear_i(t_dlist **lst, int ret);
void	ft_dlist_iter(t_dlist *lst, void (*f)(void *));
t_dlist	*ft_dlist_map(t_dlist *lst, void *(*f)(void *),
			void (*del)(void *));
int		ft_dlist_print_s(t_dlist *lst, char *delim);
int		ft_dlist_print_pi(t_dlist *lst, char *delim);
int		ft_dlist_print(t_dlist *lst, int debug_lvl, char *delim,
			void (*p)(void *));
// compares return 0 if lists equal,
// otherwise - number (not index) of first different node,
// negative if first list is smaller
int		ft_dlist_ncmp(t_dlist *a, t_dlist *b, int n,
			int (*cmp)(void *, void *));
int		ft_dlist_ncmp_str(t_dlist *a, t_dlist *b, int n);
int		ft_dlist_ncmp_i(t_dlist *a, t_dlist *b, int n);
int		ft_voidptr_strcmp(void *a, void *b);
int		ft_voidptr_icmp(void *a, void *b);
#endif
