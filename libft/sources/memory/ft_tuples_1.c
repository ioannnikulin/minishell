/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tuples_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:13:02 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/05 20:28:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	**ft_s4(char *s0, char *s1, char *s2, char *s3)
{
	char	**res;

	res = ft_calloc_if(sizeof(char *) * 4, 1);
	if (!res)
		return (0);
	res[0] = s0;
	res[1] = s1;
	res[2] = s2;
	res[3] = s3;
	return (res);
}

char	**ft_s5(char **s0_3, char *s4)
{
	char	**res;

	res = ft_calloc_if(sizeof(char *) * 5, 1);
	if (!res)
		return (0);
	res[0] = s0_3[0];
	res[1] = s0_3[1];
	res[2] = s0_3[2];
	res[3] = s0_3[3];
	res[4] = s4;
	free(s0_3);
	return (res);
}

char	**ft_s6(char **s0_3, char *s4, char *s5)
{
	char	**res;

	res = ft_calloc_if(sizeof(char *) * 6, 1);
	if (!res)
		return (0);
	res[0] = s0_3[0];
	res[1] = s0_3[1];
	res[2] = s0_3[2];
	res[3] = s0_3[3];
	res[4] = s4;
	res[5] = s5;
	free(s0_3);
	return (res);
}

char	**ft_s7(char **s0_3, char *s4, char *s5, char *s6)
{
	char	**res;

	res = ft_calloc_if(sizeof(char *) * 7, 1);
	if (!res)
		return (0);
	res[0] = s0_3[0];
	res[1] = s0_3[1];
	res[2] = s0_3[2];
	res[3] = s0_3[3];
	res[4] = s4;
	res[5] = s5;
	res[6] = s6;
	free(s0_3);
	return (res);
}
