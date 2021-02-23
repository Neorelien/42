/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 00:02:12 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 20:36:31 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_info(char *tex_path, t_textures *textures, t_mlx *mlx)
{
	if (textures->malloc == 1)
	{
		mlx->error = ERROR_IN_PARS;
		if (tex_path != NULL)
			free(tex_path);
	}
	else
		textures->path = tex_path;
	textures->malloc = 1;
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
			mlx->error = ERROR_IN_PARS;
			break ;
		}
		i++;
	}
	if (!info[i] || mlx->error)
		mlx->error = ERROR_IN_PARS;
	else if (!(path = (char*)malloc(sizeof(char) * (ft_strlen(info + i) + 1))))
		mlx->error = ERROR_IN_PARS;
	if (mlx->error != SUCCESS)
		return (NULL);
	while (info[i])
		path[j++] = info[i++];
	path[j] = 0;
	return (path);
}

void	ft_textures(char *info, t_mlx *mlx)
{
	if (info[0] == 'N' && info[1] == 'O')
		find_info(make_textures_path(info + 2, mlx), &mlx->tex_n, mlx);
	else if (info[0] == 'S' && info[1] == 'O')
		find_info(make_textures_path(info + 2, mlx), &mlx->tex_s, mlx);
	else if (info[0] == 'W' && info[1] == 'E')
		find_info(make_textures_path(info + 2, mlx), &mlx->tex_w, mlx);
	else if (info[0] == 'E' && info[1] == 'A')
		find_info(make_textures_path(info + 2, mlx), &mlx->tex_e, mlx);
	else if (info[0] == 'S')
		find_info(make_textures_path(info + 2, mlx), &mlx->tex_sprite, mlx);
	else if (info[0] != 'N' && info[0] != 'S' && info[0] != 'W' && info[0]
		!= 'E' && info[0] != 'R' && info[0] != 'F' && info[0] != 'C'
		&& info[0] > 65 && info[0] < 122)
		mlx->error = ERROR_IN_PARS;
}

void	ft_init_texture(t_mlx *mlx)
{
	if (mlx->ray.side == 0 && mlx->ray.raydir_x < 0)
		mlx->texture = mlx->tex_n;
	if (mlx->ray.side == 0 && mlx->ray.raydir_x >= 0)
		mlx->texture = mlx->tex_s;
	if (mlx->ray.side == 1 && mlx->ray.raydir_y < 0)
		mlx->texture = mlx->tex_w;
	if (mlx->ray.side == 1 && mlx->ray.raydir_y >= 0)
		mlx->texture = mlx->tex_e;
	if (mlx->ray.side == 0)
		mlx->wall_x = mlx->ray.pos_y + mlx->ray.dist * mlx->ray.raydir_y;
	else
		mlx->wall_x = mlx->ray.pos_x + mlx->ray.dist * mlx->ray.raydir_x;
	mlx->wall_x -= floor((mlx->wall_x));
}
