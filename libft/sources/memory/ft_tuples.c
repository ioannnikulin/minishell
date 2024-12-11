/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tuples.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:13:02 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/26 23:34:46 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	**ft_s2(char *s1, char *s2)
{
	char	**res;

	res = ft_calloc_if(sizeof(char *) * 2, 1);
	if (!res)
		return (0);
	res[0] = s1;
	res[1] = s2;
	return (res);
}

char	**ft_s3(char *s1, char *s2, char *s3)
{
	char	**res;

	res = ft_calloc_if(sizeof(char *) * 3, 1);
	if (!res)
		return (0);
	res[0] = s1;
	res[1] = s2;
	res[2] = s3;
	return (res);
}

char	***ft_ss2(char **s1, char **s2)
{
	char	***res;

	res = ft_calloc_if(sizeof(char **) * 2, 1);
	if (!res)
		return (0);
	res[0] = s1;
	res[1] = s2;
	return (res);
}

char	***ft_ss3(char **s1, char **s2, char **s3)
{
	char	***res;

	res = ft_calloc_if(sizeof(char **) * 3, 1);
	if (!res)
		return (0);
	res[0] = s1;
	res[1] = s2;
	res[2] = s3;
	return (res);
}
