/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:28:04 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/14 00:08:52 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

static void		ft_sup_2(t_data *mlx, int *i, int count, int *wall)
{
	if (ft_x_move(cos(mlx->direction), count))
	{
		if (sin(mlx->direction) >= 0)
		{
			if (cos(mlx->direction) >= 0)
				*wall = write_pixel_move(mlx, i, 1, -1);
			else
				*wall = write_pixel_move(mlx, i, -1, -1);
		}
		else
		{
			if (cos(mlx->direction) >= 0)
				*wall = write_pixel_move(mlx, i, 1, 1);
			else
				*wall = write_pixel_move(mlx, i, -1, 1);
		}
	}
	else
	{
		if (sin(mlx->direction) >= 0)
			*wall = write_pixel_move(mlx, i, 0, -1);
		else
			*wall = write_pixel_move(mlx, i, 0, 1);
	}
}

void			ft_move_start_looking(t_data *mlx)
{
	int i;
	int	count;
	int	wall;

	wall = 1;
	count = 1;
	i = mlx->start_looking;
	while (count <= mlx->amplitude && wall)
	{
		if (ft_y_move(sin(mlx->direction), count))
			ft_sup_2(mlx, &i, count, &wall);
		else
		{
			if (ft_x_move(cos(mlx->direction), count))
			{
				if (cos(mlx->direction) >= 0)
					wall = write_pixel_move(mlx, &i, 1, 0);
				else
					wall = write_pixel_move(mlx, &i, -1, 0);
			}
		}
		count++;
	}
	ft_reset_ft();
}

int				ft_move(t_data *mlx, int direction)
{
	float temp;

	temp = mlx->direction;
	mlx->direction += direction * RAD;
	ft_move_start_looking(mlx);
	mlx->direction = temp;
	return (0);
}

static void		pl_sup_1(t_data *mlx, int key, int *first_move)
{
	float temp;

	if (key == 124)
	{
		if (*first_move == 0 && (*first_move = 1))
			ft_del_ray(mlx);
		mlx->direction -= 0.0523599;
		if (mlx->direction < 0)
			mlx->direction += 360 * RAD;
	}
	if (key == 53)
		clean_exit(NULL, mlx);
	if (mlx->ex_direction[1] != mlx->direction)
	{
		temp = mlx->direction;
		mlx->direction = mlx->ex_direction[1];
		mlx->ex_direction[0] = 1;
		ft_sprite_pos(mlx);
		mlx->direction = temp;
		mlx->ex_direction[0] = 0;
		ft_sprite_pos(mlx);
	}
	ft_look(mlx);
}

int				ft_player_move(int key, t_data *mlx)
{
	static int		first_move;

	mlx->ex_direction[1] = mlx->direction;
	if (key == 1)
		ft_move(mlx, 180);
	if (key == 13)
		ft_move(mlx, 0);
	if (key == 2)
		ft_move(mlx, 270);
	if (key == 0)
		ft_move(mlx, 90);
	if (key == 123)
	{
		if (first_move == 0)
		{
			first_move = 1;
			ft_del_ray(mlx);
		}
		mlx->direction += 0.0523599;
		if (mlx->direction > 360 * RAD)
			mlx->direction -= 360 * RAD;
	}
	pl_sup_1(mlx, key, &first_move);
	return (0);
}
