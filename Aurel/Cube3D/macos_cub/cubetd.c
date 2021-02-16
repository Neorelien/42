/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubetd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:40 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/14 00:00:10 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int				ft_map_size_sup(int i, char **line, int fd, int nxt_line)
{
	while (ft_map_element(line))
	{
		free(*line);
		nxt_line = get_next_line(fd, line);
		if (nxt_line == -1)
		{
			free(line);
			return (-1);
		}
	}
	free(*line);
	while (nxt_line > 0)
	{
		nxt_line = get_next_line(fd, line);
		i++;
		free(*line);
	}
	free(line);
	close(fd);
	return (i);
}

static int		ft_map_size(char **argv, t_data *mlx)
{
	int		i;
	int		fd;
	char	**line;
	int		nxt_line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if ((line = malloc(sizeof(char*))) == NULL)
		return (clean_exit("malloc", mlx));
	nxt_line = get_next_line(fd, line);
	if (nxt_line == -1)
	{
		free(line);
		return (-1);
	}
	return (ft_map_size_sup(i, line, fd, nxt_line));
}

int				ft_maping(char **argv, t_data *mlx, int map_size)
{
	int		i;
	int		fd;
	char	**line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if ((line = malloc(sizeof(char*))) == NULL)
		return (clean_exit("malloc", mlx));
	while (get_next_line(fd, line) && ft_map_element(line))
		free(*line);
	mlx->map[i++] = *line;
	mlx->x_dd = ft_strlen(*line);
	while (i < map_size)
		maping_sup(fd, line, mlx, &i);
	mlx->map[i] = NULL;
	free(line);
	close(fd);
	if (ft_check_map(mlx->map))
		return (clean_exit("map is not right", mlx));
	return (0);
}

int				ft_map_init(int argc, char **argv, t_data *mlx)
{
	int map_size;

	if (ft_check_argv(argv, argc, mlx))
		return (clean_exit("argument", mlx));
	if (ft_get_elements(argv, mlx))
		return (clean_exit("elements in map file", mlx));
	map_size = ft_map_size(argv, mlx);
	mlx->y_dd = map_size + 2;
	if ((mlx->map = malloc(sizeof(char*) * (map_size + 1))) == NULL)
		return (clean_exit("malloc", mlx));
	if (ft_maping(argv, mlx, map_size))
		return (clean_exit("someting is wrong with the map", mlx));
	return (0);
}

int				main(int argc, char **argv)
{
	t_data				mlx;

	mlx.amplitude = 7;
	ft_null_init(&mlx);
	if (ft_map_init(argc, argv, &mlx))
		return (clean_exit("map", &mlx));
	if (ft_display_init(&mlx))
		return (clean_exit("display", &mlx));
	mlx_hook(mlx.td_win_ptr, 2, 0, &ft_player_move, &mlx);
	mlx_hook(mlx.td_win_ptr, 17, 0, &cross_clean_exit, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
