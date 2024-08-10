/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 13:30:55 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_toupper_test(void)
{
	assert(ft_toupper('/') == '/');
	assert(ft_toupper(':') == ':');
	assert(ft_toupper('0') == '0');
	assert(ft_toupper('1') == '1');
	assert(ft_toupper('9') == '9');
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('z') == 'Z');
	assert(ft_toupper('A') == 'A');
	assert(ft_toupper('Z') == 'Z');
	assert(ft_toupper(2000000000) == 2000000000);
	assert(ft_toupper(-2147483648) == -2147483648);
	assert(ft_toupper(2147483647) == 2147483647);
	assert(ft_toupper(-1) == -1);
	assert(ft_toupper(128) == 128);
	assert(ft_toupper('\0') == '\0');
	assert(ft_toupper('\n') == '\n');
	assert(ft_toupper('\t') == '\t');
	assert(ft_toupper('!') == '!');
	assert(ft_toupper('@') == '@');
	assert(ft_toupper('[') == '[');
	assert(ft_toupper('`') == '`');
	assert(ft_toupper('{') == '{');
}
