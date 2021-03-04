/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:55:20 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 17:50:25 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tempsrc;
	char	*tempdst;
	int		i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	tempsrc = (char*)src;
	tempdst = (char*)dst;
	while (n--)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}
