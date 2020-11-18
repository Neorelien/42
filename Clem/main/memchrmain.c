/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:54 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/16 20:16:34 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
void	*ft_memchr(const void *s, int c, unsigned long n)
{
	const unsigned char		*src;
	unsigned int	i;

	src = s;
	i = 0;
	while (n-- > 0)
	{
		if (*src == c)
			return ((void*)src);
		src++;
	}
	return (0);
}

int main(void)
{
	char dest[100] = "bonjour";
	char dest2[100] = "bonjour";
	char c = 'z';

	printf("%s	%s\n", memchr(dest, c, 5), dest);
	printf("%s	%s\n", ft_memchr(dest2, c, 5), dest2);
}
