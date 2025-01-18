/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e2e_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:06:59 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/13 19:07:36 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e2e_internal.h"

void	catch(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stdout);
	*out = open(fname, O_WRONLY|O_APPEND|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stdout));
	assert (-1 != dup2(*out, fileno(stdout)));
}

void	catch_err(char* fname, int *out, int *save)
{
	remove(fname);
	fflush(stderr);
	*out = open(fname, O_WRONLY|O_APPEND|O_CREAT, 0600);
	assert (-1 != *out);
	*save = dup(fileno(stderr));
	assert (-1 != dup2(*out, fileno(stderr)));
}

void finally(int *out, int *save)
{
	fflush(stdout);
	close(*out);
	dup2(*save, fileno(stdout));
	close(*save);
}

void finally_err(int *out, int *save)
{
	fflush(stderr);
	close(*out);
	dup2(*save, fileno(stderr));
	close(*save);
}
