/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:12:52 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:12:56 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isalpha(int c)
{
	if (c < 'A')
		return (0);
	if (c > 'Z' && (c < 'a' || c > 'z'))
		return (0);
	return (1);
}

int		ft_ismaj(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int		ft_isnum(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
