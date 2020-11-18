/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:29:33 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/18 14:23:24 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	while (*big && len > 0)
	{
		j = 0;
		while (*big == little[j])
		{
			j++;
			if (!little[j])
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (0);
}
