/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:11:48 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:15:31 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	ft_textures_angle_s(t_mlx mlx, t_ray ray, t_angle angle)
{
	angle.y = mlx.map.y - (mlx.hero.pos_x - 4);
	angle.y = ft_abs(angle.y);
	angle.x = (mlx.map.x - 1) - (mlx.hero.pos_y - 5);
	angle.x = ft_abs(angle.x);
	angle.first = (angle.x * angle.x) + (angle.y * angle.y);
	angle.y = (mlx.map.y - 1) - (mlx.hero.pos_x - 4);
	angle.y = ft_abs(angle.y);
	angle.x = mlx.map.x - (mlx.hero.pos_y - 5);
	angle.x = ft_abs(angle.x);
	angle.second = (angle.x * angle.x) + (angle.y * angle.y);
	angle.min = ft_min(angle.first, angle.second);
	if (angle.min == angle.first)
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_n.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
	else
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_w.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
}

void	ft_textures_angle_w(t_mlx mlx, t_ray ray, t_angle angle)
{
	angle.y = mlx.map.y - (mlx.hero.pos_x - 4);
	angle.y = ft_abs(angle.y);
	angle.x = (mlx.map.x - 1) - (mlx.hero.pos_y - 5);
	angle.x = ft_abs(angle.x);
	angle.first = (angle.x * angle.x) + (angle.y * angle.y);
	angle.y = (mlx.map.y + 1) - (mlx.hero.pos_x - 4);
	angle.y = ft_abs(angle.y);
	angle.x = mlx.map.x - (mlx.hero.pos_y - 5);
	angle.x = ft_abs(angle.x);
	angle.second = (angle.x * angle.x) + (angle.y * angle.y);
	angle.min = ft_min(angle.first, angle.second);
	if (angle.min == angle.first)
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_s.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
	else
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_w.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
}

void	ft_textures_angle_q(t_mlx mlx, t_ray ray, t_angle angle)
{
	angle.y = mlx.map.y - (mlx.hero.pos_x - 4);
	angle.y = ft_abs(angle.y);
	angle.x = (mlx.map.x + 1) - (mlx.hero.pos_y - 5);
	angle.x = ft_abs(angle.x);
	angle.first = (angle.x * angle.x) + (angle.y * angle.y);
	angle.y = (mlx.map.y + 1) - (mlx.hero.pos_x - 4);
	angle.y = ft_abs(angle.y);
	angle.x = mlx.map.x - (mlx.hero.pos_y - 5);
	angle.x = ft_abs(angle.x);
	angle.second = (angle.x * angle.x) + (angle.y * angle.y);
	angle.min = ft_min(angle.first, angle.second);
	if (angle.min == angle.first)
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_s.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
	else
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_e.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
}

void	ft_textures_angle_a(t_mlx mlx, t_ray ray, t_angle angle)
{
	angle.y = mlx.map.y - (mlx.hero.pos_x - 4);
	angle.y = ft_abs(angle.y);
	angle.x = (mlx.map.x + 1) - (mlx.hero.pos_y - 5);
	angle.x = ft_abs(angle.x);
	angle.first = (angle.x * angle.x) + (angle.y * angle.y);
	angle.y = (mlx.map.y - 1) - (mlx.hero.pos_x - 4);
	angle.y = ft_abs(angle.y);
	angle.x = mlx.map.x - (mlx.hero.pos_y - 5);
	angle.x = ft_abs(angle.x);
	angle.second = (angle.x * angle.x) + (angle.y * angle.y);
	angle.min = ft_min(angle.first, angle.second);
	if (angle.min == angle.first)
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_n.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
	else
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_e.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
}

void	ft_textures_angle(t_mlx mlx, t_ray ray)
{
	t_angle	angle;

	angle.y = 0;
	if (ray.angle == 's')
		ft_textures_angle_s(mlx, ray, angle);
	else if (ray.angle == 'w')
		ft_textures_angle_w(mlx, ray, angle);
	else if (ray.angle == 'q')
		ft_textures_angle_q(mlx, ray, angle);
	else if (ray.angle == 'a')
		ft_textures_angle_a(mlx, ray, angle);
}
