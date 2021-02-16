/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:48:38 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 00:06:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	check_map_third(t_map *card, char **map, t_mlx *mlx)
{
	if (map[card->temp_y][card->temp_x] != '0' && map[card->temp_y]
		[card->temp_x] != '1' && !(ft_ispos(map[card->temp_y][card->temp_x]
		, mlx)) && map[card->temp_y][card->temp_x] != '2')
		mlx->error = MAP_ERROR;
	card->temp_x = card->x - 1;
	card->temp_y = card->y + 1;
	if (map[card->temp_y][card->temp_x] != '0' && map[card->temp_y]
		[card->temp_x] != '1' && !(ft_ispos(map[card->temp_y][card->temp_x]
		, mlx)) && map[card->temp_y][card->temp_x] != '2')
		mlx->error = MAP_ERROR;
	card->temp_x = card->x + 1;
	card->temp_y = card->y - 1;
	if (map[card->temp_y][card->temp_x] != '0' && map[card->temp_y]
		[card->temp_x] != '1' && !(ft_ispos(map[card->temp_y][card->temp_x]
		, mlx)) && map[card->temp_y][card->temp_x] != '2')
		mlx->error = MAP_ERROR;
	card->temp_x = card->x - 1;
	card->temp_y = card->y - 1;
	if (map[card->temp_y][card->temp_x] != '0' && map[card->temp_y]
		[card->temp_x] != '1' && !(ft_ispos(map[card->temp_y][card->temp_x]
		, mlx)) && map[card->temp_y][card->temp_x] != '2')
		mlx->error = MAP_ERROR;
	if (mlx->error == MAP_ERROR)
		ft_error(mlx);
}

void	check_map_second(t_map *card, char **map, t_mlx *mlx)
{
	card->temp_y = card->y;
	card->temp_x = card->x;
	while (map[card->temp_y][card->x] != '1' && card->temp_y >= 0)
		card->temp_y--;
	if (card->temp_y < 0)
		mlx->error = MAP_ERROR;
	card->temp_y = card->y;
	while (map[card->temp_y][card->x] != '1' && map[card->temp_y][card->x] != 0)
		card->temp_y++;
	if (map[card->temp_y][card->x] == 0)
		mlx->error = MAP_ERROR;
	while (map[card->y][card->temp_x] != '1' && card->temp_x >= 0)
		card->temp_x--;
	if (card->temp_x < 0)
		mlx->error = MAP_ERROR;
	card->temp_x = card->x;
	while (map[card->y][card->temp_x] != '1' && map[card->y][card->temp_x] != 0)
		card->temp_x++;
	if (map[card->y][card->temp_x] == 0)
		mlx->error = MAP_ERROR;
	card->temp_x = card->x + 1;
	card->temp_y = card->y + 1;
}

t_mlx	check_map(char **map, t_mlx mlx)
{
	t_map card;

	card.y = 0;
	while (map[card.y][0])
	{
		card.x = -1;
		while (map[card.y][++card.x])
		{
			if ((card.y == 0 && (map[card.y][card.x] == '0' || map[card.y]
				[card.x] == '2')) || !ft_ismap(map[card.y][card.x]))
			{
				mlx.error = MAP_ERROR;
				ft_error(&mlx);
			}
			else if (map[card.y][card.x] == '0' || map[card.y][card.x] == '2')
			{
				check_map_second(&card, map, &mlx);
				check_map_third(&card, map, &mlx);
			}
		}
		if (mlx.error == MAP_ERROR)
			ft_error(&mlx) ;
		card.y++;
	}
	return (mlx);
}

void	count_size_map_second(t_mlx *mlx, char *line)
{
	if (line)
	{
		if (line[0] && ft_ismaj(line[0]))
			mlx->map.size_height = 0;
		else if (line[0])
		{
			mlx->map.size_height++;
			if (mlx->map.size_width < (int)ft_strlen(line))
				mlx->map.size_width = ft_strlen(line);
		}
	}
}

void	count_size_map(char *path, t_mlx *mlx)
{
	char	*line;
	int		ret;
	int		fd;

	ret = 1;
	mlx->map.size_width = 0;
	mlx->map.size_height = 0;
	fd = open(path, O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			mlx->error = 1;
			ft_error(mlx);
		}
		if (ret)
		{
			count_size_map_second(mlx, line);
		}
		free(line);
	}
	mlx->map.size_height *= 64;
	mlx->map.size_width *= 64;
	close(fd);
}
