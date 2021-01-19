/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:40 by Aurelien          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/17 22:43:48 by Aurelien         ###   ########.fr       */
=======
/*   Updated: 2021/01/18 16:23:21 by awery            ###   ########.fr       */
>>>>>>> 03be7f6ffed5aeaaadf3795f7da062e3db56ad0d
/*                                                                            */
/* ************************************************************************** */

#include "Cube3D_utils.h"


int	ft_check_map(char **map)
{
	int x;
	int y;
	int check;

	check = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (ft_map_is_0(map, y, x, &check))
				return (1);
			if (ft_map_is_close(map, y, x, &check))
				return (1);
			if (ft_map_is_2(map, y, x, &check))
				return (1);
			if (ft_map_is_O(map, y, x, &check))
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	if (check == 6)
		return (0);
	return (1);	
}

int	ft_check_argv(char **argv, int argc)
{
	int i;

	i = 0;
	if (argc != 2)
		return (1);
	while (argv[1][i] != '.')
	{
		if (argv[1][i] == '\0')
			return (1);
		i++;
	}
	i++;
	if (argv[1][i++] != 'c')
		return (1);
	if (argv[1][i++] != 'u')
		return (1);
	if (argv[1][i] != 'b')
		return (1);
	return (0);
}

static int	ft_map_size(char **argv)
{
	int		i;
	int		fd;
	char	**line;
	int		nxt_line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = malloc(sizeof(char*));
	nxt_line = get_next_line(fd, line);
	if (nxt_line == -1)
		return (-1);
	while (ft_map_element(line))
	{
		free(*line);
		nxt_line = get_next_line(fd, line);
		if (nxt_line == -1)
			return (-1);
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

int		ft_maping(char **argv, t_data *mlx, int map_size)
{
	int		i;
	int		fd;
	char	**line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if ((line = malloc(sizeof(char*))) == NULL)
		return (1);
	while (get_next_line(fd, line) && ft_map_element(line)) 
		free(*line);
	mlx->map[i++] = *line;
	while (i < map_size)
	{
		get_next_line(fd, line);
		mlx->map[i] = *line;
		i++;
	}
	mlx->map[i] = NULL;
	free(line);
	close(fd);
	if (ft_check_map(mlx->map))
		return (1);
	return (0);
}

int			ft_map_init(int argc, char **argv, t_data *mlx)
{
	int map_size;

	if (ft_check_argv(argv, argc))
		return (1);
	if (ft_get_elements(argv, mlx))
		return (1);
	map_size = ft_map_size(argv);
	if ((mlx->map = malloc(sizeof(char*) * (map_size + 1))) == NULL)
		return (1);
	if (ft_maping(argv, mlx, map_size))
		return (1);
	if (ft_map_display(mlx))
		return (1);
	return (0);
}

void	ft_free_mlx(t_data *xlm)
{
	int i;

	i = 0;
	while (xlm->map[i])
	{
		free(xlm->map[i]);
		i++;
	}
	free(xlm->map[i]);
}

int		ft_error(char *error)
{
	printf("%s", error);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data	mlx;
	int		 t = 0;

	if (ft_map_init(argc, argv, &mlx))
		return (ft_error("Error map"));
	while (mlx.map[t])
	{
		printf("%s\n", mlx.map[t++]);
	}
	printf("%s\n", mlx.map[t]);
	printf("%d %d", mlx.element.x, mlx.element.y);
<<<<<<< HEAD
=======

>>>>>>> 03be7f6ffed5aeaaadf3795f7da062e3db56ad0d
	mlx_loop(mlx.mlx_ptr);
	ft_free_mlx(&mlx);
	return (0);
}
