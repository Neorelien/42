/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:17:35 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 17:30:52 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		char_lengh(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

void	writeinjoin(char *dest, char *src, char *str)
{
	int		i;

	i = 0;
	while (*dest)
	{
		str[i++] = *dest++;
	}
	while (*src)
	{
		str[i++] = *src++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(const char *d1, const char *s1)
{
	int		ldest;
	int		lsrc;
	char	*str;
	char	*dest;
	char	*src;

	dest = (char*)d1;
	src = (char*)s1;
	ldest = char_lengh(dest);
	lsrc = char_lengh(src);
	if (!(str = (char*)malloc(sizeof(char) * ldest + lsrc + 1)))
		return (0);
	writeinjoin(dest, src, str);
	return (str);
}
