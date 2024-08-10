/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/10 12:40:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

int	main(void)
{
	printf("isalpha in testing\n");
	ft_isalpha_test();
	printf("isdigit in testing\n");
	ft_isdigit_test();
	printf("isalnum in testing\n");
	ft_isalnum_test();
	printf("isascii in testing\n");
	ft_isascii_test();
	printf("isprint in testing\n");
	ft_isprint_test();
	printf("strlen in testing\n");
	ft_strlen_test();
	printf("memset in testing\n");
	ft_memset_test();
	printf("bzero in testing\n");
	ft_bzero_test();
	printf("memcpy in testing\n");
	ft_memcpy_test();
	printf("memmove in testing\n");
	ft_memmove_test();
	printf("strlcpy in testing\n");
	ft_strlcpy_test();
	printf("strlcat in testing\n");
	ft_strlcat_test();
	printf("toupper in testing\n");
	ft_toupper_test();
	printf("tolower in testing\n");
	ft_tolower_test();
	printf("strchr in testing\n");
	ft_strchr_test();
	printf("strrchr in testing\n");
	ft_strrchr_test();
	printf("strncmp in testing\n");
	ft_strncmp_test();
	printf("memchr in testing\n");
	ft_memchr_test();
	printf("strnstr in testing\n");
	ft_strnstr_test();
//	printf("atoi in testing\n");
//	ft_atoi_test();
	printf("strdup in testing\n");
	ft_strdup_test();
	printf("substr in testing\n");
	ft_substr_test();
	printf("strjoin in testing\n");
	ft_strjoin_test();
	printf("strtrim in testing\n");
	ft_strtrim_test();
	printf("split in testing\n");
	ft_split_test();
//	printf("itoa in testing\n");
//	ft_itoa_test();
//	printf("strmapi in testing\n");
//	ft_strmapi_test();
	printf("striteri in testing\n");
	ft_striteri_test();
	printf("putchar_fd in testing\n");
	ft_putchar_fd_test();
//	printf("putstr_fd in testing\n");
//	ft_putstr_fd_test();
	printf("putendl_fd in testing\n");
	ft_putendl_fd_test();
	printf("putnbr_fd in testing\n");
	ft_putnbr_fd_test();
	printf("lstnew in testing\n");
	ft_lstnew_test();
	printf("lstsize in testing\n");
	ft_lstsize_test();
	printf("lstadd_front in testing\n");
	ft_lstadd_front_test();
	printf("lstclear in testing\n");
	ft_lstclear_test();
	printf("ft_lstlast in testing\n");
	ft_lstlast_test();
	printf("lstadd_back in testing\n");
	ft_lstadd_back_test();
	printf("lstdelone in testing\n");
	ft_lstdelone_test();
	printf("lstmap in testing\n");
	ft_lstmap_test();
	printf("lstiter in testing\n");
	ft_lstiter_test();
	printf("ft_list_generate in testing\n");
	ft_list_generate_test();
/*	printf("ft_lltoa_base in testing\n");
	ft_lltoa_base_test();
	printf("ft_ulltoa_base in testing\n");
	ft_ulltoa_base_test();
	printf("ft_printf in testing\n");
	ft_printf_test();*/
	printf("All tests passed successfully!\n");
	return (0);
}
