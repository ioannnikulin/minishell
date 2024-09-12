/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/08 17:29:26 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_test.h"

int	strings_test(void)
{
	printf("strlen in testing\n");
	ft_strlen_test();
	printf("strlcpy in testing\n");
	ft_strlcpy_test();
	printf("strlcat in testing\n");
	ft_strlcat_test();
	printf("strchr in testing\n");
	ft_strchr_test();
	printf("strrchr in testing\n");
	ft_strrchr_test();
	printf("strncmp in testing\n");
	ft_strncmp_test();
	printf("strnstr in testing\n");
	ft_strnstr_test();
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
	printf("strmapi in testing\n");
	ft_strmapi_test();
	printf("striteri in testing\n");
	ft_striteri_test();
	printf("putchar_fd in testing\n");
	ft_putchar_fd_test();
	printf("putstr_fd in testing\n");
	ft_putstr_fd_test();
	printf("putendl_fd in testing\n");
	ft_putendl_fd_test();
	printf("putnbr_fd in testing\n");
	ft_putnbr_fd_test();
	return (0);
}
