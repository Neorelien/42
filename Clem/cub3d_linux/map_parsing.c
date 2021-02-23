/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:35:38 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 21:16:39 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_res_color(char *info, t_mlx *mlx)
{
	int		i;

	i = 0;
	mlx->i = 1;
	if (mlx->sizeline > 0 && (mlx->tex_n.path == NULL || mlx->tex_s.path
		== NULL || mlx->tex_w.path == NULL || mlx->tex_e.path == NULL
		|| mlx->tex_sprite.path == NULL))
		mlx->error = ERROR_IN_PARS;
	if ((mlx->tex_n.path != NULL || mlx->tex_s.path != NULL || mlx->tex_w.path
		!= NULL || mlx->tex_e.path != NULL || mlx->tex_sprite.path
		!= NULL) && (mlx->win_width == 0 || mlx->win_height == 0))
		mlx->error = ERROR_IN_PARS;
	if (info[i] == 'R')
	{
		if (mlx->win_width != 0 && mlx->win_height != 0)
			mlx->error = ERROR_IN_PARS;
		window(mlx, 0, info);
	}
	else if (info[i] == 'F' || info[i] == 'C')
		ft_make_color_cf(info, mlx);
}

void	ft_map(char *info, t_mlx *mlx)
{
	int		i;

	i = 0;
	if (ft_is_map(info, mlx) == 1)
	{
		if (mlx->color_f == -1 || mlx->color_c == -1 ||
			mlx->tex_n.path == NULL ||
			mlx->tex_e.path == NULL || mlx->tex_w.path == NULL ||
			mlx->tex_w.path == NULL || mlx->tex_sprite.path == NULL)
			mlx->error = ERROR_IN_PARS;
		if ((int)ft_strlen(info) > mlx->sizeline)
			mlx->sizeline = ft_strlen(info);
		mlx->nblines = mlx->nblines + 1;
	}
}

void	ft_parsing_map(char *map_path, t_mlx *mlx)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(map_path, O_RDONLY);
	if (!(mlx->card = malloc(sizeof(char*) * (mlx->nblines + 1))))
		return ;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (mlx->inmap == 1 && ret != 0 && *str == 0)
			mlx->error = MAP_ERROR;
		else if ((mlx->inmap = ft_is_map(str, mlx)) == 1)
		{
			mlx->count++;
			ft_copy_map(str, mlx);
		}
		free(str);
	}
	close(fd);
	if (mlx->error != SUCCESS)
		ft_error(mlx, "Error in map parsing");
	ft_init_sprite(mlx);
}

void	ft_get_info_pars(t_mlx *mlx, int fd, int count, char *info)
{
	while (count != 0)
	{
		count = get_next_line(fd, &info);
		ft_res_color(info, mlx);
		ft_textures(info, mlx);
		ft_map(info, mlx);
		free(info);
		if (mlx->error != SUCCESS || count < 0)
		{
			while (count > 0)
			{
				count = get_next_line(fd, &info);
				free(info);
			}
			ft_error(mlx, "La partie parsing detecte une error\n");
		}
	}
}

void	ft_parsing_info(char *map_path, t_mlx *mlx)
{
	int		fd;
	int		count;
	char	*info;

	count = 1;
	info = NULL;
	if ((fd = open(map_path, O_DIRECTORY)) != -1)
		ft_error(mlx, "Invalid directory\n");
	if ((fd = open(map_path, O_RDONLY)) == -1)
		ft_error(mlx, "Invalid file type\n");
	mlx->error = 0;
	ft_get_info_pars(mlx, fd, count, info);
	close(fd);
	if (mlx->sizeline == 0 || mlx->nblines == 0)
		ft_error(mlx, "Map absente\n");
	ft_parsing_map(map_path, mlx);
	ft_mlx(mlx);
}
