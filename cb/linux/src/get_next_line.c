/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:13:38 by awery             #+#    #+#             */
/*   Updated: 2021/02/09 19:11:33 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checkerror(int fd, char **line, char **buf, int init)
{
	int		i;
	int		readres;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (1);
	if (!(line))
		return (1);
	if (init)
		*line = ft_strdup_gnl("", 0);
	if (buf[0] == 0 && (buf[0] = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		while (i < BUFFER_SIZE)
			buf[0][i++] = '\0';
		if ((readres = read(fd, *buf, BUFFER_SIZE)) == -1)
		{
			free(*line);
			*line = 0;
			return (1);
		}
		if (line[0][0] == '\0' && buf[0][0] == '\0' && readres == 0)
			return (2);
		buf[0][BUFFER_SIZE] = '\0';
	}
	return (0);
}

int		checkbuff(char buffer, int i, int *o)
{
	if (buffer == '\0')
	{
		*o = 0;
		return (ENDFILE);
	}
	if (buffer == '\n')
	{
		if (i < BUFFER_SIZE - 1 - *o)
			*o = *o + i + 1;
		else
			*o = 0;
		return (NEXTLINE);
	}
	return (-1);
}

int		ft_final(char **buffer, int i, char **line, int *retour)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(*line, *buffer, i, 0);
	ft_clean(0, 0, &temp, 0);
	if (buffer[0][i] == '\n')
	{
		if (i == BUFFER_SIZE - 1 - retour[1])
			ft_clean(0, 0, buffer, 0);
		else
		{
			temp = *buffer + i + 1;
			temp = ft_strjoin("", temp, char_lengh(temp) - 1, 1);
			ft_clean(0, 0, buffer, 0);
			*buffer = temp;
		}
		return (retour[0]);
	}
	if (buffer[0][i] == '\0')
		ft_clean(0, 0, buffer, 0);
	return (retour[0]);
}

int		ft_browse_buffer(char **buffer, char **line, int i, int fd)
{
	int			retour[2];
	static int	o;
	char		*temp;

	while (1)
	{
		retour[1] = o;
		retour[0] = checkbuff(buffer[0][i], i, &o);
		if (retour[0] == NEXTLINE)
			return (ft_final(buffer, i, line, retour));
		if (retour[0] == ENDFILE)
			return (ft_final(buffer, i, line, retour));
		if (i == BUFFER_SIZE - 1 - o && (o = 0) == 0)
		{
			temp = *line;
			*line = ft_strjoin(*line, *buffer, i, 0);
			ft_clean(0, 0, &temp, 0);
			if (ft_clean(fd, line, buffer, 1))
				return (ERROR);
			retour[0] = ft_browse_buffer(buffer, line, 0, fd);
			return (retour[0]);
		}
		i++;
	}
}

int		get_next_line(int fd, char **line)
{
	static char		**buffer;
	static int		retour;

	if (buffer == 0)
	{
		buffer = (char**)malloc(sizeof(char*) * 1);
		buffer[0] = 0;
	}
	if ((retour = checkerror(fd, line, buffer, 1)) == 1)
		return (ERROR);
	if (retour == 2)
	{
		free(*buffer);
		free(buffer);
		buffer = 0;
		return (ENDFILE);
	}
	retour = ft_browse_buffer(buffer, line, 0, fd);
	if (retour == NEXTLINE)
		return (NEXTLINE);
	free(buffer);
	buffer = 0;
	return (ENDFILE);
}
