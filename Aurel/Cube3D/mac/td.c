/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   td.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:04:38 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/19 15:45:56 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

void			ft_put_sprite(int *x, int *y, t_data *mlx, int i)
{
	long double	county;
	int			texture;

	while (x[0] > x[1])
	{
		x[0]--;
		county = 0.00000;
		while (county < mlx->y_td)
		{
			if (county >= y[0] && county < y[1])
			{
				texture = ft_put_texture_sprite(mlx, i, county, y);
				if (texture != 0)
					mlx->td_data[pos_td(mlx, x[0], county)] = texture;
			}
			else
			{
				if (county < y[0])
					mlx->td_data[pos_td(mlx, x[0], county)] = mlx->rgb_sky;
				else
					mlx->td_data[pos_td(mlx, x[0], county)] = mlx->rgb_floor;
			}
			county++;
		}
	}
}

void			ft_wall_td(int i, int *count, t_data *mlx)
{
	int x[2];
	int	y[2];

	x[0] = (mlx->x_td / mlx->nb_ray) * *count;
	x[1] = (mlx->x_td / mlx->nb_ray) * ((*count) - 1);
	y[0] = (mlx->y_td - mlx->wall_height) / 2;
	y[1] = mlx->y_td - y[0];
	ft_put_colomn(x, y, mlx, i);
}

void			ft_sprite_td(int i, int *count, t_data *mlx)
{
	int x[2];
	int	y[2];

	x[0] = (mlx->x_td / mlx->nb_ray) * *count;
	x[1] = (mlx->x_td / mlx->nb_ray) * ((*count) - 1);
	y[0] = (mlx->y_td - mlx->wall_height) / 2;
	y[1] = mlx->y_td - y[0];
	ft_put_sprite(x, y, mlx, i);
}

static void		supp_1(t_data *mlx, float *range, int *count, int *utils)
{
	if (mlx->ray_touch_sprite != NULL)
	{
		while (mlx->ray_touch_sprite[0] - utils[1] >= 0)
		{
			utils[2] = mlx->ray_touch_sprite[mlx->ray_touch_sprite[0] -
				utils[1] + 1];
			*range = sqrt(pow(ft_variance(ft_y(mlx->start_looking, mlx),
							ft_y(utils[2], mlx)), 2) + pow(ft_variance(
							ft_x(mlx->start_looking, mlx),
							ft_x(utils[2], mlx)), 2));
			*range = *range *
				cos(ft_floatcomp(mlx->direction, mlx->initial_direction));
			mlx->wall_height = (mlx->ratio_map * mlx->y_td) / *range;
			ft_sprite_td(utils[2], count, mlx);
			utils[1]++;
			mlx->start_sprite = 1;
		}
		free(mlx->ray_touch_sprite);
		mlx->ray_touch_sprite = NULL;
	}
	else
		mlx->start_sprite = 1;
}

void			ft_3d(t_data *mlx, int i)
{
	float		range;
	static int	count;
	int			utils[3];

	utils[2] = i;
	utils[1] = 1;
	if (count < 1)
		count = mlx->nb_ray;
	utils[0] = mlx->x_td / mlx->nb_ray;
	range = sqrt(pow(ft_variance(ft_y(mlx->start_looking, mlx),
					ft_y(utils[2], mlx)), 2) + pow(ft_variance(
					ft_x(mlx->start_looking, mlx), ft_x(utils[2], mlx)), 2));
	range *= cos(ft_floatcomp(mlx->direction, mlx->initial_direction));
	mlx->wall_height = (mlx->ratio_map * mlx->y_td) / range;
	ft_wall_td(utils[2], &count, mlx);
	supp_1(mlx, &range, &count, utils);
	if (count > 1)
		count = count - 1;
	else
		count = mlx->nb_ray;
}
