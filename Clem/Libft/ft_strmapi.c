/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:23:08 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/20 00:46:50 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*dest;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	if (!str || !f)
		return (0);
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (0);
	while (*str)
	{
		dest[i] = f(i, *str);
		str++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
