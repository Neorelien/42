/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:15:22 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 19:57:00 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_forward_back(t_mlx *mlx)
{
	if (mlx->hero.forward == 1)
	{
		if (mlx->card[(int)mlx->ray.pos_y][(int)(mlx->ray.pos_x
			+ (mlx->ray.dir_x * mlx->ray.move_speed * 2))] == '0')
			mlx->ray.pos_x += mlx->ray.dir_x * mlx->ray.move_speed;
		if (mlx->card[(int)(mlx->ray.pos_y + (mlx->ray.dir_y
			* mlx->ray.move_speed * 2))][(int)(mlx->ray.pos_x)] == '0')
			mlx->ray.pos_y += mlx->ray.dir_y * mlx->ray.move_speed;
	}
	if (mlx->hero.back == 1)
	{
		if (mlx->card[(int)(mlx->ray.pos_y)][(int)(mlx->ray.pos_x
			- (mlx->ray.dir_x * mlx->ray.move_speed * 2))] == '0')
			mlx->ray.pos_x -= mlx->ray.dir_x * mlx->ray.move_speed;
		if (mlx->card[(int)(mlx->ray.pos_y - (mlx->ray.dir_y
			* mlx->ray.move_speed * 2))][(int)(mlx->ray.pos_x)] == '0')
			mlx->ray.pos_y -= mlx->ray.dir_y * mlx->ray.move_speed;
	}
}

void	ft_left_right(t_mlx *mlx)
{
	if (mlx->hero.right == 1)
	{
		if (mlx->card[(int)mlx->ray.pos_y][(int)(mlx->ray.pos_x + mlx->ray.dir_y
			* (mlx->ray.move_speed * 2))] == '0')
			mlx->ray.pos_x += mlx->ray.dir_y * mlx->ray.move_speed;
		if (mlx->card[(int)(mlx->ray.pos_y - mlx->ray.dir_x
			* (mlx->ray.move_speed * 2))][(int)mlx->ray.pos_x] == '0')
			mlx->ray.pos_y -= mlx->ray.dir_x * mlx->ray.move_speed;
	}
	if (mlx->hero.left == 1)
	{
		if (mlx->card[(int)mlx->ray.pos_y][(int)(mlx->ray.pos_x - mlx->ray.dir_y
			* (mlx->ray.move_speed * 2))] == '0')
			mlx->ray.pos_x -= mlx->ray.dir_y * mlx->ray.move_speed;
		if (mlx->card[(int)(mlx->ray.pos_y + mlx->ray.dir_x
			* (mlx->ray.move_speed * 2))][(int)mlx->ray.pos_x] == '0')
			mlx->ray.pos_y += mlx->ray.dir_x * mlx->ray.move_speed;
	}
}

void	ft_rotate_right_left(t_mlx *mlx)
{
	double	plan_x_prec;
	double	dir_x_prec;

	plan_x_prec = mlx->ray.plan_x;
	dir_x_prec = mlx->ray.dir_x;
	if (mlx->hero.r_right == 1)
	{
		mlx->ray.dir_x = mlx->ray.dir_x * cos(-mlx->ray.rot_speed / 2) -
			mlx->ray.dir_y * sin(-mlx->ray.rot_speed / 2);
		mlx->ray.dir_y = dir_x_prec * sin(-mlx->ray.rot_speed / 2) +
			mlx->ray.dir_y * cos(-mlx->ray.rot_speed / 2);
		mlx->ray.plan_x = mlx->ray.plan_x * cos(-mlx->ray.rot_speed / 2)
			- mlx->ray.plan_y * sin(-mlx->ray.rot_speed / 2);
		mlx->ray.plan_y = plan_x_prec * sin(-mlx->ray.rot_speed / 2) +
			mlx->ray.plan_y * cos(-mlx->ray.rot_speed / 2);
	}
	ft_rotate_left(mlx, dir_x_prec);
}

void	ft_rotate_left(t_mlx *mlx, double dir_x_prec)
{
	double	oldplanex;

	if (mlx->hero.r_left == 1)
	{
		dir_x_prec = mlx->ray.dir_x;
		oldplanex = mlx->ray.plan_x;
		mlx->ray.dir_x = mlx->ray.dir_x * cos(mlx->ray.rot_speed / 2) -
			mlx->ray.dir_y * sin(mlx->ray.rot_speed / 2);
		mlx->ray.dir_y = dir_x_prec * sin(mlx->ray.rot_speed / 2) + mlx->
			ray.dir_y * cos(mlx->ray.rot_speed / 2);
		mlx->ray.plan_x = mlx->ray.plan_x * cos(mlx->ray.rot_speed / 2) -
			mlx->ray.plan_y * sin(mlx->ray.rot_speed / 2);
		mlx->ray.plan_y = oldplanex * sin(mlx->ray.rot_speed / 2) +
			mlx->ray.plan_y * cos(mlx->ray.rot_speed / 2);
	}
}
