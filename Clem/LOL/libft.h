/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:21:59 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 15:10:21 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_strncmp(const char *s3, const char *s4, size_t n);
char	*ft_strmapi(char const *s1, char (*f)(unsigned int, char));
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *s1, size_t size);
size_t	ft_strlcat(char *dest, const char *s, size_t size);
char	*ft_strjoin(const char *d1, const char *s1);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	**ft_split(const char *s1, char charset);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n1, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(void *s1, const void *s2, size_t n);
void	*ft_memchr(void *dst, int c, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
char	*ft_itoa(int n1);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *s);

#endif
