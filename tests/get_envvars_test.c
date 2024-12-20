/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:25:04 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/20 18:46:20 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#define SZ 1

typedef s_testcase
{
	char	**src;
	char	**exp_path;
	int		exp_path_sz;
	char	***exp_envvars;
	int		exp_envvars_sz;
}	t_testcase;

int	get_envvars_test(void)
{
	t_testcase t[SZ];

	t[0] = (t_testcase){
		{"HOME=/home/taretiuk", "GNOME_TERMINAL_SERVICE=:1.1098", "DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/101997/bus", "DOCKER_HOST=unix:///run/user/101997/docker.sock"}
		, {}
		, 0
		, {
			{"GNOME_TERMINAL_SERVICE", ":1.1098"}
			, {"DBUS_SESSION_BUS_ADDRESS", "unix:path=/run/user/101997/bus"}
			, {"DOCKER_HOST", "unix:///run/user/101997/docker.sock"}
			, {"HOME", "/home/taretiuk"}
		}
		, 4
	};

	for (int i = 0; i < SZ; i ++)
	{
		t_param param;
		assert(param_get_envvars(&param, t[i].src) == 0);
		t_mapss *exp_envvars_map = ft_mapss_gen(t[i].exp_envvars, t[i].exp_envvars_sz);
		assert(ft_mapss_ncmp(exp_envvars_map, param.envvars, t[i].exp_envvars_sz) == 0);
		t_dlist *exp_path_list = ft_dlist_generate(t[i].exp_path, t[i].exp_path_sz);
		assert(ft_dlist_ncmp(exp_path_list, param.envvar_path_head) == 0);
		ft_dlist_clear_s(param.envvar_path_head, 0);
		ft_dlist_clear_s(exp_path_list, 0);
		ft_mapss_finalize(param.envvars);
		ft_mapss_finalize(exp_envvars_map);
	}
}
