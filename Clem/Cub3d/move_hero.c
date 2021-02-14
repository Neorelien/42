/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:16:26 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/14 02:16:37 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	rl_move(t_mlx *mlx)
{
	mlx->hero.tdx = cos(mlx->hero.pos_a + 1.5708) * 5;
	mlx->hero.tdy = sin(mlx->hero.pos_a + 1.5708) * 5;
}

void	hero_new_pos_second(int key, t_mlx *mlx)
{
	if (key == 2)
	{
		rl_move(mlx);
		mlx->hero.pos_x += mlx->hero.tdx;
		mlx->hero.pos_y += mlx->hero.tdy;
		if (move_hero(*mlx).hero.wall == 0)
		{
			mlx->hero.pos_x -= mlx->hero.tdx;
			mlx->hero.pos_y -= mlx->hero.tdy;
		}
	}
	else if (key == 0)
	{
		rl_move(mlx);
		mlx->hero.pos_x -= mlx->hero.tdx;
		mlx->hero.pos_y -= mlx->hero.tdy;
		if (move_hero(*mlx).hero.wall == 0)
		{
			mlx->hero.pos_x += mlx->hero.tdx;
			mlx->hero.pos_y += mlx->hero.tdy;
		}
	}
}

t_mlx	hero_new_pos(int key, t_mlx mlx)
{
	clear_hero(mlx);
	if (key == 13)
	{
		mlx.hero.pos_x -= mlx.hero.pdx;
		mlx.hero.pos_y -= mlx.hero.pdy;
		if (move_hero(mlx).hero.wall == 0)
		{
			mlx.hero.pos_x += mlx.hero.pdx;
			mlx.hero.pos_y += mlx.hero.pdy;
		}
	}
	else if (key == 1)
	{
		mlx.hero.pos_x += mlx.hero.pdx;
		mlx.hero.pos_y += mlx.hero.pdy;
		if (move_hero(mlx).hero.wall == 0)
		{
			mlx.hero.pos_x -= mlx.hero.pdx;
			mlx.hero.pos_y -= mlx.hero.pdy;
		}
	}
	else if (key == 0 || key == 2)
		hero_new_pos_second(key, &mlx);
	mlx = move_hero(mlx);
	return (mlx);
}

t_mlx	hero_turn(int key, t_mlx mlx)
{
	clear_hero(mlx);
	if (key == 124)
	{
		mlx.hero.pos_a -= 0.0174533;
		if (mlx.hero.pos_a < 0)
			mlx.hero.pos_a += 2 * PI;
		mlx.hero.pdx = cos(mlx.hero.pos_a) * 5;
		mlx.hero.pdy = sin(mlx.hero.pos_a) * 5;
	}
	else if (key == 123)
	{
		mlx.hero.pos_a += 0.0174533;
		if (mlx.hero.pos_a > 2 * PI)
			mlx.hero.pos_a -= 2 * PI;
		mlx.hero.pdx = cos(mlx.hero.pos_a) * 5;
		mlx.hero.pdy = sin(mlx.hero.pos_a) * 5;
	}
	mlx = move_hero(mlx);
	return (mlx);
}
