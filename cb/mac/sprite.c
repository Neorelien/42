/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:48:56 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/17 20:58:09 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

void		write_pixel_sprite(t_data *mlx, int *i, int move_x, int move_y)
{
	*i = pos(mlx, ft_x(*i, mlx) + move_x, ft_y(*i, mlx) + move_y);
	if (mlx->data[*i] != mlx->rgb_wall)
	{
		if (mlx->ex_direction[0])
			mlx->data[*i] = mlx->rgb_floor;
		else
			mlx->data[*i] = mlx->sprite_pos[mlx->count_sprite][5];
	}
	else
		printf("wrong sprite's width\n");
}

int			ft_sprite_width(int i, t_data *mlx, int nb_sprite)
{
	int range;
	int	del_point;

	del_point = 0;
	range = sqrt(pow(ft_variance(ft_y(mlx->sprite_pos[nb_sprite][2], mlx),
					ft_y(i, mlx)), 2) + pow(ft_variance(ft_x(mlx->sprite_pos
						[nb_sprite][2], mlx), ft_x(i, mlx)), 2));
	if (mlx->direction > 0 && mlx->direction <= 45 * RAD)
		del_point = 0;
	if (mlx->direction > 45 * RAD && mlx->direction <= 120 * RAD)
		del_point = -1;
	if (mlx->direction > 120 * RAD && mlx->direction <= 200 * RAD)
		del_point = -1;
	if (range > 30 - del_point)
		return (0);
	return (1);
}

void		ft_look_sprite(t_data *mlx, int sprite_nb)
{
	float		temp;

	temp = mlx->direction;
	mlx->direction += 90 * RAD;
	if (mlx->direction > 360 * RAD)
		mlx->direction -= 360 * RAD;
	mlx->sprite_pos[sprite_nb][3] = ft_cast_ray_sprite(mlx, sprite_nb);
	mlx->direction -= 180 * RAD;
	if (mlx->direction < 0)
		mlx->direction += 360 * RAD;
	mlx->sprite_direction = mlx->direction;
	mlx->sprite_pos[sprite_nb][4] = ft_cast_ray_sprite(mlx, sprite_nb);
	mlx->direction = temp;
}

void		ft_sprite_pos(t_data *mlx)
{
	int count;

	count = 0;
	while (count < mlx->nb_sprite)
	{
		mlx->sprite_pos[count][2] = pos(mlx, (mlx->sprite_pos[count][0] *
					mlx->ratio_map) + mlx->ratio_map / 2,
				(mlx->sprite_pos[count][1] * mlx->ratio_map)
				+ mlx->ratio_map / 2);
		ft_look_sprite(mlx, count);
		count++;
	}
}
