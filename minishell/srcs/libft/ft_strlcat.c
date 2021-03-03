/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:22:53 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/18 12:39:52 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	char	*s;

	s = (char *)src;
	srclen = ft_strlen(s);
	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		srclen += size;
	else
		srclen += dstlen;
	if (size > dstlen)
	{
		while (*s && dstlen < (size - 1))
		{
			dst[dstlen] = *s;
			s++;
			dstlen++;
		}
	}
	dst[dstlen] = 0;
	return (srclen);
}
