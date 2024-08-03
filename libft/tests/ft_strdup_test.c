/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 16:13:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#define SZ 3 

void	ft_strdup_test(void)
{
	char *tests[SZ] = {"hello", "¤", ""};
	for (int i = 0; i <  SZ; i ++)
	{
		char *std = strdup(tests[i]);
		char *custom = ft_strdup(tests[i]);
		assert(strcmp(std, custom) == 0);
		free(std);
		free(custom);
	}
}
