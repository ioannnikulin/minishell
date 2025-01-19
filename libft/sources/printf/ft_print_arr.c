/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:52:08 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 18:16:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_arr_i_2(int **val, int rows, int cols)
{
	int	row;
	int	col;
	int	ret;

	row = -1;
	ret = 0;
	while (++row < rows)
	{
		col = -1;
		while (++col < cols)
			ret += FT_PRINTF("%i ", val[row][col]);
		ret += FT_PRINTF("\n");
	}
	ret += FT_PRINTF("\n");
	return (ret);
}
