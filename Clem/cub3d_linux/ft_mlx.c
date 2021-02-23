/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:44:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/23 00:03:18 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx_part(t_mlx *mlx)
{
	if (!(mlx->sprite.zbuffer = (double *)malloc(sizeof(double)
		* mlx->win_width)))
		ft_error(mlx, "Malloc zbuffer");
	mlx->init[1] = 1;
	mlx->hero.forward = 0;
	mlx->hero.back = 0;
	mlx->hero.right = 0;
	mlx->hero.left = 0;
	mlx->hero.r_right = 0;
	mlx->hero.r_left = 0;
	mlx->ray.pos_x = (double)mlx->hero.pos_x + 0.5;
	mlx->ray.pos_y = (double)mlx->hero.pos_y + 0.5;
	mlx->game.img_ptr = NULL;
	mlx->tex_n.img = NULL;
	mlx->tex_s.img = NULL;
	mlx->tex_e.img = NULL;
	mlx->tex_w.img = NULL;
	mlx->tex_sprite.img = NULL;
	mlx->game_win = NULL;
	mlx->game.img_ptr = NULL;
}

int		ft_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		ft_error(mlx, "Mlx init impossible\n");
	window_second(mlx);
	ft_init_mlx_part(mlx);
	get_textures_data(mlx);
	mlx->game.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width
		, mlx->win_height);
	mlx->game.data = (int *)mlx_get_data_addr(mlx->game.img_ptr, &mlx->game.bpp
		, &mlx->game.size_l, &mlx->game.endian);
	if (mlx->save == 1)
		ft_raycasting(mlx);
	mlx->game_win = mlx_new_window(mlx->mlx_ptr, mlx->win_width,
		mlx->win_height, "INFINITY GAME");
	mlx_hook(mlx->game_win, 2, 1L << 0, ft_press_key, mlx);
	mlx_hook(mlx->game_win, 33, 1L << 17, ft_exit, mlx);
	mlx_loop_hook(mlx->mlx_ptr, ft_raycasting, mlx);
	mlx_hook(mlx->game_win, 3, 1L << 1, ft_release_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
