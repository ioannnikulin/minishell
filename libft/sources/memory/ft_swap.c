/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:23:23 by inikulin          #+#    #+#             */
/*   Updated: 2024/04/13 20:00:53 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_i(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap_s(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_swap_l(long *a, long *b)
{
	long	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap_ull(unsigned long long *a, unsigned long long *b)
{
	unsigned long long	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap_d(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}
