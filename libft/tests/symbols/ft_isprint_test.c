/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:01 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 15:57:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <limits.h>
#include <ctype.h>
//#define DEBUG

void	ft_isprint_test(void)
{
	for (int i = 0; i < 256; i ++)
	{
		#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
		printf("%i ", isprint(i));
		fflush(stdout);
		printf("%i, \t", ft_isprint(i));
		#endif
		assert((ft_isprint(i) == 0) == (isprint(i) == 0));
	}

}
