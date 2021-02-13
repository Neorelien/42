/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:26:04 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 12:04:55 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *s1, size_t size)
{
	size_t	srclen;
	char	*src;

	src = (char*)s1;
	srclen = ft_strlen(src);
	if (size > 0)
	{
		while (*src && --size)
		{
			*dest = *src;
			dest++;
			src++;
		}
		*dest = '\0';
	}
	return (srclen);
}
