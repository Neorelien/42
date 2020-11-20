/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:55:20 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 17:04:10 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *dst, int c, size_t n)
{
	unsigned char	*tempdst;
	int				i;
	unsigned char	c2;

	c2 = c;
	i = 0;
	tempdst = (unsigned char*)dst;
	while (n--)
	{
		if (tempdst[i] == c2)
			return (&tempdst[i]);
		i++;
	}
	return (0);
}
