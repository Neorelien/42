/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:13:47 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/17 16:26:44 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	ft_double_pointer_free(char **tab, int size, int all)
{
	while (size >= 0)
		free(tab[size--]);
	if (all == 1)
		free(tab);
}

void	ft_free_all(t_mlx *mlx)
{
	if (mlx->tex_n.malloc != -1)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_n.img);
	if (mlx->tex_s.malloc != -1)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_s.img);
	if (mlx->tex_e.malloc != -1)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_e.img);
	if (mlx->tex_w.malloc != -1)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_w.img);
	if (mlx->tex_sprite.malloc != -1)
		mlx_destroy_image(mlx->mlx_ptr, mlx->tex_sprite.img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->game.img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
}

void	ft_free_textures(t_mlx *mlx)
{
	if (mlx->tex_n.malloc == 1)
		free(mlx->tex_n.path);
	if (mlx->tex_s.malloc == 1)
		free(mlx->tex_s.path);
	if (mlx->tex_e.malloc == 1)
		free(mlx->tex_e.path);
	if (mlx->tex_w.malloc == 1)
		free(mlx->tex_w.path);
	if (mlx->tex_sprite.malloc == 1)
		free(mlx->tex_sprite.path);
}
