/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:36:07 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 20:36:38 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures_data_second(t_mlx *mlx)
{
	if (!(mlx->tex_e.img = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->tex_e.path,
		&mlx->tex_e.width, &mlx->tex_e.height)))
		ft_error(mlx, "In East texture");
	mlx->tex_e.data = (int *)mlx_get_data_addr(mlx->tex_e.img, &mlx->tex_e.bpp,
		&mlx->tex_e.size_l, &mlx->tex_e.endian);
	if (!(mlx->tex_w.img = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->tex_w.path,
		&mlx->tex_w.width, &mlx->tex_w.height)))
		ft_error(mlx, "In West texture");
	mlx->tex_w.data = (int *)mlx_get_data_addr(mlx->tex_w.img, &mlx->tex_w.bpp,
		&mlx->tex_w.size_l, &mlx->tex_w.endian);
	if (!(mlx->tex_sprite.img = mlx_xpm_file_to_image(mlx->mlx_ptr,
		mlx->tex_sprite.path, &mlx->tex_sprite.width, &mlx->tex_sprite.height)))
		ft_error(mlx, "In Sprite texture");
	mlx->tex_sprite.data = (int *)mlx_get_data_addr(mlx->tex_sprite.img,
		&mlx->tex_sprite.bpp, &mlx->tex_sprite.size_l, &mlx->tex_sprite.endian);
}

void	get_textures_data(t_mlx *mlx)
{
	if (!(mlx->tex_n.img = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->tex_n.path,
		&mlx->tex_n.width, &mlx->tex_n.height)))
		ft_error(mlx, "In North texture");
	mlx->tex_n.data = (int *)mlx_get_data_addr(mlx->tex_n.img, &mlx->tex_n.bpp,
		&mlx->tex_n.size_l, &mlx->tex_n.endian);
	if (!(mlx->tex_s.img = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->tex_s.path,
		&mlx->tex_s.width, &mlx->tex_s.height)))
		ft_error(mlx, "In South texture");
	mlx->tex_s.data = (int *)mlx_get_data_addr(mlx->tex_s.img, &mlx->tex_s.bpp,
		&mlx->tex_s.size_l, &mlx->tex_s.endian);
	get_textures_data_second(mlx);
}
