/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 05:47:20 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 20:42:42 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dist_order2(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < mlx->nb_sprite)
	{
		mlx->sprite.order[i] = i;
		mlx->sprite.dist[i] = ((mlx->ray.pos_x - mlx->spr[i].x) *
				(mlx->ray.pos_x - mlx->spr[i].x) + (mlx->ray.pos_y -
					mlx->spr[i].y) * (mlx->ray.pos_y - mlx->spr[i].y));
	}
}

void	ft_dist_order(t_mlx *mlx)
{
	int		i;
	int		j;
	double	tmp;

	ft_dist_order2(mlx);
	i = -1;
	while (++i < mlx->nb_sprite)
	{
		j = -1;
		while (++j < mlx->nb_sprite - 1)
		{
			if (mlx->sprite.dist[j] < mlx->sprite.dist[j + 1])
			{
				tmp = mlx->sprite.dist[j];
				mlx->sprite.dist[j] = mlx->sprite.dist[j + 1];
				mlx->sprite.dist[j + 1] = tmp;
				tmp = mlx->sprite.order[j];
				mlx->sprite.order[j] = mlx->sprite.order[j + 1];
				mlx->sprite.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	ft_calculs_second(t_mlx *mlx)
{
	if (mlx->sprite.drawstartx < 0)
		mlx->sprite.drawstartx = 0;
	mlx->sprite.drawendx = mlx->sprite.sprite_w / 2 + mlx->sprite.spritescreenx;
	if (mlx->sprite.drawendx >= mlx->win_width)
		mlx->sprite.drawendx = mlx->win_width;
}

void	ft_calculs(t_mlx *mlx, int i)
{
	mlx->sprite.spritex = mlx->spr[mlx->sprite.order[i]].x - mlx->ray.pos_x;
	mlx->sprite.spritey = mlx->spr[mlx->sprite.order[i]].y - mlx->ray.pos_y;
	mlx->sprite.invdet = 1.0 / (mlx->ray.plan_x * mlx->ray.dir_y -
		mlx->ray.dir_x * mlx->ray.plan_y);
	mlx->sprite.transformx = mlx->sprite.invdet * (mlx->ray.dir_y *
		mlx->sprite.spritex - mlx->ray.dir_x * mlx->sprite.spritey);
	mlx->sprite.transformy = mlx->sprite.invdet * (-mlx->ray.plan_y *
		mlx->sprite.spritex + mlx->ray.plan_x * mlx->sprite.spritey);
	mlx->sprite.spritescreenx = (int)((mlx->win_width / 2) * (1
		+ mlx->sprite.transformx / mlx->sprite.transformy));
	mlx->sprite.sprite_h = abs((int)(mlx->win_height
	/ (mlx->sprite.transformy)));
	mlx->sprite.drawstarty = -mlx->sprite.sprite_h / 2 + mlx->win_height / 2;
	if (mlx->sprite.drawstarty < 0)
		mlx->sprite.drawstarty = 0;
	mlx->sprite.drawendy = mlx->sprite.sprite_h / 2 + mlx->win_height / 2;
	if (mlx->sprite.drawendy >= mlx->win_height)
		mlx->sprite.drawendy = mlx->win_height;
	mlx->sprite.sprite_w = abs((int)(mlx->win_height
		/ (mlx->sprite.transformy)));
	mlx->sprite.drawstartx = -mlx->sprite.sprite_w
		/ 2 + mlx->sprite.spritescreenx;
	ft_calculs_second(mlx);
}

void	ft_draw_spr(t_mlx *mlx, int y, int txx, int s)
{
	int		d;
	int		txy;

	while (y < mlx->sprite.drawendy)
	{
		d = (y) * 256 - (mlx->win_height - 1) * 128
			+ mlx->sprite.sprite_h * 128;
		txy = ((d * mlx->tex_sprite.height) / mlx->sprite.sprite_h) / 256;
		if (mlx->tex_sprite.data[txy * mlx->tex_sprite.size_l / 4 +
				txx] != 0)
		{
			mlx->game.data[y * mlx->win_width + s] =
				mlx->tex_sprite.data[txy * mlx->tex_sprite.size_l / 4 + txx];
		}
		y++;
	}
}
