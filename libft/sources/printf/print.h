/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:54:47 by inikulin          #+#    #+#             */
/*   Updated: 2024/12/20 18:16:41 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

int	ft_fprintf_ss(int fd, const char **s);
int	ft_fprintf_s(int fd, const char *s);
#ifndef PRINTF_ALLOWED

int	ft_printf(const char *s, ...);
int	ft_fprintf(int fd, const char *s, ...);
#endif

int	ft_print_arr_i_2(int **val, int rows, int cols);

#endif
