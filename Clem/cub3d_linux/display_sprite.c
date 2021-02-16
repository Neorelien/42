/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:17:28 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:13:16 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		ft_count_sprite(t_mlx mlx)
{
	int		nb;
	t_ray	ray;

	nb = 0;
	ray.ligne = 0;
	ray.pos_x = mlx.hero.pos_x;
	ray.pos_y = mlx.hero.pos_y;
	mlx.map.x = ray.pos_y - 5;
	mlx.map.y = ray.pos_x - 4;
	while (ft_iswall(mlx))
	{
		if (!ft_issprite(mlx))
			nb++;
		ray.dist[ray.ligne]++;
		ray.pos_x -= mlx.hero.pdx / 5;
		ray.pos_y -= mlx.hero.pdy / 5;
		mlx.map.x = ray.pos_y - 5;
		mlx.map.y = ray.pos_x - 4;
	}
	return (nb);
}

int		ft_sprite_textures_x(t_mlx mlx)
{
	int		x;
	int		i;

	i = 0;
	while (i < mlx.nb_sprite - 1)
	{
		if (mlx.sprite[i].count_w * 64 <= mlx.map.x
			&& (mlx.sprite[i].count_w + 1) * 64 > mlx.map.x)
			if (mlx.sprite[i].count_h * 64 <= mlx.map.y
				&& (mlx.sprite[i].count_h + 1) * 64 > mlx.map.y)
				break ;
		i++;
	}
	x = sqrt(pow(mlx.map.x - mlx.sprite[i].coord_x, 2)
		+ pow(mlx.map.y - mlx.sprite[i].coord_y, 2));
	return (x);
}
