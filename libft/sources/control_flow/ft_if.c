/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:57:29 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/17 11:52:42 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_if_i(int choice, int a, int b)
{
	if (choice)
		return (a);
	return (b);
}

char	ft_if_c(int choice, char a, char b)
{
	if (choice)
		return (a);
	return (b);
}
