/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:49:30 by awery             #+#    #+#             */
/*   Updated: 2020/11/23 12:56:36 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"

int		checkerror(int fd, char **line, char *str)
{
	if (fd < 0)
		return (1);
	if (str == 0)
		if (read(fd, str, BUFFER_SIZE) == -1)
			return (1);
	if (!(line))
		return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	str[BUFFER_SIZE];

	if (checkerror(fd, line, str))
		return (-1);

	
	return (1);
}

int main()
{
	char **test;

	test = (char**)malloc(sizeof(char*) * 1);
	get_next_line(1, test);

	printf("%s", *test);
}
