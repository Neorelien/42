/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:38:14 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/23 00:20:51 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_third(t_map *card, char **map, t_mlx *mlx)
{
	if (map[card->temp_y][card->temp_x] != '0' && map[card->temp_y]
		[card->temp_x] != '1' && !(ft_ispos(map[card->temp_y][card->temp_x]
		, mlx)) && map[card->temp_y][card->temp_x] != '2')
		ft_error(mlx, "Wrong char in the pratice map part");
	card->temp_x = card->x - 1;
	card->temp_y = card->y + 1;
	if (map[card->temp_y][card->temp_x] != '0' && map[card->temp_y]
		[card->temp_x] != '1' && !(ft_ispos(map[card->temp_y][card->temp_x]
		, mlx)) && map[card->temp_y][card->temp_x] != '2')
		ft_error(mlx, "Wrong char in the pratice map part");
	card->temp_x = card->x + 1;
	card->temp_y = card->y - 1;
	if (map[card->temp_y][card->temp_x] != '0' && map[card->temp_y]
		[card->temp_x] != '1' && !(ft_ispos(map[card->temp_y][card->temp_x]
		, mlx)) && map[card->temp_y][card->temp_x] != '2')
		ft_error(mlx, "Wrong char in the pratice map part");
	card->temp_x = card->x - 1;
	card->temp_y = card->y - 1;
	if (map[card->temp_y][card->temp_x] != '0' && map[card->temp_y]
		[card->temp_x] != '1' && !(ft_ispos(map[card->temp_y][card->temp_x]
		, mlx)) && map[card->temp_y][card->temp_x] != '2')
		ft_error(mlx, "Wrong char in the pratice map part");
}

void	check_map_second(t_map *card, char **map, t_mlx *mlx)
{
	card->temp_y = card->y;
	card->temp_x = card->x;
	while (map[card->temp_y][card->x] != '1' && card->temp_y >= 0)
		card->temp_y--;
	if (card->temp_y < 0)
		ft_error(mlx, "Map have a hole in the wall");
	card->temp_y = card->y;
	while (card->temp_y < mlx->nblines && map[card->temp_y][card->x] != '1')
		card->temp_y++;
	if (card->temp_y == mlx->nblines)
		ft_error(mlx, "Map have a hole in the wall");
	while (map[card->y][card->temp_x] != '1' && card->temp_x >= 0)
		card->temp_x--;
	if (card->temp_x < 0)
		ft_error(mlx, "Map have a hole in the wall");
	card->temp_x = card->x;
	while (map[card->y][card->temp_x] != '1' && map[card->y][card->temp_x] != 0)
		card->temp_x++;
	if (map[card->y][card->temp_x] == 0)
		ft_error(mlx, "Map have a hole in the wall");
	card->temp_x = card->x + 1;
	card->temp_y = card->y + 1;
}

void	ft_map_hero(t_mlx *mlx, char c, int y, int x)
{
	if (mlx->start != 0)
		ft_error(mlx, "COOP MOD COMING SOON");
	mlx->start = (int)c;
	mlx->hero.pos_y = y;
	mlx->hero.pos_x = x;
	mlx->card[y][x] = '0';
}

t_mlx	check_map(char **map, t_mlx mlx)
{
	t_map card;

	card.y = 0;
	while (card.y < mlx.nblines)
	{
		card.x = -1;
		while (map[card.y][++card.x])
		{
			if ((card.y == 0 && (map[card.y][card.x] == '0' || map[card.y]
				[card.x] == '2')))
				ft_error(&mlx, "Map have a hole in the wall");
			else if (!ft_ismap(map[card.y][card.x]) || mlx.wrongcharmap != 0)
				ft_error(&mlx, "Wrong char in map");
			else if (map[card.y][card.x] == '0' || map[card.y][card.x] == '2' ||
				ft_ispos(map[card.y][card.x], &mlx) == 1)
			{
				check_map_second(&card, map, &mlx);
				check_map_third(&card, map, &mlx);
			}
			if (ft_ispos(map[card.y][card.x], &mlx) == 1)
				ft_map_hero(&mlx, map[card.y][card.x], card.y, card.x);
		}
		card.y++;
	}
	return (mlx);
}
