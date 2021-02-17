/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:13:05 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:13:09 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int		ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}