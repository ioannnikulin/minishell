/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:57:30 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/27 01:32:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H

int				ft_atoi(const char *nptr, int *ok);
char			*ft_itoa(int v);
size_t			ft_lltoa_base(long long nbr, char *base, char *buf);
size_t			ft_ulltoa_base(unsigned long long nbr, char *base, char *buf);
int				*ft_min_int(int *a, int *b);
int				*ft_max_int(int *a, int *b);
int				*ft_min_int_va(int sz, ...);
int				*ft_max_int_va(int sz, ...);
double			*ft_min_dbl(double *a, double *b);
double			*ft_max_dbl(double *a, double *b);
double			*ft_min_dbl_va(int sz, ...);
double			*ft_max_dbl_va(int sz, ...);
char			*ft_min_c(char *a, char *b);
char			*ft_max_c(char *a, char *b);
char			*ft_min_c_va(int sz, ...);
char			*ft_max_c_va(int sz, ...);
unsigned char	*ft_min_uc(unsigned char *a, unsigned char *b);
unsigned char	*ft_max_uc(unsigned char *a, unsigned char *b);
unsigned char	*ft_min_uc_va(int sz, ...);
unsigned char	*ft_max_uc_va(int sz, ...);
int				ft_sign_i(int i);
#endif
