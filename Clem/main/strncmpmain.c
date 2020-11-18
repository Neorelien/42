/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmpmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:51:30 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/17 10:57:49 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (!*s1)
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	main()
{
	char str[] = "test 123 test";
	char *c = "test 153 test";

	printf("%d\n", strncmp(str, c, 10));
	printf("%d\n", ft_strncmp(str, c, 10));

}

