/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:22:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/08/03 17:47:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

# define FREE_ENVVARS_DLISTS 1
# define FREE_ENVVARS_ENTRIES 2
# define FREE_ENVVARS_KEYS 4
# define FREE_ENVVARS_VALUES 8
# define STAGE_FULL 15

typedef struct s_envvar // 4. contens of each double-linked list node
{
	char	*key;
	char	*value;
}	t_envvar;

typedef struct s_ssmap
{
	t_dlist	*head; // 3. double-linked list head - for the envvars associative array
	int		size;
}	t_ssmap;

typedef  struct s_history
{
	char	**commands;
	int		top;
}	t_history;

typedef struct s_command
{
	char	*source;
	char	*parts;
	int		blocks;
	int		passes_output;
}	t_command;

typedef struct s_line
{
	char	*source;
	int		source_size;
	t_dlist	*commands_head;
	int		commands_size;
}	t_line;

typedef struct s_params // 1. "global" parameter structure
{
	int			errno;
	t_ssmap		envvars; // 2. "map" (associative array) of environment variables
	t_history	history;
	
}	t_param;

#endif
