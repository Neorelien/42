/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:55:20 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 11:51:26 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, const void *s2, size_t n)
{
	unsigned char	*temps1;
	unsigned char	*temps2;
	int				i;

	i = 0;
	temps1 = (unsigned char*)s1;
	temps2 = (unsigned char*)s2;
	while (n--)
	{
		if (temps1[i] != temps2[i])
			return (temps1[i] - temps2[i]);
		i++;
	}
	return (0);
}
