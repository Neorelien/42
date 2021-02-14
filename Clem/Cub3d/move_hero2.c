/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:58:16 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/14 02:08:07 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	move_hero_third(t_mlx *mlx, t_map *map)
{
	if (mlx->hero.wall == 1)
	{
		mlx->hero.wall = 1;
		mlx->img.data[map->y * mlx->map.size_width + map->x] = 0xFF0000;
	}
}

int		move_hero_second(t_mlx *mlx, t_map *map, int i)
{
	if (mlx->img.data[map->y * mlx->map.size_width + map->x] == 0xFFFF00
		|| mlx->img.data[map->y * mlx->map.size_width + map->x] == 0x00FF00
		|| mlx->img.data[map->y * mlx->map.size_width + map->x] == 0xFFFFFF
		|| mlx->img.data[map->y * mlx->map.size_width + map->x] == 0x00FFFF)
	{
		mlx->hero.wall = 0;
		return (i);
	}
	else
	{
		while (i < mlx->nb_sprite)
		{
			if (mlx->sprite[i].count_h * 64 < map->y
				&& (mlx->sprite[i].count_h + 1) * 64 > map->y
				&& mlx->sprite[i].count_w * 64 < map->x
				&& (mlx->sprite[i].count_w + 1) * 64 > map->x)
			{
				mlx->hero.wall = 0;
				return (i);
			}
			i++;
		}
		move_hero_third(mlx, map);
	}
	return (i);
}

t_mlx	move_hero(t_mlx mlx)
{
	t_map	map;
	int		i;

	map.y = 0;
	map.x = 0;
	map.y = mlx.hero.pos_x + 1;
	mlx.hero.wall = 1;
	while (--map.y > mlx.hero.pos_x - 10)
	{
		map.x = mlx.hero.pos_y + 1;
		while (--map.x > mlx.hero.pos_y - 10)
		{
			i = 0;
			i = move_hero_second(&mlx, &map, i);
			if (mlx.hero.wall == 0)
				break ;
		}
	}
	return (mlx);
}
