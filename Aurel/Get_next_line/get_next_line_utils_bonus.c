/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:22:18 by awery             #+#    #+#             */
/*   Updated: 2020/11/30 18:17:17 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1, int o)
{
	char	*cpy;
	int		i;
	char	*src;

	src = (char*)s1;
	i = 0;
	if (!(cpy = malloc(sizeof(char) * o + 1)))
		return (0);
	while (i <= o)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		char_lengh(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

void	writeinjoin(char *dest, char *src, char *str, int *o)
{
	int		i;

	i = 0;
	while (*dest)
	{
		str[i++] = *dest++;
	}
	if ((*src == '\0') || ((*src == '\n') && o[1] == 0))
	{
		str[i++] = '\0';
		return ;
	}
	if (o[1] == 1)
		while (*src && o[0]-- >= 0)
			str[i++] = *src++;
	else
		while (*src && o[0]-- >= 0 && *src != '\n')
			str[i++] = *src++;
	str[i] = '\0';
}

char	*ft_strjoin(char *d1, char *s1, int i, int secu)
{
	int		ldest;
	char	*str;
	char	*dest;
	char	*src;
	int		p[2];

	p[0] = i;
	p[1] = secu;
	dest = (char*)d1;
	src = (char*)s1;
	ldest = char_lengh(dest);
	if (!(str = (char*)malloc(sizeof(char) * ldest + i + 2)))
	{
		return (0);
	}
	writeinjoin(dest, src, str, p);
	return (str);
}

int		ft_clean(int fd, char **line, char **buffer, int reload)
{
	int	i;

	i = 0;
	while (buffer[fd][i])
	{
		buffer[fd][i] = '\0';
		i++;
	}
	free(buffer[fd]);
	buffer[fd] = NULL;
	if (!(reload))
		return (0);
	return (checkerror(fd, line, buffer, 0));
}
