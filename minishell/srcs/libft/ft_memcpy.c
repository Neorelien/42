/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:48:13 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/19 23:48:19 by cmoyal           ###   ########.fr       */
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
