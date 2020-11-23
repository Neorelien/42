/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:49:30 by awery             #+#    #+#             */
/*   Updated: 2020/11/23 17:44:05 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"

int		checkerror(int fd, char **line, char *buffer)
{
	if (fd < 0)
		return (1);
	if (buffer == 0)
		if (read(fd, buffer, BUFFER_SIZE) == -1)
			return (1);
	if (!(line))
		return (1);
	if (BUFFER_SIZE == 0)
		return (1);
	return (0);
}

char	*ft_browse_buffer(char *buffer, char **line)
{
	int	i;

	i = 0;
	while(1)
	{
		if (i == BUFFER_SIZE)
		{
			return (ERROR)
		}
		if (i == 0 && buffer[i] == '\n')
		{
			*line = ft_strdup("", i);
			if (i == BUFFER_SIZE - 1)
				return (EMPTYBUFF);
			else
				return (buffer + i + NEXTLINE);
		}
		if (i == 0 && buffer[i] == EOF)
		{
			*line = ft_strdup("");
			return (ENDFILE);
		}
		if (buffer[i] == '\n')
		{
			*line = ft_strdup(buffer, i);
			return (buffer + i + NEXTLINE);
		}
		if (buffer[i] == EOF)
		{
			*line = ft_strdup(buffer, i);
			return (ENDFILE);
		}
		i++;
	}
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];

	if (checkerror(fd, line, buffer ))
		return (-1);

	buffer = ft_browse_buffer(buffer, line);
	if (buffer == ENDFILE)
		return (ENDFILE);
	if (buffer == ERROR)
		return (ERROR);
	if (buffer || (buffer == EMPTYBUFF))
		return (NEXTLINE);
}

int main()
{
	char **test;
	int fd = open("/Users/Aurelien/Pro/42/Perso/Stud/Aurel/Get_next_line/test", O_RDONLY);
	test = (char**)malloc(sizeof(char*) * 1);
	get_next_line(fd, test);
	


	printf("%s", *test);
}
