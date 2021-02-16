/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:38:15 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:15:08 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

t_mlx	angle(t_mlx mlx, t_ray ray)
{
	mlx.hero.cos_a = mlx.hero.pos_a - mlx.hero.ray_a;
	if (ray.ligne)
	{
		mlx.hero.ray_a -= 1.047198 / ray.nb_line;
		if (mlx.hero.ray_a < 0)
			mlx.hero.ray_a += 2 * PI;
		if (mlx.hero.ray_a > 2 * PI)
			mlx.hero.ray_a -= 2 * PI;
		mlx.hero.pdx = cos(mlx.hero.ray_a) * 5;
		mlx.hero.pdy = sin(mlx.hero.ray_a) * 5;
	}
	else
	{
		mlx.hero.ray_a += (0.0174533 * 30);
		if (mlx.hero.ray_a > 2 * PI)
			mlx.hero.ray_a -= 2 * PI;
		mlx.hero.pdx = cos(mlx.hero.ray_a) * 5;
		mlx.hero.pdy = sin(mlx.hero.ray_a) * 5;
	}
	if (mlx.hero.cos_a < 0)
		mlx.hero.cos_a += 2 * PI;
	if (mlx.hero.cos_a > 2 * PI)
		mlx.hero.cos_a -= 2 * PI;
	return (mlx);
}

void	range_ray_second(t_ray ray, t_mlx mlx)
{
	while (ray.i < ray.ligne * mlx.win_width / ray.nb_line)
	{
		mlx.tex_pos.y = 0;
		mlx.tex_pos.ty = mlx.tex_pos.ty_off * mlx.tex_pos.ty_step;
		mlx.tex_pos.tx = ((int)mlx.map.y / 2) % 32;
		mlx.tex_pos.txy = ((int)mlx.map.x / 2) % 32;
		ray.height = -1;
		while (++ray.height <= mlx.win_height)
		{
			if (ray.height < ray.line_h)
				make_textures(mlx, ray);
			mlx.tex_pos.ty += mlx.tex_pos.ty_step;
		}
		ray.i++;
	}
}

void	range_ray(t_ray ray, t_mlx mlx)
{
	if (mlx.nb_disprite > 0)
		mlx.tex_pos.ta = (ft_sprite_textures_x(mlx) / 2) % 32;
	ray.dist[ray.ligne] = ray.dist[ray.ligne] * cos(mlx.hero.cos_a);
	ray.i = (ray.ligne - 1) * mlx.win_width / ray.nb_line;
	ray.line_h = (64 * mlx.win_height / ray.dist[ray.ligne]);
	mlx.tex_pos.ty_step = 32.0 / ray.line_h;
	mlx.tex_pos.ty_off = 0;
	if (ray.line_h > mlx.win_height)
	{
		mlx.tex_pos.ty_off = (ray.line_h - mlx.win_height) / 2.0;
		ray.line_h = mlx.win_height;
	}
	ray.line_o = mlx.win_height / 2 - ray.line_h / 2;
	range_ray_second(ray, mlx);
}
