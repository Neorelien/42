/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:15:31 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/18 12:43:03 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strstr(char *charset, char to_find)
{
	unsigned int	j;

	j = 0;
	while (charset[j])
	{
		if (charset[j] == to_find)
			return (1);
		j++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*charset;
	char	*str;
	char	*dest;

	charset = (char *)set;
	str = (char *)s1;
	size = ft_strlen(str);
	while (ft_strstr(charset, *str))
	{
		size--;
		str++;
	}
	if (!*str)
		return (0);
	while (ft_strstr(charset, str[size - 1]))
		size--;
	if (size <= 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * size);
	ft_strlcpy(dest, str, size + 1);
	return (dest);
}
