/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:11:19 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/13 16:26:45 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

float			ft_change_pos_in_sprite(int i, t_data *mlx)
{
	float res;

	res = sqrt(pow(ft_variance(ft_y(mlx->sprite_pos[mlx->ex_sprite_text][3],
						mlx), ft_y(i, mlx)), 2)
			+ pow(ft_variance(ft_x(mlx->sprite_pos[mlx->ex_sprite_text][3],
						mlx), ft_x(i, mlx)), 2));
	return (res);
}

int				ft_research(int i, t_data *mlx)
{
	int count;

	count = 0;
	while (mlx->sprite_pos[count][5] != mlx->data[i])
		count++;
	mlx->ex_sprite_text = count;
	return (count);
}

float			ft_pos_in_sprite(t_data *mlx, int i)
{
	int		count;
	float	res;

	count = ft_research(i, mlx);
	res = sqrt(pow(ft_variance(ft_y(mlx->sprite_pos[count][3], mlx),
					ft_y(i, mlx)), 2)
			+ pow(ft_variance(ft_x(mlx->sprite_pos[count][3], mlx),
					ft_x(i, mlx)), 2));
	return (res);
}

int				ft_no_in_sprite(t_data *mlx, int texture)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < mlx->sprite_size[0] * mlx->sprite_size[1])
	{
		if (mlx->xpm_data[4][i] == texture)
			return (0);
		i++;
	}
	return (1);
}

int				ft_put_texture_sprite(t_data *mlx, int i,
		long double county, int *y)
{
	int				texture;
	static float	pos_in_sprite = -1.00000;
	static int		ex_i;
	int				x_res;
	int				y_res;

	if (mlx->start_sprite == 1)
	{
		pos_in_sprite = -1;
		mlx->start_sprite = 0;
	}
	if (pos_in_sprite == -1 || i <= (ex_i - (mlx->x * mlx->ratio_map)) ||
			i >= ex_i + (mlx->x * mlx->ratio_map))
		pos_in_sprite = ft_pos_in_sprite(mlx, i);
	else if (i != ex_i)
		pos_in_sprite = ft_change_pos_in_sprite(i, mlx);
	x_res = (pos_in_sprite / mlx->ratio_map) * (mlx->sprite_size[0]);
	y_res = (county - y[0]) / (y[1] - y[0]) * (mlx->sprite_size[1]);
	if (x_res > 63)
		x_res = 63;
	texture = mlx->xpm_data[4][y_res * mlx->sprite_size[0] + x_res];
	ex_i = i;
	return (texture);
}
