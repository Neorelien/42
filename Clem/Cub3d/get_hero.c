/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:05:42 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/13 23:35:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		get_hero_second(char **map, t_mlx *mlx, t_map *card, int hero)
{
	card->count_w = -1;
	while (map[card->count_h][++card->count_w] != 0)
	{
		if (ft_ispos(map[card->count_h][card->count_w], mlx))
		{
			hero++;
			mlx->hero.pos_y = card->count_w * 64 - 1;
			while (++mlx->hero.pos_y < 64 * (card->count_w) + 10)
			{
				mlx->hero.pos_x = card->count_h * 64 - 1;
				while (++mlx->hero.pos_x < 64 * (card->count_h) + 10)
					mlx->img.data[(int)mlx->hero.pos_x * mlx->map.size_width
					+ (int)mlx->hero.pos_y] = 0xFF0000;
			}
		}
	}
	return (hero);
}

t_mlx	get_hero(char **map, t_mlx mlx)
{
	t_map	card;
	int		hero;

	hero = 0;
	card.count_h = -1;
	while (map[++card.count_h][0] != 0)
	{
		if (card.count_h > mlx.win_height && !hero)
		{
			mlx.error = ERROR_NO_HERO;
			ft_error(&mlx);
		}
		if (hero > 1)
		{
			mlx.error = TOO_MUCH_HERO;
			ft_error(&mlx);
		}
		hero = get_hero_second(map, &mlx, &card, hero);
	}
	mlx.hero.pos_x -= 1;
	mlx.hero.pos_y -= 1;
	mlx.hero.pdx = cos(mlx.hero.pos_a) * 5;
	mlx.hero.pdy = sin(mlx.hero.pos_a) * 5;
	return (mlx);
}
