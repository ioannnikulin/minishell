/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/13 13:21:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AUX_PRINTF_H
# define AUX_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

typedef struct s_params
{
	unsigned char	hex_prefix;
	unsigned char	left_zero_pad;
	unsigned char	left_space_pad;
	unsigned char	space_before_positive;
	unsigned char	sign_mandatory;
	unsigned char	capital_hex;
	int				precision;
	int				min_width;

}	t_params;

int	parse_conversion(char **c, va_list *argv, int fd);
int	put_c(char **c, va_list *argv, int fd, t_params params);
int	put_s(char **c, va_list *argv, int fd, t_params params);
int	put_p(char **c, va_list *argv, int fd, t_params params);
int	put_d(char **c, va_list *argv, int fd, t_params params);
int	put_u(char **c, va_list *argv, int fd, t_params params);
int	put_x(char **c, va_list *argv, int fd, t_params params);
int	put_percent(char **c, va_list *argv, int fd, t_params params);
int	pad_n_put(char *c, int l, int fd, t_params params);
#endif
