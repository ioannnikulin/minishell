/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:27:55 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/15 13:08:15 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_INTERNAL_H
# define EXPANDER_INTERNAL_H

# include "../minishell.h"

typedef struct s_crawler
{
	char	*src;
	int		i;
	int		squote;
	int		dquote;
	int		envvar;
	int		normal;
	t_sbuf	*sbuf;
	int		errno;
	t_param	*param;
}	t_crawler;

int	expand_envvar(t_crawler *c);

#endif
