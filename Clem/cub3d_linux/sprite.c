/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:16:08 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/23 00:16:26 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_sprite2(t_mlx *mlx, int i, int j, int k)
{
	j -= 1;
	while (++j < mlx->nblines)
	{
		i = -1;
		while (++i < mlx->sizeline)
		{
			if (mlx->card[j][i] == '2')
			{
				mlx->spr[k].x = (double)i + 0.5;
				mlx->spr[k].y = (double)j + 0.5;
				k++;
			}
		}
	}
}

void	ft_init_sprite(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	mlx->nb_sprite = 0;
	*mlx = check_map(mlx->card, *mlx);
	if (mlx->start == 0)
		ft_error(mlx, "You can't play without hero");
	while (++i < mlx->nblines)
	{
		j = -1;
		while (++j < mlx->sizeline)
		{
			if (mlx->card[i][j] == '2')
				mlx->nb_sprite += 1;
		}
	}
	if (!(mlx->spr = (t_disprite *)malloc(sizeof(t_disprite) * mlx->nb_sprite)))
		ft_error(mlx, "Malloc spr");
	if (!(mlx->sprite.order = (int *)malloc(sizeof(int) * mlx->nb_sprite)))
		ft_error(mlx, "Malloc sprite order*");
	if (!(mlx->sprite.dist = (double *)malloc(sizeof(double) * mlx->nb_sprite)))
		ft_error(mlx, "Malloc sprite dist");
	ft_init_sprite2(mlx, 0, 0, 0);
	ft_mlx(mlx);
}

void	ft_sprite(t_mlx *mlx)
{
	int	i;
	int	y;
	int	s;
	int	txx;

	i = -1;
	ft_dist_order(mlx);
	while (++i < mlx->nb_sprite)
	{
		ft_calculs(mlx, i);
		s = mlx->sprite.drawstartx;
		while (s < mlx->sprite.drawendx)
		{
			txx = (int)(256 * (s - (-mlx->sprite.sprite_w / 2 +
							mlx->sprite.spritescreenx)) * mlx->tex_sprite.width
					/ mlx->sprite.sprite_w) / 256;
			if (mlx->sprite.transformy > 0 && s >= 0 && s < mlx->win_width
					&& mlx->sprite.transformy < mlx->sprite.zbuffer[s])
			{
				y = mlx->sprite.drawstarty;
				ft_draw_spr(mlx, y, txx, s);
			}
			s++;
		}
	}
}
