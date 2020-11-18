/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpymain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:04:58 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/16 18:48:21 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
void	*ft_memccpy(void *dest, const void *src, int c, unsigned long n)
{
	char			*d;
	const char		*s;
	unsigned int	i;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i++] == c)
			return (d + i);

	}
	return (0);
}

int main(void)
{
	char str[] = "testa";
	char dest[100] = "bonjour";
	char dest2[100] = "bonjour";
	char c = 'j';

	printf("%s	%s\n", memccpy(dest, str, c, 5), dest);
	printf("%s	%s\n", ft_memccpy(dest2, str, c, 5), dest2);
}
