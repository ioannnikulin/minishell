/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 13:29:19 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_tolower_test(void)
{
	assert(ft_tolower('/') == '/');
	assert(ft_tolower(':') == ':');
	assert(ft_tolower('0') == '0');
	assert(ft_tolower('1') == '1');
	assert(ft_tolower('9') == '9');
	assert(ft_tolower('a') == 'a');
	assert(ft_tolower('z') == 'z');
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('Z') == 'z');
	assert(ft_tolower(2000000000) == 2000000000);
	assert(ft_tolower(-2147483648) == -2147483648);
	assert(ft_tolower(2147483647) == 2147483647);
	assert(ft_tolower(-1) == -1);
	assert(ft_tolower(128) == 128);
	assert(ft_tolower('\0') == '\0');
	assert(ft_tolower('\n') == '\n');
	assert(ft_tolower('\t') == '\t');
	assert(ft_tolower('!') == '!');
	assert(ft_tolower('@') == '@');
	assert(ft_tolower('[') == '[');
	assert(ft_tolower('`') == '`');
	assert(ft_tolower('{') == '{');
}
