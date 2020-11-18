/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchrmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:31:09 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/17 10:41:52 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

int	main()
{
	char str[] = "test 123 test";
	char c = 'z';

	printf("%s   %s\n", strchr(str, c), str);
	printf("%s   %s\n", ft_strchr(str, c), str);

}
