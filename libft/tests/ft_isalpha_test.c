/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:01 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 15:55:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <limits.h>
#include <ctype.h>
//#define DEBUG

void	ft_isalpha_test(void)
{
	for (int i = 0; i < 256; i ++)
	{
		#ifdef DEBUG
		printf("%i ", i);
		fflush(stdout);
		printf("%i ", isalpha(i));
		fflush(stdout);
		printf("%i, \t", ft_isalpha(i));
		#endif
		assert((ft_isalpha(i) == 0) == (isalpha(i) == 0));
	}

}
