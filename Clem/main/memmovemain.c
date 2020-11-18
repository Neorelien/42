/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:53:46 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/16 19:24:18 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
void *ft_memmove(void *dest, const void *src, unsigned long n)
{
	unsigned int	i;
	char *d;
	const char *s;

	d = dest;
	s = src;
	i = 0;
	if (d < s)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		while (n-- > 0)
			*(d + n) = *(s + n);
	}
	return (dest);
}

int main(void)
{
	char str[] = "test";
	char str2[] = "test";
	char *dest;
	char *dest2;
	dest = str - 2;
	dest2 = str2 - 2;
 	memmove(dest, str, 4);
	ft_memmove(dest2, str2, 4);
	int i = 0;

	while (i < 4)
		printf("%c", dest[i++]);
	printf("\n");
	i = 0;
	while (i < 4)
		printf("%c", dest2[i++]);
}
