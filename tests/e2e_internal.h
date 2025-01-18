/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:17:25 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 13:51:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E2E_INTERNAL_H
# define E2E_INTERNAL_H

# include "tests_internal.h"

typedef struct s_testcase
{
	char	*cmd;
	t_mapss	*exp;
	int		exp_ret;
	int		check_mallocs;
}	t_testcase;

#define UNSTABLE_RETURN_0_1 -1

int		populate(void);
void	successful_execution(t_testcase *test, int *mallocs);
void	malloc_failure_recoveries(char *cmd, int mallocs, int from_mallocs);
void	catch(char* fname, int *out, int *save);
void	catch_err(char* fname, int *out, int *save);
void	finally(int *out, int *save);
void 	finally_err(int *out, int *save);
#endif