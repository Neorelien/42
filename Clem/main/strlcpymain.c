/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpymain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:02:57 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/17 18:02:53 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	char	*s;

	s = (char *)src;
	srclen = ft_strlen(s);
	if (size > 0)
	{
		while (*s && size--)
		{
			*dst = *s;
			dst++;
			s++;
		}
		*dst = '\0';
	}
	return (srclen);
}

int	main()
{
	char str[100] = "test 123 test";
	char c[100] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	char c2[100] = "test 153 test bonjour"; 
	strncpy(c, str, 4);
	printf("%s\n", c);
	printf("%zu %s\n", ft_strlcpy(c2, str, 4), c2);

}

