/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:22:38 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 11:41:29 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;
	int		len;
	int		i;

	len = size * count;
	i = len;
	if (!(array = malloc(len)))
		return (0);
	while (len--)
	{
		*(char*)array++ = 0;
	}
	return (array - i);
}
