/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:03:08 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/18 14:14:08 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_validation_internal.h"

static bool	print_err_message(char *token, bool ret)
{
	FT_FPRINTF(STDERR, "%s: %s `%s'\n", TXT_MINISHELL,
		ERR_UNEXPECTED_TOKEN, token);
	return (ret);
}

static bool	check_sequent_tokens(char *s1, char *s2)
{
	if ((is_operator(s1) || is_redirection(s1))
		&& (is_operator(s2) || is_redirection(s2)))
		return (print_err_message(s1, false));
	return (true);
}

static bool	check_cmd_edges(char *s, int i)
{
	if (is_operator(s) || is_redirection(s))
	{
		if (i == 0)
			return (print_err_message(s, false));
		else
			return (print_err_message("newline", false));
	}
	return (true);
}

bool	validate_input(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (i == 0 && !check_cmd_edges(tokens[i], 0))
			return (false);
		else if (tokens[i + 1] != NULL)
		{
			if (!check_sequent_tokens(tokens[i], tokens[i + 1]))
				return (false);
		}
		else if (tokens[i + 1] == NULL && !check_cmd_edges(tokens[i], 1))
			return (false);
		i++;
	}
	return (true);
}
