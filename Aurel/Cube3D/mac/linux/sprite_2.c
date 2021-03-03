/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:48:56 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/12 19:44:02 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

static void		support(t_data *mlx, int *i)
{
	if (cos(mlx->direction) >= 0)
	{
		write_pixel_sprite(mlx, i, 1, 0);
		write_pixel_sprite(mlx, i, 0, -1);
	}
	else
	{
		write_pixel_sprite(mlx, i, -1, 0);
		write_pixel_sprite(mlx, i, 0, -1);
	}
}

static void		support_2(t_data *mlx, int *i)
{
	if (cos(mlx->direction) >= 0)
	{
		write_pixel_sprite(mlx, i, 1, 0);
		write_pixel_sprite(mlx, i, 0, 1);
	}
	else
	{
		write_pixel_sprite(mlx, i, -1, 0);
		write_pixel_sprite(mlx, i, 0, 1);
	}
}

static void		support_3(t_data *mlx, int *i)
{
	if (sin(mlx->direction) >= 0)
		write_pixel_sprite(mlx, i, 0, -1);
	else
		write_pixel_sprite(mlx, i, 0, 1);
}

static void		super_support(t_data *mlx, int *i, int count)
{
	if (ft_x_move(cos(mlx->direction), count))
	{
		if (sin(mlx->direction) >= 0)
			support(mlx, i);
		else
			support_2(mlx, i);
	}
	else
		support_3(mlx, i);
}

int				ft_cast_ray_sprite(t_data *mlx, int sprite_nb)
{
	int i;
	int	count;

	count = 1;
	i = mlx->sprite_pos[sprite_nb][2];
	mlx->count_sprite = sprite_nb;
	mlx->data[mlx->sprite_pos[sprite_nb][2]] = mlx->sprite_pos[sprite_nb][5];
	while (ft_sprite_width(i, mlx, sprite_nb))
	{
		if (ft_y_move(sin(mlx->direction), count))
			super_support(mlx, &i, count);
		else
		{
			if (ft_x_move(cos(mlx->direction), count))
			{
				if (cos(mlx->direction) >= 0)
					write_pixel_sprite(mlx, &i, 1, 0);
				else
					write_pixel_sprite(mlx, &i, -1, 0);
			}
		}
		count++;
	}
	ft_reset_ft();
	return (i);
}
