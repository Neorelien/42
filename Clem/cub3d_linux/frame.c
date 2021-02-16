/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:15:26 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:13:40 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		frame_third(t_mlx *mlx, t_ray *ray, int i)
{
	ray->pos_x = mlx->hero.pos_x;
	ray->pos_y = mlx->hero.pos_y;
	mlx->map.x = ray->pos_y - 5;
	mlx->map.y = ray->pos_x - 4;
	while (ft_iswall(*mlx))
	{
		if (!ft_issprite(*mlx))
		{
			mlx->sprite_here[i].dist = ray->dist[ray->ligne];
			mlx->sprite_here[i].y = mlx->map.y;
			mlx->sprite_here[i].x = mlx->map.x;
			i++;
		}
		ray->dist[ray->ligne]++;
		ray->pos_x -= mlx->hero.pdx / 5;
		ray->pos_y -= mlx->hero.pdy / 5;
		mlx->map.x = ray->pos_y - 5;
		mlx->map.y = ray->pos_x - 4;
	}
	return (i);
}

int		frame_second(t_mlx *mlx, t_ray *ray, int i)
{
	i = 0;
	mlx->nb_disprite = ft_count_sprite(*mlx);
	if (mlx->nb_disprite)
		if (!(mlx->sprite_here = (t_disprite*)malloc(sizeof(t_disprite)
			* mlx->nb_disprite)))
			return (-10);
	i = frame_third(mlx, ray, i);
	*mlx = angle(*mlx, *ray);
	if (ray->ligne > 0)
	{
		ray->angle = ft_isangle(*mlx, *ray);
		range_ray(*ray, *mlx);
		i = mlx->nb_disprite;
		while (--i >= 0)
		{
			ray->dist[ray->ligne] = mlx->sprite_here[i].dist;
			mlx->map.y = mlx->sprite_here[i].y;
			mlx->map.x = mlx->sprite_here[i].x;
			range_ray(*ray, *mlx);
		}
	}
	ray->dist[++ray->ligne] = 0;
	if (mlx->nb_disprite)
		free(mlx->sprite_here);
	return (i);
}

void	frame(t_mlx mlx)
{
	t_ray	ray;
	int		i;

	ray.nb_line = 600;
	ray.ligne = 0;
	mlx.hero.ray_a = mlx.hero.pos_a;
	init_color_fc(mlx);
	while (ray.ligne < ray.nb_line + 1)
		if ((i = frame_second(&mlx, &ray, i)) == -10)
		{
			mlx.error = MALLOC_ERROR;
			ft_error(&mlx);
		}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.game_win, mlx.game.img_ptr, 0, 0);
}
