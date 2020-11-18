/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpymain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:02:35 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/16 16:31:22 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
void *ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned int	i;
	char *d;
	const char *s;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int main(void)
{
	char str[] = "test";
	char dest[] = "bonjour";
	char dest2[] = "bonjour";

	printf("%s\n", memcpy(dest, str, 0));
	printf("%s\n", ft_memcpy(dest2, str, 0));
}
