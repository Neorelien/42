/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:29:33 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/19 12:41:10 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	while (*big && i < len)
	{
		j = 0;
		while (big[j + i] == little[j] && i + j < len)
		{
			j++;
			if (!little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
