/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:48:49 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/17 13:55:44 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void		get_pixel_third(t_mlx *mlx, t_map *card)
{
	if (card->x == card->count_h * 64 && mlx->img.data[card->x
			* mlx->map.size_width + card->y] == 0xFFFF00)
	{
		if (mlx->img.data[card->x * mlx->map.size_width + (card->y - 1)]
			== 0xFFFF00)
			mlx->img.data[card->x * mlx->map.size_width
				+ (card->y - 1)] = 0x00FFFF;
		mlx->img.data[card->x * mlx->map.size_width + card->y] = 0x00FFFF;
	}
}

void		get_pixel_second(t_mlx *mlx, t_map *card)
{
	card->x = card->count_h * 64 - 1;
	while (++card->x < 64 * (card->count_h + 1))
	{
		if (card->x == 0 && card->y == 0)
			mlx->img.data[card->x * mlx->map.size_width + card->y] = 0x00FF00;
		else if (card->y == card->count_w * 64)
		{
			if (mlx->img.data[card->x * mlx->map.size_width + (card->y - 1)]
					== 0xFFFFFF)
			{
				mlx->img.data[card->x * mlx->map.size_width
					+ (card->y - 1)] = 0xFFFF00;
				mlx->img.data[card->x * mlx->map.size_width
					+ card->y] = 0xFFFF00;
			}
			else
				mlx->img.data[card->x * mlx->map.size_width
					+ card->y] = 0x00FF00;
		}
		else if (card->y == (card->count_w + 1) * 64 - 1)
			mlx->img.data[card->x * mlx->map.size_width + card->y] = 0xFFFFFF;
		else
			mlx->img.data[card->x * mlx->map.size_width + card->y] = 0xFFFF00;
		get_pixel_third(mlx, card);
	}
}

t_mlx		get_pixel(char **map, t_mlx mlx)
{
	t_map card;

	mlx = check_map(map, mlx);
	if (mlx.error != SUCCESS)
		ft_error(&mlx);
	mlx.nb_sprite = 0;
	card.count_h = -1;
	while (map[++card.count_h][0] != 0)
	{
		card.count_w = -1;
		while (map[card.count_h][++card.count_w] != 0)
		{
			if (map[card.count_h][card.count_w] == '2')
				mlx.nb_sprite++;
			else if (map[card.count_h][card.count_w] == '1')
			{
				card.y = card.count_w * 64 - 1;
				while (++card.y < 64 * (card.count_w + 1))
				{
					get_pixel_second(&mlx, &card);
				}
			}
		}
	}
	return (mlx);
}

t_mlx		get_map_second(char **map, t_mlx mlx, int fd)
{
	mlx = get_textures_data(mlx);
	if (mlx.error != SUCCESS)
		ft_error(&mlx);
	mlx = get_pixel(map, mlx);
	if (mlx.error != SUCCESS)
		ft_error(&mlx);
	mlx = get_hero(map, mlx);
	if (mlx.error != SUCCESS)
		ft_error(&mlx);
	mlx = get_sprite(map, mlx);
	if (mlx.error != SUCCESS)
		ft_error(&mlx);
	frame(mlx);
	if (mlx.error != SUCCESS)
		ft_error(&mlx);
	close(fd);
	return (mlx);
}

t_mlx		get_map(char *path, t_mlx mlx)
{
	int		fd;
	char	**map;
	int		count;
	int		i;

	i = 0;
	count = 1;
	if (!(map = (char**)malloc(sizeof(char*) * (mlx.map.size_height + 1))))
	{
		mlx.error = MALLOC_ERROR;
		ft_error(&mlx);
	}
	fd = open(path, O_RDONLY);
	while (count)
	{
		if ((count = get_next_line(fd, &map[i])) == -1)
			mlx.error = READ_ERROR;
		else if (count)
			i = take_info(map, &mlx, i, 0);
		if (mlx.error != SUCCESS)
			ft_error(&mlx);
	}
	mlx = get_map_second(map, mlx, fd);
	ft_double_pointer_free(map, i, 1);
	return (mlx);
}
