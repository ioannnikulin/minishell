/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil_floor_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:17:42 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/17 13:06:37 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers_test.h"
#include <math.h>
#define SZ 9
//#define DEBUG

int	ft_ceil_floor_test(void)
{
	float	tests[SZ] = {-2, -1.9, -1.1, -1, 0, 1, 1.1, 1.9, 2};
	float	exp, act;
	for (int i = 0; i < SZ; i ++)
	{
		#ifdef DEBUG
		printf("%i: %f\n", i, tests[i]);
		#endif
		act = ft_floor(tests[i]);
		exp = floorf(tests[i]);
		#ifdef DEBUG
		printf("floor: %f %f\n", exp, act);
		#endif
		assert(exp == act);
		act = ft_ceil(tests[i]);
		exp = ceil(tests[i]);
		#ifdef DEBUG
		printf("ceiling: %f %f\n", exp, act);
		#endif
		assert(exp == act);
	}
	return (0);
}
