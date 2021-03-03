/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:48:33 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/19 23:48:36 by cmoyal           ###   ########.fr       */
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
