/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:54 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/18 12:34:29 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	size_t				i;

	src = s;
	i = 0;
	while (n-- > 0)
	{
		if (*src == c)
			return ((void*)src);
		src++;
	}
	return (0);
}
