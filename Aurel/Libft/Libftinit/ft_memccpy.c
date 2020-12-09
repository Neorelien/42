/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:55:20 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 20:14:54 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tempsrc;
	unsigned char	*tempdst;
	int				i;
	unsigned char	c2;

	c2 = c;
	i = 0;
	tempsrc = (unsigned char*)src;
	tempdst = (unsigned char*)dst;
	while (n--)
	{
		tempdst[i] = tempsrc[i];
		if (tempsrc[i] == c2)
			return (&tempdst[i + 1]);
		i++;
	}
	return (0);
}
