/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:40 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/15 15:27:54 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3D_utils.h"

/*
   int	ft_check_map(char **map)
   {
   return (0);	
   }

   int	ft_check_argv(char **argv)
   {
   int i;

   i = 0;
   while (argv[1][i] != '.')
   {
   if (argv[1][i] == '\0')
   return (1);
   i++;
   }
   if (argv[1][i++] == 'c')
   return (1);
   if (argv[1][i++] == 'u')
   return (1);
   if (argv[1][i] == 'c')
   return (1);
   return (0);
   }*/

int			ft_is_map_descriptor(char **line)
{
	if (line[0][0] == '0')
		return (0);
	if (line[0][0] == '1')
		return (0);
	if (line[0][0] == '2')
		return (0);
	if (line[0][0] == ' ')
		return (0);
	if (line[0][0] == 'E')
		return (0);
	if (line[0][0] == 'W')
		return (0);
	if (line[0][0] == 'S')
		return (0);
	if (line[0][0] == 'N')
		return (0);
	return (1);
}

static int	ft_map_size(char **argv)
{
	int		i;
	int		fd;
	char	**line;
	int		nxt_line;

	int u = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = malloc(sizeof(char*));
	nxt_line = get_next_line(fd, line);
	while (ft_is_map_descriptor(line))
	{
		nxt_line = get_next_line(fd, line);
		free(*line);
	}
	while (nxt_line > 0)
	{
		nxt_line = get_next_line(fd, line);
		i++;
		free(*line);
	}
	free(line);
	close (fd);
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
	while (get_next_line(fd, line) && ft_is_map_descriptor(line)) 
		free(*line);
	free(*line);
	while (i < map_size)
	{
		get_next_line(fd, line);
		mlx->map[i] = *line;
		i++;
	}
	mlx->map[i] = NULL;
	free(line);
	close (fd);
	return (0);
}

int			ft_map_init(int argc, char **argv, t_data *mlx)
{
	int map_size;

	//	if (ft_check_arg(argv, argc))
	//		return (1);
	map_size = ft_map_size(argv);
	if ((mlx->map = malloc(sizeof(char*) * (map_size + 1))) == NULL)
		return (1);
	ft_maping(argv, mlx, map_size);
	//	if (ft_check_map(mlx->map))
	//		return (1);
	return (0);	
}

int main(int argc, char **argv)
{
	t_data	mlx;

	if (ft_map_init(argc, argv, &mlx))
		return (1);
	printf("%s", mlx.map[0]);
	return (0);
}
