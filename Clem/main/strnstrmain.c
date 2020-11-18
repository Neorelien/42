/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:29:33 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/17 11:41:17 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <strings.h>
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	while (*big)
	{
		j = 0;
		while (big[j] == little[j])
		{
			j++;
			if (!little[j])
				return ((char *)big);
		}
		big++;
	}
	return (0);
}

int	main()
{
	char str[] = "test 123 test";
	char c[] = "test 123 test";

	//printf("%d\n", strnstr(str, c, 13));
	printf("%s\n", ft_strnstr(str, c, 13));

}
