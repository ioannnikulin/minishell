/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:03:08 by taretiuk          #+#    #+#             */
/*   Updated: 2025/01/19 13:19:50 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_validation_internal.h"

static bool	print_err_message(char *token, bool ret)
{
	ERR("%s: %s `%s'\n", TXT_MINISHELL,
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

static bool	check_last_token(char *s1, char *s2, int i)
{
	if (is_operator(s2) || is_redirection(s2))
		return (print_err_message("newline", false));
	else if (i == 0)
	{
		if (is_opening_parenthesis(s1))
			return (print_err_message(s1, false));
	}
	else
	{
		if ((is_operator(s1) || is_redirection(s1)
				|| is_opening_parenthesis(s1))
			&& (is_operator(s2) || is_redirection(s2)
				|| is_opening_parenthesis(s2) || is_closing_parenthesis(s2)))
			return (print_err_message(s1, false));
	}
	return (true);
}

static bool	check_first_token(char *s)
{
	if (is_operator(s) || is_redirection(s)
		|| is_closing_parenthesis(s))
	{
		return (print_err_message(s, false));
	}
	return (true);
}

bool	validate_input(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (i == 0 && !check_first_token(tokens[i]))
			return (false);
		else if (tokens[i + 1] != NULL)
		{
			if (!check_sequent_tokens(tokens[i], tokens[i + 1]))
				return (false);
		}
		else if (tokens[i + 1] == NULL)
		{
			if (i == 0)
			{
				if (!check_last_token(tokens[0], tokens[i], i))
					return (false);
			}
			else if (!check_last_token(tokens[i - 1], tokens[i], i))
				return (false);
		}
		i++;
	}
	return (true);
}
