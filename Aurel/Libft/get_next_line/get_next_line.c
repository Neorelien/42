/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:13:38 by awery             #+#    #+#             */
/*   Updated: 2020/12/09 23:47:00 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checkerror(int fd, char **line, char **buf, int init)
{
	int		i;
	int		readres;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !(line))
		return (1);
	if (init)
		*line = ft_strdup("", 0);
	if (buf[fd] == NULL)
	{
		if (!(buf[fd] = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (1);
		while (i <= BUFFER_SIZE)
			buf[fd][i++] = '\0';
		if ((readres = read(fd, buf[fd], BUFFER_SIZE)) == -1)
		{
			free(*line);
			*line = 0;
			return (1);
		}
		if (line[0][0] == '\0' && buf[fd][0] == '\0' && readres == 0)
			return (2);
		buf[fd][BUFFER_SIZE] = '\0';
	}
	return (0);
}

int		checkbuff(char buffer)
{
	if (buffer == '\0')
		return (0);
	if (buffer == '\n')
		return (1);
	return (-1);
}

int		ft_final(char **buffer, int i, char **line, int *retour)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(*line, buffer[retour[1]], i, 0);
	ft_clean(0, 0, &temp, 0);
	if (buffer[retour[1]][i] == '\n')
	{
		if (buffer[retour[1]][i + 1] == '\0')
			ft_clean(retour[1], 0, buffer, 0);
		else
		{
			temp = buffer[retour[1]] + i + 1;
			temp = ft_strjoin("", temp, char_lengh(temp) - 1, 1);
			ft_clean(retour[1], 0, buffer, 0);
			buffer[retour[1]] = temp;
		}
		return (retour[0]);
	}
	if (buffer[retour[1]][i] == '\0')
		ft_clean(retour[1], 0, buffer, 0);
	return (retour[0]);
}

int		ft_browse_buffer(char **buffer, char **line, int i, int fd)
{
	int			retour[2];
	char		*temp;

	while (1)
	{
		retour[1] = fd;
		retour[0] = checkbuff(buffer[fd][i]);
		if (retour[0] == 1)
			return (ft_final(buffer, i, line, retour));
		if (retour[0] == 0)
			return (ft_final(buffer, i, line, retour));
		if (buffer[fd][i + 1] == '\0')
		{
			temp = *line;
			*line = ft_strjoin(*line, buffer[fd], i, 0);
			ft_clean(0, 0, &temp, 0);
			if (ft_clean(fd, line, buffer, 1))
				return (-1);
			retour[0] = ft_browse_buffer(buffer, line, 0, fd);
			return (retour[0]);
		}
		i++;
	}
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer[4096];
	int				retour;

	if ((retour = checkerror(fd, line, buffer, 1)) == 1)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (-1);
	}
	if (retour == 2)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	retour = ft_browse_buffer(buffer, line, 0, fd);
	if (retour == 1)
		return (1);
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (0);
}
