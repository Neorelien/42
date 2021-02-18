/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:07:08 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/18 18:52:21 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int		ft_rgb(int r, int g, int b)
{
	int		result;

	result = 0;
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
	{
		printf("error RGB values\n");
		return (-1);
	}
	result = b + (g * 256) + (r * 65536);
	return (result);
}

void	dis_sprite_player(t_data *mlx, int *count, int x, int y)
{
	count[0] = (x + 1) * mlx->ratio_map;
	while (count[0] - (x * mlx->ratio_map) >= 0)
	{
		count[1] = (y + 1) * mlx->ratio_map;
		while (count[1] - (y * mlx->ratio_map) >= 0)
		{
			mlx->data[pos(mlx, count[0], count[1])] = mlx->rgb_floor;
			count[1]--;
		}
		count[0]--;
	}
}

void	dis_wall(t_data *mlx, int *count, int x, int y)
{
	count[0] = (x + 1) * mlx->ratio_map;
	while (count[0] - (x * mlx->ratio_map) >= 0)
	{
		count[1] = (y + 1) * mlx->ratio_map;
		while (count[1] - (y * mlx->ratio_map) >= 0)
		{
			mlx->data[pos(mlx, count[0], count[1])] = mlx->rgb_wall;
			count[1]--;
		}
		count[0]--;
	}
}

int		ft_display_cub(t_data *mlx)
{
	int y;
	int x;
	int	count[2];

	y = 0;
	while (mlx->map[y] != NULL)
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == '1')
				dis_wall(mlx, count, x, y);
			else if (mlx->map[y][x] == '0' || mlx->map[y][x] == 'N' ||
					mlx->map[y][x] == 'S' || mlx->map[y][x] == 'W' ||
					mlx->map[y][x] == 'E' || mlx->map[y][x] == '2')
				dis_sprite_player(mlx, count, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
