/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:20:47 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 12:09:13 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int	j;
	char			*str;
	char			*to_find;

	str = (char*)s1;
	to_find = (char*)s2;
	if (*to_find == 0)
		return (str);
	while (*str && len)
	{
		j = 0;
		while (str[j] == to_find[j] && len >= ft_strlen(to_find))
		{
			j++;
			if (!to_find[j])
				return (str);
		}
		str++;
		len--;
	}
	return (0);
}
