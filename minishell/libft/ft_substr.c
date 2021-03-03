/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:49:17 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/20 00:50:35 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*dest;
	size_t	i;

	i = 0;
	str = (char *)s;
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (len)
	{
		dest[i] = str[start];
		start++;
		len--;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
