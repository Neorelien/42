/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:02:57 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/25 11:18:49 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	char	*s;

	s = (char *)src;
	srclen = ft_strlen(s);
	if (size > 0)
	{
		while (*s && --size)
		{
			*dst = *s;
			dst++;
			s++;
		}
		*dst = '\0';
	}
	return (srclen);
}
