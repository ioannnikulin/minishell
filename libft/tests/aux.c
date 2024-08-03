/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/13 15:28:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	bad_alloc(int ret)
{
	printf("ERROR: couldn't allocate memory for testing. Results unknown.\n");
	return (ret);
}

int	segfault_expected(int ret)
{
	printf("ERROR: SEGFAULT EXPECTED!\n");
	return (ret);
}

int	file_not_created(int ret)
{
	printf("ERROR: couldn't create file for testing.\n");
	return (ret);
}
