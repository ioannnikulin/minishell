/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:10:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/06 16:29:07 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_interrupt_flag;

static char	*cwd(void)
{
	int		sz;
	char	*tgt;

	sz = 32;
	tgt = 0;
	while (!tgt || !tgt[0])
	{
		free(tgt);
		tgt = ft_calloc_if(sizeof(char) * sz, 1);
		if (!tgt)
			return (0);
		getcwd(tgt, sz);
		sz <<= 1;
		if (sz < 0)
		{
			free(tgt);
			return (0);
		}
	}
	return (tgt);
}

int	param_get_cur_dir(t_param *param)
{
	char	*tgt;
	t_dlist	*node;

	tgt = cwd();
	if (!tgt)
		return (1);
	node = ft_dlist_new(tgt);
	if (!node)
	{
		free(tgt);
		return (2);
	}
	ft_dlist_add_front(&param->envvar_path_head, node);
	return (0);
}

t_param	*param_alloc(void)
{
	t_param	*param;

	param = ft_calloc_if(sizeof(t_param), 1);
	if (!param)
		return (0);
	param->opts.debug_output_level = 0;
	return (param);
}

static void	parent_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	param_init(t_param *param)
{
	struct sigaction	sa;

	sa.sa_handler = parent_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (2);
	param->envvars = ft_mapss_init();
	if (!param->envvars)
		return (1);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
