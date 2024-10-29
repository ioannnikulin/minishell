/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:59:34 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/29 17:00:22 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_calloc_if(size_t size, int choice);
void	ft_swap_i(int *a, int *b);
void	ft_swap_s(char **a, char **b);
void	ft_swap_l(long *a, long *b);
void	ft_swap_ll(long long *a, long long *b);
void	ft_swap_ull(unsigned long long *a, unsigned long long *b);
void	ft_swap_d(double *a, double *b);
void	ft_swap_c(char *a, char *b);
int		ft_assign_i(int *where, int what, int retval);
int		ft_assign_pc(char **where, char *what, int retval);
char	*ft_assign_i_pc(int *where, int what, char *retval);

int		ft_cmp_pvoid_pi(void *a, void *b);
int		ft_less_eq_pvoid_pi(void *a, void *b);
int		ft_cmp_pvoid_s(void *a, void *b);

void	*ft_new_pi_pvoid(int i);
int		*ft_new_pi(int i);

void	ft_free_s_null(void **c);
void	ft_free_s(void *c);
void	ft_free_nop(void **c);
void	ft_free_pi_null(void **p);
void	ft_free_pi(void *p);
void	ft_free_ss_sz(void **c, int sz);
void	ft_free_ss_sz_null(void ***c, int sz);

char	**ft_s2(char *s1, char *s2);
char	**ft_s3(char *s1, char *s2, char *s3);
#endif
