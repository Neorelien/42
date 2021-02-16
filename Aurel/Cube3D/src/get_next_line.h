/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:51:14 by awery             #+#    #+#             */
/*   Updated: 2021/02/09 19:12:06 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ERROR  -1
# define NEXTLINE 1
# define ENDFILE 0

int		get_next_line(int fd, char **line);
char	*ft_strdup_gnl(const char *s1, int p);
char	*ft_strjoin(char *d1, char *s1, int i, int secu);
int		ft_browse_buffer(char **buffer, char **line, int i, int fd);
int		ft_clean(int fd, char **line, char **str, int reload);
int		checkerror(int fd, char **line, char **buffer, int init);
int		char_lengh(char *src);

#endif
