/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_post.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:21:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 18:21:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef FT_CALLOC_IF_TRAPPED
# include "../libft/tests/memory/memory_test.h"

void	pre(t_param *param)
{
	ft_calloc_if_trap_setup(param->opts.calloc_trap);
}

void	post(t_param *param)
{
	(void)param;
	ft_calloc_if_trap_count();
}
#else

void	pre(t_param *param)
{
	(void)param;
	return ;
}

void	post(t_param *param)
{
	(void)param;
	return ;
}
#endif