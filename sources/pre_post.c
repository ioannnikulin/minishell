/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_post.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:21:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 17:19:50 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef FT_CALLOC_IF_TRAPPED
# include "../libft/tests/memory/memory_test.h"

void	pre(void)
{
	ft_calloc_if_trap_setup();
}

void	post(void)
{
	ft_calloc_if_trap_count();
}
#else

void	pre(void)
{
	return ;
}

void	post(void)
{
	return ;
}
#endif
