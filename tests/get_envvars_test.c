/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:25:04 by taretiuk          #+#    #+#             */
/*   Updated: 2024/12/22 16:08:31 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_internal.h"
#define SZ 3
#define DEBUG

typedef struct s_testcase
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
		(char *[]){
			"HOME=/home/user"
			, "GNOME_TERMINAL_SERVICE=:1.1098"
			, "DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/101997/bus"
			, "DOCKER_HOST=unix:///run/user/101997/docker.sock"
			, NULL
		},
		(char *[]){
			0
		},
		0,
		(char **[]){
			(char *[]){"GNOME_TERMINAL_SERVICE", ":1.1098"},
			(char *[]){"DBUS_SESSION_BUS_ADDRESS", "unix:path=/run/user/101997/bus"},
			(char *[]){"DOCKER_HOST", "unix:///run/user/101997/docker.sock"},
			(char *[]){"HOME", "/home/user"}
		},
		4
	};
	t[1] = (t_testcase){
		(char *[]){
			"PWD=/home/user"
			, "GNOME_DESKTOP_SESSION_ID=whatever"
			, "LOGNAME=user"
			, NULL
		},
		(char *[]){
			0
		},
		0,
		(char **[]){
			(char *[]){"GNOME_DESKTOP_SESSION_ID", "whatever"}
			,(char *[]){"LOGNAME", "user"}
		},
		2
	};
	t[2] = (t_testcase){
		(char *[]){
			"PATH=/home/user/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
			, NULL
		},
		(char *[]){
			"/home/user/bin"
			, "/usr/local/sbin"
			, "/usr/local/bin"
			, "/usr/sbin"
			, "/usr/bin"
			, "/sbin"
			, "/bin"
			, NULL
		},
		7,
		(char **[]){
			0
		},
		0
	};

	for (int i = 0; i < SZ; i ++)
	{
		t_param	*param;
		param = param_alloc();
		if (!param)
			return (finalize(0, 0, ERR_MALLOC, 1));
		param->envvars = ft_mapss_init();
		if (!param->envvars)
			return (1);
		t_mapss *exp_envvars_map = ft_mapss_gen(t[i].exp_envvars, t[i].exp_envvars_sz);
		t_dlist *exp_path_list = ft_dlist_generate(t[i].exp_path, -1);
		#ifdef DEBUG
		ft_printf("\n=======Test======= %i\n", i);
		ft_printf("expected path:\n");
		ft_dlist_print_s(exp_path_list, " ");
		ft_printf("\nexpected envvars:\n");
		ft_mapss_print(exp_envvars_map);
		ft_printf("\n");
		#endif
		assert(param_get_envvars(param, t[i].src) == 0);
		#ifdef DEBUG
		ft_printf("\nactual path:\n");
		ft_dlist_print_s(param->envvar_path_head, " ");
		ft_printf("\nactual envvars:\n");
		ft_mapss_print(param->envvars);
		ft_printf("\n");
		#endif
		assert(ft_mapss_ncmp(exp_envvars_map, param->envvars, t[i].exp_envvars_sz) == 0);
		assert(ft_dlist_ncmp_str(exp_path_list, param->envvar_path_head, t[i].exp_path_sz) == 0);
		ft_dlist_clear_s(&param->envvar_path_head, 0);
		ft_dlist_clear_s(&exp_path_list, 0);
		ft_mapss_finalize_i(param->envvars, 0, 0);
		ft_mapss_finalize_i(exp_envvars_map, 0, 0);
	}
	return (0);
}
