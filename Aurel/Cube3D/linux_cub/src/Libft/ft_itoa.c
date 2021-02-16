/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:58:08 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 11:42:44 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	intlen(unsigned int n, int *len)
{
	if (n > 9)
	{
		*len = *len + 1;
		intlen(n / 10, len);
	}
	else
		*len = *len + 1;
}

void	recurse(unsigned int n, char *str, int len)
{
	if (n > 9)
	{
		str[len - 1] = n % 10 + 48;
		recurse(n / 10, str, len - 1);
	}
	else
		str[len - 1] = n + 48;
}

char	*ft_itoa(int n1)
{
	char			*str;
	int				len;
	int				signe;
	unsigned int	n;

	if ((len = 0) || n1 < 0)
	{
		signe = 2;
		n = n1 * -1;
	}
	else
	{
		n = n1;
		signe = 1;
	}
	intlen(n, &len);
	if (!(str = (char*)malloc(sizeof(char) * len + signe)))
		return (0);
	if (signe == 2)
		*str++ = '-';
	recurse(n, str, len);
	str[len] = '\0';
	if (signe == 2)
		return (str - 1);
	return (str);
}
