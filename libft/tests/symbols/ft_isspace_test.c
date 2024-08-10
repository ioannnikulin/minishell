/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:01 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 15:59:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <limits.h>
#include <ctype.h>
//#define DEBUG

void	ft_isspace_test(void)
{
	for (int i = 0; i < 256; i ++)
	{
		#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
		printf("%i ", isspace(i));
		fflush(stdout);
		printf("%i, \t", ft_isspace(i));
		#endif
		assert((ft_isspace(i) == 0) == (isspace(i) == 0));
	}

}
