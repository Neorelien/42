/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:49:17 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/18 12:43:42 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	destlen;
	char	*str;
	char	*dest;

	str = (char *)s;
	if (len - start <= 0)
		return (0);
	destlen = len - start;
	dest = (char*)malloc(sizeof(char) * destlen);
	while (start < len)
	{
		*dest++ = str[start];
		start++;
	}
	return (dest - destlen);
}
