/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:22:17 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/13 18:32:05 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int				ft_reset_ft(void)
{
	ft_y_move(0, 0);
	ft_x_move(0, 0);
	return (1);
}

void			rc_1(t_data *mlx, int *i, int *loop)
{
	if (cos(mlx->direction) >= 0)
	{
		*loop = write_pixel(mlx, i, 1, 0);
		*loop = write_pixel(mlx, i, 0, -1);
	}
	else
	{
		*loop = write_pixel(mlx, i, -1, 0);
		*loop = write_pixel(mlx, i, 0, -1);
	}
}

void			rc_2(t_data *mlx, int *i, int *loop)
{
	if (cos(mlx->direction) >= 0)
	{
		*loop = write_pixel(mlx, i, 1, 0);
		*loop = write_pixel(mlx, i, 0, 1);
	}
	else
	{
		*loop = write_pixel(mlx, i, -1, 0);
		*loop = write_pixel(mlx, i, 0, 1);
	}
}

void			rc(t_data *mlx, int *i, int *loop)
{
	if (sin(mlx->direction) >= 0)
		rc_1(mlx, i, loop);
	else
		rc_2(mlx, i, loop);
}
