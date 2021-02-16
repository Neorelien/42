/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:36:20 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 17:04:36 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c1)
{
	int		i;
	int		len;
	char	*str;
	char	c;

	c = c1;
	str = (char*)s;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}
