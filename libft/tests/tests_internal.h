/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:58:51 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/13 21:33:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <assert.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <stdio.h>
# include "../libft.h"
# include "map/mapss/mapss.h"

int	bad_alloc(int ret);
int	segfault_expected(int ret);
int	file_not_created(int ret);
void	ft_isalpha_test(void);
void	ft_isdigit_test(void);
void	ft_isalnum_test(void);
void	ft_isascii_test(void);
void	ft_isprint_test(void);
void	ft_isspace_test(void);
void	ft_strlen_test(void);
void	ft_memset_test(void);
void	ft_bzero_test(void);
void	ft_memcpy_test(void);
void	ft_memmove_test(void);
void	ft_putchar_fd_test(void);
void	ft_putendl_fd_test(void);
void	ft_putnbr_fd_test(void);
void	ft_putchar_fd_test(void);
void	ft_split_test(void);
void	ft_strlcpy_test(void);
void	ft_strlcat_test(void);
void	ft_toupper_test(void);
void	ft_tolower_test(void);
void	ft_strchr_test(void);
void	ft_strrchr_test(void);
void	ft_strncmp_test(void);
void	ft_memchr_test(void);
void	ft_memcmp_test(void);
void	ft_strnstr_test(void);
void	ft_atoi_test(void);
// don't know how to test calloc. I can check that n bytes are empty, but cannot check their state before, and also cannot check the space after.
void	ft_strdup_test(void);
void	ft_substr_test(void);
void	ft_strjoin_test(void);
void	ft_strtrim_test(void);
void	ft_split_test(void);
void	ft_itoa_test(void);
void	ft_striteri_test(void);
void	ft_strmapi_test(void);
void	ft_putchar_fd_test(void);
void	ft_putstr_fd_test(void);
void	ft_putendl_fd_test(void);
void	ft_putnbr_fd_test(void);
void	ft_lstnew_test(void);
void	ft_lstsize_test(void);
void	ft_lstadd_front_test(void);
void	ft_lstclear_test(void);
void	ft_lstlast_test(void);
void	ft_lstadd_back_test(void);
void	ft_lstdelone_test(void);
void	ft_lstmap_test(void);
void	ft_lstiter_test(void);
void	ft_list_generate_test(void);
void	ft_lltoa_base_test(void);
void	ft_ulltoa_base_test(void);
void	ft_printf_test(void);
#endif
