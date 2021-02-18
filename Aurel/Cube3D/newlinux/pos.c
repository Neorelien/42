/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:04:19 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/12 14:05:34 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int			ft_x(int i, t_data *mlx)
{
	return (i % mlx->x);
}

int			ft_y(int i, t_data *mlx)
{
	return (i / mlx->x);
}

int			ft_y_move(float sinus, int count)
{
	static int	y_moins_un;
	int			y;

	y = 1 + sinus * count;
	if (y != y_moins_un)
	{
		y_moins_un = y;
		return (1);
	}
	y_moins_un = y;
	return (0);
}

int			ft_x_move(float cosinus, int count)
{
	static int		x_moins_un;
	int				x;

	x = 1 + cosinus * count;
	if (x != x_moins_un)
	{
		x_moins_un = x;
		return (1);
	}
	x_moins_un = x;
	return (0);
}
