/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:53:17 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/02 20:06:25 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLS_H
# define SYMBOLS_H

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	is_closing_parenthesis(char *token);
int	is_opening_parenthesis(char *token);
int	is_operator(char *token);
int	is_redirection(char *token);
#endif
