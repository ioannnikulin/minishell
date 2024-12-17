/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:26:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 16:37:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

# define ERR_ENVVAR_INSERT "Error initializing environment variables"
# define ERR_COMMAND_NOT_FOUND "command not found"
# define ERR_NO_COMMAND_FOUND "Empty command string"
# define ERR_TEXT_TREE_EMPTY "Command analysis failed"
# define ERR_CD_NOWHERE "No such file or directory"
# define ERR_CD_NO_HOME "HOME not set"
# define ERR_EXPORT_INVALID "not a valid identifier"
# define ERR_MALLOC "failed to allocate memory"
# define ERR_NO_SCRIPT "No such file or directory"
# define ERR_CMD_ARG_UNKNOWN "argument not supported"
# define ERR_CMD_ARG_MISSING "argument incomplete"
# define ERR_UNTERMINATED_SINGLE_QUOTE "single quote block not terminated"
# define ERR_UNTERMINATED_BLOCK "block not terminated"

# define TXT_INVITATION "> "
# define TXT_MINISHELL "minishell"

# define PARAM_INTERACTIVE "--interactive"
# define PARAM_CALLOC_TRAP "--trap"
# define PARAM_FILE "--file"
# define PARAM_DEBUG_OUTPUT "--debug"
# define PARAM_SINGLE_COMMAND "--command"
#endif
