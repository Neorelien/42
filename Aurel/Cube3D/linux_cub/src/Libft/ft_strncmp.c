/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:10:52 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 17:05:33 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s3, const char *s4, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	i = 0;
	s1 = (unsigned char*)s3;
	s2 = (unsigned char*)s4;
	if (n == 0)
		return (0);
	while (n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (!s1[i])
			break ;
		i++;
		n--;
	}
	return (0);
}
