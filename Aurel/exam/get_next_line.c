#include "get_next_line.h"
int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (*str++)
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	int len;
	int i;
	int j;
	if (!s1 || !s2)
	{
		str = (char*)malloc(sizeof(char) * 1);
		*str = 0;
		return (str);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

int get_next_line(char **line)
{
	int r;
	char buff[2];
	char *str;
	char *temp;
	if (!line)
		return (-1);
	if (!(str = (char*)malloc(sizeof(char) * 1)))
		return (-1);
	*str = 0;
	while ((r = read(0, &buff, 1)))
	{
		buff[1] = 0;
		if (r == -1)
			return (-1);
		if (buff[0] == '\n')
			break;
		temp = str;
		if (!(str = ft_strjoin(str, buff)))
			return (-1);
		free(temp);
	}
	*line = str;
	return (r);
}


