/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:19:48 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 01:57:17 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	ft_refresh_sprite_third(t_mlx *mlx, int i)
{
	mlx->sprite[i].y_prec = mlx->sprite[i].pos_x;
	mlx->sprite[i].pos_x -= mlx->sprite[i].pdx;
	if ((int)mlx->sprite[i].pos_x != (int)mlx->sprite[i].y_prec
		&& mlx->sprite[i].pos_x > mlx->sprite[i].count_h * 64
		&& mlx->sprite[i].pos_y > mlx->sprite[i].count_w * 64
		&& mlx->sprite[i].pos_x < (mlx->sprite[i].count_h + 1) * 64
		&& mlx->sprite[i].pos_y < (mlx->sprite[i].count_w + 1) * 64)
		mlx->img.data[(int)mlx->sprite[i].pos_x * mlx->map.size_width
		+ (int)mlx->sprite[i].pos_y] = 0xFF00FF;
	mlx->sprite[i].pos_y -= mlx->sprite[i].pdy;
	mlx->map.x++;
}

int		ft_refresh_sprite_second(t_mlx *mlx, int i)
{
	mlx->map.x = 0;
	mlx->sprite[i].width = 0;
	while (mlx->map.x != 64)
	{
		if (mlx->sprite[i].pos_x < mlx->sprite[i].count_h * 64)
			mlx->sprite[i].pos_x = mlx->sprite[i].count_h * 64;
		if (mlx->sprite[i].pos_y < mlx->sprite[i].count_w * 64)
			mlx->sprite[i].pos_y = mlx->sprite[i].count_w * 64;
		if (mlx->sprite[i].pos_x >= (mlx->sprite[i].count_h + 1) * 64)
			mlx->sprite[i].pos_x = (mlx->sprite[i].count_h + 1) * 64 - 1;
		if (mlx->sprite[i].pos_y >= (mlx->sprite[i].count_w + 1) * 64)
			mlx->sprite[i].pos_y = (mlx->sprite[i].count_w + 1) * 64 - 1;
		if (mlx->map.x == 0)
		{
			mlx->sprite[i].coord_y = mlx->sprite[i].pos_x;
			mlx->sprite[i].coord_x = mlx->sprite[i].pos_y;
		}
		mlx->img.data[(int)mlx->sprite[i].pos_x * mlx->map.size_width +
		(int)mlx->sprite[i].pos_y] = 0xFF00FF;
		mlx->sprite[i].width++;
		ft_refresh_sprite_third(mlx, i);
	}
	i--;
	return (i);
}

void	ft_refresh_sprite(t_mlx *mlx)
{
	int	i;

	i = mlx->nb_sprite - 1;
	while (i >= 0)
	{
		mlx->sprite[i].pos_a = -mlx->hero.pos_a;
		if (mlx->sprite[i].pos_a < 0)
			mlx->sprite[i].pos_a += 2 * PI;
		if (mlx->sprite[i].pos_a > 2 * PI)
			mlx->sprite[i].pos_a -= 2 * PI;
		mlx->sprite[i].pdy = cos(mlx->sprite[i].pos_a);
		mlx->sprite[i].pdx = sin(mlx->sprite[i].pos_a);
		mlx->sprite[i].pos_y = (mlx->sprite[i].count_w) * 64 + 31;
		mlx->sprite[i].pos_x = (mlx->sprite[i].count_h) * 64 + 31;
		mlx->map.x = 0;
		while (mlx->map.x != 32
			&& mlx->sprite[i].pos_x > mlx->sprite[i].count_h * 64
			&& mlx->sprite[i].pos_y > mlx->sprite[i].count_w * 64)
		{
			mlx->sprite[i].pos_x += mlx->sprite[i].pdx;
			mlx->sprite[i].pos_y += mlx->sprite[i].pdy;
			mlx->map.x++;
		}
		i = ft_refresh_sprite_second(mlx, i);
	}
}

t_mlx	get_sprite(char **map, t_mlx mlx)
{
	int count_h;
	int count_w;
	int i;

	i = 0;
	if (!(mlx.sprite = (t_sprite*)malloc(sizeof(t_sprite) * mlx.nb_sprite)))
	{
		mlx.error = MALLOC_ERROR;
		ft_error(&mlx);
	}
	count_h = -1;
	while (map[++count_h][0] != 0)
	{
		count_w = -1;
		while (map[count_h][++count_w] != 0)
			if (map[count_h][count_w] == '2')
			{
				mlx.sprite[i].count_w = count_w;
				mlx.sprite[i].count_h = count_h;
				i++;
			}
	}
	ft_refresh_sprite(&mlx);
	return (mlx);
}
