/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:59:06 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 12:00:40 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *s, size_t size)
{
	unsigned int	srclen;
	unsigned int	destlen;
	char			*src;

	src = (char*)s;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (size <= destlen)
		srclen += size;
	else
		srclen += destlen;
	if (size > destlen)
	{
		while (*src && destlen < (size - 1))
		{
			dest[destlen] = *src;
			src++;
			destlen++;
		}
	}
	dest[destlen] = 0;
	return (srclen);
}
