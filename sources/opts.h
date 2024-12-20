/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:06:16 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/06 13:42:25 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTS_H
# define OPTS_H
# include "minishell.h"

int	opt_debug(const char **act, int *i, t_param *param);
int	opt_single(const char **act, int *f, int t, t_param *param);

#endif
