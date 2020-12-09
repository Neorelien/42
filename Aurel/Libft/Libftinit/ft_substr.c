/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:42:04 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 19:55:10 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	s += start;
	while (*s && len)
	{
		s++;
		i++;
		len--;
	}
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	len += i;
	s -= i;
	while (*s && len--)
	{
		*str++ = *s;
		s++;
	}
	*str = '\0';
	str -= i;
	return (str);
}
