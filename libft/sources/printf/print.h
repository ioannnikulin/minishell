/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:54:47 by inikulin          #+#    #+#             */
/*   Updated: 2025/01/18 18:46:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# ifdef PRINTF_ALLOWED
#  include <stdio.h>
#  define FT_PRINTF printf
#  define ERR printf
# else
#  define FT_PRINTF ft_printf
#  define ERR ft_errprintf

int	ft_printf(const char *s, ...);
int	ft_fprintf(int fd, const char *s, ...);
int	ft_errprintf(const char *s, ...);
# endif

int	ft_print_arr_i_2(int **val, int rows, int cols);
#endif
