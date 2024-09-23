/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:58:51 by inikulin          #+#    #+#             */
/*   Updated: 2024/09/08 17:46:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_INTERNAL_H
# define TESTS_INTERNAL_H
# include <assert.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <stdio.h>
# include "../libft.h"

int	bad_alloc(int ret);
int	segfault_expected(int ret);
int	file_not_created(int ret);

#endif