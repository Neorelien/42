/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:03:13 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/16 20:23:28 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	window_third(t_mlx *mlx)
{
	if (mlx->max_width < mlx->win_width)
		mlx->win_width = mlx->max_width;
	if (mlx->max_height < mlx->win_height)
		mlx->win_height = mlx->max_height;
	if (mlx->win_width < 100)
		mlx->win_width = 100;
	if (mlx->win_height < 100)
		mlx->win_height = 100;
}

int		window_second(t_mlx *mlx, int count, char *res)
{
	count = 0;
	if (res[count] != 'R')
	{
		mlx->win_width = 800;
		mlx->win_height = 600;
		return (0);
	}
	mlx->win_width = 0;
	mlx->win_height = 0;
	while (res[count])
	{
		while (!ft_isnum(res[count]) && res[count])
			if (mlx->win_width == 0)
				while (ft_isnum(res[++count]) && res[count])
					mlx->win_width = mlx->win_width * 10 + res[count] - 48;
			else
				while (ft_isnum(res[++count]) && res[count])
					mlx->win_height = mlx->win_height * 10 + res[count] - 48;
	}
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->max_width, &mlx->max_height);
	window_third(mlx);
	return (1);
}

t_mlx	window(char *path, t_mlx mlx)
{
	int		count;
	char	*res;
	int		fd;

	count = 1;
	fd = open(path, O_RDONLY);
	while (count)
	{
		count = get_next_line(fd, &res);
		if (*res == 'R')
			break ;
		if (count == -1)
		{
			mlx.error = READ_ERROR;
			ft_error(&mlx);
		}
		free(res);
	}
	close(fd);
	if (window_second(&mlx, count, res))
		free(res);
	return (mlx);
}
