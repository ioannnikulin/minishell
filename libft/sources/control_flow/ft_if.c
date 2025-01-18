/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:57:29 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 17:48:37 by inikulin         ###   ########.fr       */
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

char	*ft_if_s(int choice, char *a, char *b)
{
	if (choice)
		return (a);
	return (b);
}
