/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 16:51:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#include "stdio.h"

#ifdef PRINTF_ALLOWED

static int	wrapper(int fd, int (*f)(const void*), const void *arg)
{
	int	save;
	int	ret;

	save = dup(STDOUT_FILENO);
	if (save == -1)
	{
		perror("ft_fprintf: dup error");
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("ft_fprintf: dup2 error");
		close(save);
		return (-1);
	}
	ret = f(arg);
	if (dup2(save, STDOUT_FILENO) == -1)
		perror("ft_fprintf: dup2 error");
	close(save);
	return (ret);
}

static int	s(const void *arg)
{
	const char	*s;

	s = (const char *)arg;
	return (printf("%s", s));
}

static int	ss(const void *arg)
{
	const char	**s;
	int			ret;
	int			i;

	s = (const char **)arg;
	ret = 0;
	i = 0;
	while (s[i])
		ret += printf("%s", s[i ++]);
	return (ret);
}

// va_lists are not allowed
int	ft_fprintf_ss(int fd, const char **src)
{
	return (wrapper(fd, ss, src));
}

int	ft_fprintf_s(int fd, const char *src)
{
	void	*arg;

	arg = (void *)src;
	return (wrapper(fd, s, arg));
}

#endif
