/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsetmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:10:14 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/17 14:33:51 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
void	*ft_memset(void *s, int c, unsigned int n)
{
	char *temp;
	int i;

	i = 0;
	temp = s;
	while (n-- > 0)
	{
		printf("    %d\n", n);
		temp[i] = c;
		i++;
	}
	return (s);
}


int main(void)
{
	int array[] = {54, 85, 20, 63, 21};
	unsigned int size = sizeof(int) * 1;
	int i = 0;

	while (i < 5)
	{
		printf("%d\n", array[i]);
		i++;
	}
	i = 0;
	ft_memset(array, 1, size);
	while (i < 5)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (0);
}

