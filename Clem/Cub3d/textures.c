/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 03:04:11 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/17 03:12:12 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

t_mlx	get_textures_data_second(t_mlx mlx)
{
	if (!(mlx.tex_e.img = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.tex_e.path,
	&mlx.tex_e.width, &mlx.tex_e.height)))
	{
		mlx.error = ERROR_TEX_E;
		ft_error_textures(&mlx);
	}
	mlx.tex_e.data = (int *)mlx_get_data_addr(mlx.tex_e.img, &mlx.tex_e.bpp,
	&mlx.tex_e.size_l, &mlx.tex_e.endian);
	if (!(mlx.tex_w.img = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.tex_w.path,
	&mlx.tex_w.width, &mlx.tex_w.height)))
	{
		mlx.error = ERROR_TEX_W;
		ft_error_textures(&mlx);
	}
	mlx.tex_w.data = (int *)mlx_get_data_addr(mlx.tex_w.img, &mlx.tex_w.bpp,
	&mlx.tex_w.size_l, &mlx.tex_w.endian);
	if (!(mlx.tex_sprite.img = mlx_xpm_file_to_image(mlx.mlx_ptr,
	mlx.tex_sprite.path, &mlx.tex_sprite.width, &mlx.tex_sprite.height)))
	{
		mlx.error = ERROR_TEX_SPRITE;
		ft_error_textures(&mlx);
	}
	mlx.tex_sprite.data = (int *)mlx_get_data_addr(mlx.tex_sprite.img,
	&mlx.tex_sprite.bpp, &mlx.tex_sprite.size_l, &mlx.tex_sprite.endian);
	return (mlx);
}

t_mlx	get_textures_data(t_mlx mlx)
{
	if (!(mlx.tex_n.img = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.tex_n.path,
	&mlx.tex_n.width, &mlx.tex_n.height)))
	{
		mlx.error = ERROR_TEX_N;
		ft_error_textures(&mlx);
	}
	mlx.tex_n.data = (int *)mlx_get_data_addr(mlx.tex_n.img, &mlx.tex_n.bpp,
	&mlx.tex_n.size_l, &mlx.tex_n.endian);
	if (!(mlx.tex_s.img = mlx_xpm_file_to_image(mlx.mlx_ptr, mlx.tex_s.path,
	&mlx.tex_s.width, &mlx.tex_s.height)))
	{
		mlx.error = ERROR_TEX_S;
		ft_error_textures(&mlx);
	}
	mlx.tex_s.data = (int *)mlx_get_data_addr(mlx.tex_s.img, &mlx.tex_s.bpp,
	&mlx.tex_s.size_l, &mlx.tex_s.endian);
	mlx = get_textures_data_second(mlx);
	textures_check(&mlx);
	return (mlx);
}

void	textures_check(t_mlx *mlx)
{
	if (mlx->tex_n.width != 32 || mlx->tex_n.height != 32)
		mlx->error = ERROR_TEX_N;
	else if (mlx->tex_s.width != 32 || mlx->tex_s.height != 32)
		mlx->error = ERROR_TEX_S;
	else if (mlx->tex_e.width != 32 || mlx->tex_e.height != 32)
		mlx->error = ERROR_TEX_E;
	else if (mlx->tex_w.width != 32 || mlx->tex_w.height != 32)
		mlx->error = ERROR_TEX_W;
	else if (mlx->tex_sprite.width != 32 || mlx->tex_sprite.height != 32)
		mlx->error = ERROR_TEX_SPRITE;
	else
		return ;
	ft_error(mlx);
}

char	*make_textures_path(char *info, t_mlx *mlx)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	while (info[i] && info[i] != '.' && info[i] != '/' && !ft_isalpha(info[i]))
	{
		if (info[i] != ' ')
		{
			mlx->error = ERROR_TEX_NOT_PATH;
			break ;
		}
		i++;
	}
	if (!info[i] || mlx->error)
		mlx->error = ERROR_TEX_NOT_PATH;
	else if (!(path = (char*)malloc(sizeof(char) * (ft_strlen(info + i) + 1))))
		mlx->error = MALLOC_ERROR;
	if (mlx->error != SUCCESS)
		ft_error(mlx);
	while (info[i])
		path[j++] = info[i++];
	path[j] = 0;
	return (path);
}

void	make_textures(t_mlx mlx, t_ray ray)
{
	if (mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x] == 0xFF00FF)
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_sprite.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.ta];
	else if (ray.angle)
		ft_textures_angle(mlx, ray);
	else if (mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x]
			== 0xFFFFFF && mlx.map.x < mlx.hero.pos_y - 6)
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_w.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.tx];
	else if (mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x]
			== 0x00FF00 && mlx.map.x > mlx.hero.pos_y - 5)
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_e.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.tx];
	else if (mlx.map.y > mlx.hero.pos_x - 5)
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_s.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
	else
		mlx.game.data[(ray.height + (int)ray.line_o) * mlx.win_width
			+ (int)ray.i] = mlx.tex_n.data[(int)mlx.tex_pos.ty * 32
			+ (int)mlx.tex_pos.txy];
}
