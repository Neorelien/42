/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:55:31 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 20:22:18 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_make_header(t_mlx *mlx, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * mlx->win_width * mlx->win_height;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &mlx->win_width, 4);
	write(fd, &mlx->win_height, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &mlx->game.bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	ft_save(t_mlx *mlx)
{
	int	fd;
	int	x;
	int	y;

	y = mlx->win_height;
	if ((fd = open("./screen.bmp", O_WRONLY | O_CREAT, S_IRWXU)) == -1)
		ft_error(mlx, "Open screen.bmp\n");
	ft_make_header(mlx, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < mlx->win_width)
		{
			write(fd, &mlx->game.data[y * mlx->game.size_l / 4 + x], 4);
			x++;
		}
		y--;
	}
	ft_exit(mlx);
}

void	ft_save_screen(t_mlx *mlx, char **argv)
{
	if (argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's'
		&& argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e')
		mlx->save = 1;
	else
	{
		write(1, "Error\nArguments Invalids\n", 25);
		exit(EXIT_FAILURE);
	}
}
