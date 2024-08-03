/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/15 12:55:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 3 

void	ft_strlen_test(void)
{
	char *tests[SZ] = {"hello", "¤", ""};
	// system strlen segfaults on NULL, so not checking it
	for (int i = 0; i <  SZ; i ++)
		assert(ft_strlen(tests[i]) == strlen(tests[i]));
}
