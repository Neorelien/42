/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:10:50 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 20:09:51 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s1, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	len;
	unsigned int	i;
	char			*s;

	s = (char*)s1;
	i = 0;
	len = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
		if (i == ft_strlen(s1))
			str[i] = '\0';
	}
	return (str);
}
