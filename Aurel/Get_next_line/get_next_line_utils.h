/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:51:14 by awery             #+#    #+#             */
/*   Updated: 2020/11/23 16:47:55 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define ERROR  -1
# define NEXTLINE 1
# define ENDFILE -2
# define EMPTYBUFF 0

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
#endif
