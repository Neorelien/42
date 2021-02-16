/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:16:26 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:12:04 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	clear_sprite(t_mlx mlx)
{
	int i;

	i = mlx.nb_sprite - 1;
	while (i >= 0)
	{
		mlx.clear_sprite.pos_x = mlx.sprite[i].count_h * 64 - 1;
		while (++mlx.clear_sprite.pos_x < mlx.sprite[i].count_h * 64 + 64)
		{
			mlx.clear_sprite.pos_y = mlx.sprite[i].count_w * 64 - 1;
			while (++mlx.clear_sprite.pos_y < mlx.sprite[i].count_w * 64 + 64)
			{
				mlx.img.data[(int)mlx.clear_sprite.pos_x * mlx.map.size_width
					+ (int)mlx.clear_sprite.pos_y] = 0x000000;
			}
		}
		i--;
	}
}

void	clear_hero(t_mlx mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	y = mlx.hero.pos_y + 1;
	while (--y > mlx.hero.pos_y - 10)
	{
		x = mlx.hero.pos_x + 1;
		while (--x > mlx.hero.pos_x - 10)
			if (mlx.img.data[x * mlx.map.size_width + y] == 0xFFFF00
				|| mlx.img.data[(x + 10) * mlx.map.size_width + (y + 10)]
				== 0xFFFF00)
				mlx.hero.wall = 0;
			else
			{
				mlx.hero.wall = 1;
				mlx.img.data[x * mlx.map.size_width + y] = 0x000000;
			}
	}
	clear_sprite(mlx);
}
