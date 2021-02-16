/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:03:14 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/29 17:34:46 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_read(char *str, int fd, int *r)
{
	char		buff[BUFFER_SIZE + 1];
	char		*temp;

	while ((*r = read(fd, &buff, BUFFER_SIZE)) > 0)
	{
		if (*r == -1)
			return (str);
		buff[*r] = 0;
		if (str)
		{
			temp = ft_strjoin(str, buff);
			free(str);
			str = ft_strdup(temp);
			free(temp);
		}
		else
			str = ft_strdup(buff);
		if (ft_strchr(buff, '\n'))
			return (str);
	}
	return (str);
}

char	*ft_get_line(char *str, char **line, int r)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (i < ft_strlen(str))
	{
		*line = ft_substr(str, 0, i);
		temp = ft_substr(str, i + 1, ft_strlen(str));
		free(str);
		str = ft_strdup(temp);
		free(temp);
	}
	else if (r == 0)
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char		*str[4096];
	int				r;

	if (fd < 0 || !line)
		return (-1);
	if (BUFFER_SIZE <= 0)
		return (-1);
	str[fd] = gnl_read(str[fd], fd, &r);
	if (r == -1)
		return (-1);
	if (r <= 0 && !str[fd])
	{
		*line = ft_strdup("");
		return (r);
	}
	str[fd] = ft_get_line(str[fd], line, r);
	if (r <= 0 && !str[fd])
		return (r);
	return (1);
}
