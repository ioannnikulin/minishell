/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:55:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/10/17 20:10:10 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include <stddef.h>

typedef struct s_delim
{
	char	*delim;
}	t_delim;

typedef struct s_delims
{
	t_delim		*delims;
	int			error;
	size_t		count;
}	t_delims;

typedef struct s_string
{
	char	*str;
}	t_string;

typedef struct s_string_array
{
	t_string	*strs;
	int			error;
	size_t		count;
}	t_strings;

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_multi(const char **ss, int sz, const char *delim);
char	*ft_strjoin_multi_free_outer(char **ss, int sz, const char *delim);
char	*ft_strjoin_multi_free_full(char **ss, int sz, const char *delim);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char delim, int *sz);
char	**ft_split_str(const char *s, const void *delim_ar, int *sz);
char	**ft_split_ex(const char *str, char c, char ex, int *sz);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_is_in(const char c, const char *set);
char	*ft_empty_string(void);
void	*ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
#endif
