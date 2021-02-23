/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 02:04:30 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 19:11:21 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_mlx_part(t_mlx *mlx)
{
	free(mlx->sprite.zbuffer);
	if (mlx->game.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->game.img_ptr);
	if (mlx->tex_n.img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_n.img);
	if (mlx->tex_s.img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_s.img);
	if (mlx->tex_e.img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_e.img);
	if (mlx->tex_w.img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_w.img);
	if (mlx->tex_sprite.img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_sprite.img);
	if (mlx->game_win != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->game_win);
}

void	ft_free_second_part(t_mlx *mlx)
{
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

void	ft_free_first_part(t_mlx *mlx)
{
	if (mlx->tex_n.path != NULL)
		free(mlx->tex_n.path);
	if (mlx->tex_s.path != NULL)
		free(mlx->tex_s.path);
	if (mlx->tex_e.path != NULL)
		free(mlx->tex_e.path);
	if (mlx->tex_w.path != NULL)
		free(mlx->tex_w.path);
	if (mlx->tex_sprite.path != NULL)
		free(mlx->tex_sprite.path);
	if (mlx->card != NULL)
	{
		while (--mlx->count >= 0)
			free(mlx->card[mlx->count]);
		free(mlx->card);
	}
	if (mlx->spr != NULL)
		free(mlx->spr);
	if (mlx->sprite.order != NULL)
		free(mlx->sprite.order);
	if (mlx->sprite.dist != NULL)
		free(mlx->sprite.dist);
	if (mlx->init[1] == 1)
		ft_free_mlx_part(mlx);
	ft_free_second_part(mlx);
}

int		ft_exit(t_mlx *mlx)
{
	ft_free_first_part(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
