/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:26:27 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/12 14:34:36 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

void			ft_nb_sprite(t_data *mlx)
{
	int y;
	int x;

	y = 0;
	mlx->nb_sprite = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == '2')
				mlx->nb_sprite++;
			x = x + 1;
		}
		y = y + 1;
	}
}

int				ft_rgb_attribut(t_data *mlx)
{
	static int	r;
	static int	g;
	static int	b;
	int			res;

	if (r < 255)
		r++;
	else
	{
		r = 0;
		if (g < 255)
			g++;
		else
		{
			g = 0;
			if (b < 255)
				b++;
			else
				b = 0;
		}
	}
	res = ft_rgb(r, g, b);
	if (res == mlx->rgb_wall || res == mlx->rgb_floor || res == mlx->rgb_sky)
		res = ft_rgb_attribut(mlx);
	return (res);
}

void			player_get_pos_dir(int *x_temp, int x, t_data *mlx, int angle)
{
	*x_temp = x;
	mlx->direction = angle * RAD;
}

void			sprite_get_pos_dir(int y, int x, t_data *mlx)
{
	static int count;

	if ((mlx->sprite_pos[count] = malloc(sizeof(int) * 6)) == NULL)
		clean_exit("malloc", mlx);
	mlx->sprite_pos[count][0] = x;
	mlx->sprite_pos[count][1] = y;
	mlx->sprite_pos[count][5] = ft_rgb_attribut(mlx);
	count = count + 1;
}

void			ft_browse(t_data *mlx, int *x, int *y)
{
	int		temp[2];

	ft_nb_sprite(mlx);
	if ((mlx->sprite_pos = malloc(sizeof(int*) * mlx->nb_sprite)) == NULL)
		clean_exit("malloc", mlx);
	while (mlx->map[*y] && ((*x = 0) == 0))
	{
		while (mlx->map[*y][*x])
		{
			if (mlx->map[*y][*x] == '2')
				sprite_get_pos_dir(*y, *x, mlx);
			if (mlx->map[*y][*x] == 'N' && (temp[0] = *y))
				player_get_pos_dir(&temp[1], *x, mlx, 90);
			if (mlx->map[*y][*x] == 'S' && (temp[0] = *y))
				player_get_pos_dir(&temp[1], *x, mlx, 270);
			if (mlx->map[*y][*x] == 'W' && (temp[0] = *y))
				player_get_pos_dir(&temp[1], *x, mlx, 180);
			if (mlx->map[*y][*x] == 'E' && (temp[0] = *y))
				player_get_pos_dir(&temp[1], *x, mlx, 0);
			*x = *x + 1;
		}
		*y = *y + 1;
	}
	*y = temp[0];
	*x = temp[1];
}
