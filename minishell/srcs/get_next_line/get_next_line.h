/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:03:25 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/03 15:41:26 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <unistd.h>
# include <stdlib.h>

char		*ft_strchr(const char *s, int c);
int			get_next_line(int fd, char **line);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
char		*ft_strjoin_gnl(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, char *src);

#endif
