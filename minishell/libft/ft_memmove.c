/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:48:49 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/19 23:48:52 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*tempsrc;
	char		*tempdst;
	int			i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	tempsrc = (char*)src;
	tempdst = (char*)dst;
	if (tempsrc > tempdst)
		while (n--)
		{
			tempdst[i] = tempsrc[i];
			i++;
		}
	else
		while (n--)
			tempdst[n] = tempsrc[n];
	return (dst);
}
