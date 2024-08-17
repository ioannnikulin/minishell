/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 12:37:04 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "symbols_test.h"

int	symbols_test(void)
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
	printf("toupper in testing\n");
	ft_toupper_test();
	printf("tolower in testing\n");
	ft_tolower_test();
	return (0);
}
