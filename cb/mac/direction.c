/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:40 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/17 20:57:03 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

char			get_card_point(int orientation, t_data *mlx, int i)
{
	if (mlx->data[i + 1] == mlx->rgb_wall)
		orientation += 2;
	if (mlx->data[i - 1] == mlx->rgb_wall)
		orientation += 4;
	if (mlx->data[i - mlx->x] == mlx->rgb_wall)
		orientation += 8;
	if (mlx->data[i + mlx->x] == mlx->rgb_wall)
		orientation += 16;
	if (orientation == 14)
		return ('N');
	if (orientation == 22)
		return ('S');
	if (orientation == 28)
		return ('W');
	if (orientation == 26)
		return ('E');
	return (0);
}

int				next_ray(t_data *mlx, int i)
{
	if (!(i))
		mlx->direction += (60.00000 / mlx->nb_ray) / 57.2959191;
	else
		mlx->direction -= (60.00000 / mlx->nb_ray) / 57.2959191;
	return (ft_cast_ray(mlx));
}

char			ft_orientation(t_data *mlx, int i)
{
	float		temp;
	char		res;
	int			range[2];
	int			pos[2];

	if (get_card_point(0, mlx, i))
		return (get_card_point(0, mlx, i));
	temp = mlx->direction;
	pos[1] = i;
	pos[0] = i;
	while (pos[0] == i)
		pos[0] = next_ray(mlx, 0);
	range[0] = sqrt(pow(ft_variance(ft_y(mlx->start_looking, mlx),
					ft_y(pos[0], mlx)), 2) + pow(ft_variance(
					ft_x(mlx->start_looking, mlx), ft_x(pos[0], mlx)), 2));
	mlx->direction = temp;
	while (pos[1] == i)
		pos[1] = next_ray(mlx, 1);
	range[1] = sqrt(pow(ft_variance(ft_y(mlx->start_looking, mlx),
					ft_y(pos[1], mlx)), 2) + pow(ft_variance(
					ft_x(mlx->start_looking, mlx), ft_x(pos[1], mlx)), 2));
	orientation_suppor(pos, range, &i);
	res = ft_orientation(mlx, i);
	mlx->direction = temp;
	return (res);
}

void			ft_look(t_data *mlx)
{
	int			i;
	float		start;
	int			count;

	count = 0;
	mlx->nb_ray = mlx->x_td / 1;
	start = 30 * RAD;
	mlx->initial_direction = mlx->direction;
	mlx->direction -= start;
	mlx->start_sprite = 1;
	mlx->ray_touch_sprite = NULL;
	while (mlx->nb_ray - count++)
	{
		i = ft_cast_ray(mlx);
		mlx->cardinal_point = ft_orientation(mlx, i);
		ft_3d(mlx, i);
		mlx->direction += (60.00000 / mlx->nb_ray) / 57.2959191;
	}
	mlx->direction = mlx->initial_direction;
	mlx->ex_card_point = 0;
}

int				ft_init_direction(t_data *mlx)
{
	int x_player;
	int y_player;

	x_player = 0;
	y_player = 0;
	ft_browse(mlx, &x_player, &y_player);
	mlx->start_looking = pos(mlx, (x_player * mlx->ratio_map) + mlx->ratio_map
			/ 2, (y_player * mlx->ratio_map) + mlx->ratio_map / 2);
	mlx->ex_direction[0] = 0;
	ft_sprite_pos(mlx);
	ft_look(mlx);
	return (0);
}
