/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:18:51 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/16 20:33:47 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
int	ft_memcmp(const void *s1, const void *s2, unsigned long n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;

	str1 = s1;
	str2 = s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 > *str2 ? 1 : -1);
		str1++;
		str2++;
	}
	return (0);
}

int main(void)
{
	char dest[100] = "bonjour";
	char dest2[100] = "bonjorr";

	printf("%d	%s\n", memcmp(dest, dest2, 5), dest);
	printf("%d	%s\n", ft_memcmp(dest, dest2, 5), dest2);
}
