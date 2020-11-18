/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzeromain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:46:27 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/16 20:48:59 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <strings.h>
void	ft_bzero(void *s, size_t n)
{
	char *temp;
	size_t i;

	i = 0;
	temp = s;
	while (n-- > 0)
	{
		temp[i] = 0;
		i++;
	}
}
int main(void)
{
	char array[] = "testtest";
	unsigned int size = sizeof(*array) * 2;
	int i = 0;
	while (i < 8)
		printf("%c\n", array[i++]);
	ft_bzero(array, size);
	i = 0;
	while (i < 8)
		printf("%c\n", array[i++]);
	return (0);
}
