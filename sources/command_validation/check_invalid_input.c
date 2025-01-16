/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:03:08 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/16 12:35:16 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_validation_internal.h"

int	print_err_message(char *error, char *token, int i, int ret)
{
	if (i == 0)
		FT_FPRINTF(STDERR, "%s: %s '%s'\n", TXT_MINISHELL, error, token);
	return (ret);
}

bool	check_sequent_tokens(char *s1, char *s2)
{
	if ((is_operator(s1) || is_redirection(s1))
		&& (is_operator(s2) || is_redirection(s2)))
		return (print_err_message(ERR_UNEXPECTED_TOKEN, s1, 0, 0));
	return (true);
}

bool	check_cmd_edges(char *s, int i)
{
	if (is_operator(s) || is_redirection(s))
	{
		if (i == 0)
			return (print_err_message(ERR_UNEXPECTED_TOKEN, s, 0, 0));
		else
			return (print_err_message(ERR_UNEXPECTED_TOKEN, "newline", 0, 0));
	}
	return (true);
}

bool	check_invalid_input(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (i == 0 && !check_cmd_edges(tokens[i], 0))
			return (0);
		else if (tokens[i + 1] != NULL)
		{
			if (!check_sequent_tokens(tokens[i], tokens[i + 1]))
				return (0);
		}
		else if (tokens[i + 1] == NULL && !check_cmd_edges(tokens[i], 1))
			return (0);
		i++;
	}
	return (true);
}
