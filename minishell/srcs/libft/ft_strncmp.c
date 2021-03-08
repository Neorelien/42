/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:51:30 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/08 15:02:28 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL)
		return (0 - (int)*s2);
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2)
			return ((int)*s1 - (int)*s2);
		if (!*s1)
			break ;
		if (!*s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	return ((int)*s1 - (int)*s2);
}
