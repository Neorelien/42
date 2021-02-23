/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:03:20 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 20:05:00 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ray_part(t_mlx *mlx)
{
	mlx->init[2] = 1;
	mlx->ray.hit = 0;
	mlx->ray.dist = 0;
	mlx->ray.camerax = 2 * mlx->ray.x / (double)mlx->win_width - 1;
	mlx->ray.raydir_x = mlx->ray.dir_x + mlx->ray.plan_x * mlx->ray.camerax;
	mlx->ray.raydir_y = mlx->ray.dir_y + mlx->ray.plan_y * mlx->ray.camerax;
	mlx->ray.map_x = (int)mlx->ray.pos_x;
	mlx->ray.map_y = (int)mlx->ray.pos_y;
	mlx->ray.move_speed = 0.1;
	mlx->ray.rot_speed = 0.033 * 1.8;
	if (mlx->ray.raydir_y == 0)
		mlx->ray.deltadist_x = 0;
	else if (mlx->ray.raydir_x == 0)
		mlx->ray.deltadist_x = 1;
	else
		mlx->ray.deltadist_x = sqrt(1 + (mlx->ray.raydir_y * mlx->ray.raydir_y)
			/ (mlx->ray.raydir_x * mlx->ray.raydir_x));
	if (mlx->ray.raydir_x == 0)
		mlx->ray.deltadist_y = 0;
	else if (mlx->ray.raydir_y == 0)
		mlx->ray.deltadist_y = 1;
	else
		mlx->ray.deltadist_y = sqrt(1 + (mlx->ray.raydir_x * mlx->ray.raydir_x)
			/ (mlx->ray.raydir_y * mlx->ray.raydir_y));
}

void	ft_drawstartend(t_mlx *mlx)
{
	if (mlx->ray.side == 0)
		mlx->ray.dist = ((double)mlx->ray.map_x - mlx->ray.pos_x
			+ (1 - (double)mlx->ray.step_x) / 2) / mlx->ray.raydir_x;
	else
		mlx->ray.dist = ((double)mlx->ray.map_y - mlx->ray.pos_y
			+ (1 - (double)mlx->ray.step_y) / 2) / mlx->ray.raydir_y;
	mlx->ray.line_h = (int)(mlx->win_height / mlx->ray.dist);
	mlx->ray.draw_start = -mlx->ray.line_h / 2 + mlx->win_height / 2;
	if (mlx->ray.draw_start < 0)
		mlx->ray.draw_start = 0;
	mlx->ray.draw_end = mlx->ray.line_h / 2 + mlx->win_height / 2;
	if (mlx->ray.draw_end >= mlx->win_height || mlx->ray.draw_end < 0)
		mlx->ray.draw_end = mlx->win_height - 1;
}

void	ft_do_dist(t_mlx *mlx)
{
	while (mlx->ray.hit == 0)
	{
		if (mlx->ray.sidedist_x < mlx->ray.sidedist_y)
		{
			mlx->ray.sidedist_x += mlx->ray.deltadist_x;
			mlx->ray.map_x += mlx->ray.step_x;
			mlx->ray.side = 0;
		}
		else
		{
			mlx->ray.sidedist_y += mlx->ray.deltadist_y;
			mlx->ray.map_y += mlx->ray.step_y;
			mlx->ray.side = 1;
		}
		if (mlx->card[mlx->ray.map_y][mlx->ray.map_x] == '1')
			mlx->ray.hit = 1;
	}
	ft_drawstartend(mlx);
}

void	ft_stepdist(t_mlx *mlx)
{
	if (mlx->ray.raydir_x < 0)
	{
		mlx->ray.step_x = -1;
		mlx->ray.sidedist_x = (mlx->ray.pos_x - mlx->ray.map_x)
			* mlx->ray.deltadist_x;
	}
	else
	{
		mlx->ray.step_x = 1;
		mlx->ray.sidedist_x = (mlx->ray.map_x + 1.0 - mlx->ray.pos_x)
			* mlx->ray.deltadist_x;
	}
	if (mlx->ray.raydir_y < 0)
	{
		mlx->ray.step_y = -1;
		mlx->ray.sidedist_y = (mlx->ray.pos_y - mlx->ray.map_y)
			* mlx->ray.deltadist_y;
	}
	else
	{
		mlx->ray.step_y = 1;
		mlx->ray.sidedist_y = (mlx->ray.map_y + 1.0 - mlx->ray.pos_y)
			* mlx->ray.deltadist_y;
	}
	ft_do_dist(mlx);
}

int		ft_raycasting(t_mlx *mlx)
{
	mlx->ray.x = 0;
	while (mlx->ray.x < mlx->win_width)
	{
		ft_init_ray_part(mlx);
		ft_stepdist(mlx);
		ft_color_column(mlx);
		mlx->sprite.zbuffer[mlx->ray.x] = mlx->ray.dist;
		mlx->ray.x++;
	}
	ft_sprite(mlx);
	if (mlx->save == 1)
		ft_save(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->game_win, mlx->game.img_ptr
		, 0, 0);
	ft_forward_back(mlx);
	ft_left_right(mlx);
	ft_rotate_right_left(mlx);
	return (0);
}
