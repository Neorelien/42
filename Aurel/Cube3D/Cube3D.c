/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:40 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/15 23:03:10 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3D_utils.h"


int	ft_check_map(char **map)
{
	return (0);	
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

int			ft_check_elements(char **line)
{
	if (line[0][0] == 'R')
		return (2);
	if (line[0][0] == 'F')
		return (3);
	if (line[0][0] == 'C')
		return (4);
	if (line[0][0] == 'S')
		return (5);
	if (line[0][0] == 'N' && line[0][1] == 'O')
		return (6);
	if (line[0][0] == 'S' && line[0][1] == 'O')
		return (7);
	if (line[0][0] == 'E' && line[0][1] == 'A')
		return (8);
	if (line[0][0] == 'W' && line[0][1] == 'E')
		return (9);
	return (-1);
}

int			ft_map_element(char **line)
{
	static int	count;

	if (line[0][0] != 0 && count < 8)
	{
		count++;
		return (ft_check_elements(line));
	}
	if (count < 8)
		return (1);
	if (line[0][0] == 0)
		return (1);
	count = 0;
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
	return (0);
}

int			ft_elem_resolution(char **line, t_data *mlx)
{
	char	**coordinates;
	char	*newline;
	
	newline = ft_strtrim(*line, "R");
	free(*line);
	coordinates = ft_split(newline, ' ');
	free(newline);
	mlx->element.x = ft_atoi(coordinates[0]);
	mlx->element.y = ft_atoi(coordinates[1]);
	printf("%d| %d|", mlx->element.x, mlx->element.y);
	return (0);
}

int			ft_read_elem(char **line, t_data *mlx, int element)
{
	if (element == 2)
		return(ft_elem_resolution(line, mlx));
	return (1);
}

int			ft_get_elements(char **argv, t_data *mlx)
{
	int		fd;
	char	**line;
	int		element;

	fd = open(argv[1], O_RDONLY);
	if ((line = malloc(sizeof(char*))) == NULL)
		return (1);
	if (get_next_line(fd, line) == -1)
		return (1);
	while ((element = ft_map_element(line) != 0))
	{
		if (element == -1)
			return (1);
		if (ft_read_elem(line, mlx, element))
			return (1);
		if (get_next_line(fd, line) == ( - 1 || 0 ))
			return (1);
	}
	while (get_next_line(fd, line) > 0)
		free(*line);
	close(fd);
	free(line);
	free(*line);
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
	ft_maping(argv, mlx, map_size);
	if (ft_check_map(mlx->map))
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
		printf("%s\n", mlx.map[t++]);
	printf("%s\n", mlx.map[t]);
	ft_free_mlx(&mlx);
	return (0);
}
