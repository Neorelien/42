/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:05:10 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 20:34:49 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_column(t_mlx *mlx)
{
	int	j;
	int	i;

	j = -1;
	mlx->ray.draw_end = mlx->win_height - mlx->ray.draw_start;
	i = mlx->ray.draw_end;
	while (++j < mlx->ray.draw_start)
		mlx->game.data[j * mlx->game.size_l / 4 + mlx->ray.x] = mlx->color_c;
	if (j <= mlx->ray.draw_end)
		ft_draw_texture(mlx, mlx->ray.x, j);
	j = i;
	while (++j < mlx->win_height)
		mlx->game.data[j * mlx->game.size_l / 4 + mlx->ray.x] = mlx->color_f;
}

void	ft_draw_texture(t_mlx *mlx, int x, int y)
{
	y = mlx->ray.draw_start - 1;
	ft_init_texture(mlx);
	mlx->tex_pos.step = 1.0 * mlx->texture.height / mlx->ray.line_h;
	mlx->tex_pos.txx = (int)(mlx->wall_x * (double)mlx->texture.width);
	if (mlx->ray.side == 0 && mlx->ray.raydir_x > 0)
		mlx->tex_pos.txx = mlx->texture.width - mlx->tex_pos.txx - 1;
	if (mlx->ray.side == 1 && mlx->ray.raydir_y < 0)
		mlx->tex_pos.txx = mlx->texture.width - mlx->tex_pos.txx - 1;
	mlx->tex_pos.pos = (mlx->ray.draw_start - mlx->win_height / 2 +
		mlx->ray.line_h / 2) * mlx->tex_pos.step;
	while (++y <= mlx->ray.draw_end)
	{
		mlx->tex_pos.txy = (int)mlx->tex_pos.pos &
			(mlx->texture.height - 1);
		mlx->tex_pos.pos += mlx->tex_pos.step;
		if (y < mlx->win_height && x < mlx->win_width)
			mlx->game.data[y * mlx->game.size_l / 4 + x] = mlx->texture.data
				[mlx->tex_pos.txy * mlx->texture.size_l / 4 + mlx->tex_pos.txx];
	}
}
