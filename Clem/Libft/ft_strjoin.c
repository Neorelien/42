/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:26:01 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/20 00:13:54 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*dest;

	i = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = (char*)malloc(sizeof(char) * i)))
		return (0);
	i = 0;
	while (*s1)
		dest[i++] = (char)*s1++;
	while (*s2)
		dest[i++] = (char)*s2++;
	dest[i] = 0;
	return (dest);
}
