/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:49:42 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/19 23:49:44 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c1)
{
	size_t	i;
	char	*str;
	int		resultat;
	char	c;

	str = (char*)s;
	c = c1;
	i = 0;
	resultat = -1;
	while (i <= ft_strlen(str))
	{
		if (s[i] == c)
			resultat = i;
		i++;
	}
	if (resultat > -1)
		return (&str[resultat]);
	return (0);
}
