/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:58:51 by inikulin          #+#    #+#             */
/*   Updated: 2024/11/03 18:04:57 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_TEST_H
# define MEMORY_TEST_H
# include "../tests_internal.h"

int		memory_test(void);
void	ft_memset_test(void);
void	ft_bzero_test(void);
void	ft_memcpy_test(void);
void	ft_memmove_test(void);
void	ft_memchr_test(void);
void	ft_memcmp_test(void);

void	ft_calloc_if_trap_setup(int tgt);
void	ft_calloc_if_trap_count(void);
#endif
