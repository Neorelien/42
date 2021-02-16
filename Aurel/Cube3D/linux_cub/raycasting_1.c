/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:07:12 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/13 14:50:07 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

void		yes_we_touch(t_data *mlx, int *ex_i, int i)
{
	mlx->ray_touch_sprite = malloc(sizeof(int) * 2);
	mlx->ray_touch_sprite[0] = 1;
	mlx->ray_touch_sprite[1] = i;
	*ex_i = 0;
}

int			write_pixel(t_data *mlx, int *i, int move_x, int move_y)
{
	static int	ex_i;
	int			*temp;
	int			count;

	count = 0;
	*i = pos(mlx, ft_x(*i, mlx) + move_x, ft_y(*i, mlx) + move_y);
	if (mlx->data[*i] == mlx->rgb_floor && (ex_i = ex_i + 1))
		return (1);
	if (mlx->data[*i] == mlx->rgb_wall && (ex_i = ex_i + 1))
		return (0);
	if (mlx->ray_touch_sprite == NULL)
		yes_we_touch(mlx, &ex_i, *i);
	else if (ex_i > 1)
	{
		temp = malloc(sizeof(int) * (mlx->ray_touch_sprite[0] + 2));
		temp[0] = mlx->ray_touch_sprite[0] + 1;
		while (mlx->ray_touch_sprite[0] - ++count >= 0)
			temp[count] = mlx->ray_touch_sprite[count];
		free(mlx->ray_touch_sprite);
		temp[count] = *i;
		mlx->ray_touch_sprite = temp;
		ex_i = 0;
	}
	return (1);
}

void		rc_b(t_data *mlx, int *i, int *loop)
{
	if (cos(mlx->direction) >= 0)
		*loop = write_pixel(mlx, i, 1, 0);
	else
		*loop = write_pixel(mlx, i, -1, 0);
}

void		rc_a(t_data *mlx, int *i, int *loop)
{
	if (sin(mlx->direction) >= 0)
		*loop = write_pixel(mlx, i, 0, -1);
	else
		*loop = write_pixel(mlx, i, 0, 1);
}

int			ft_cast_ray(t_data *mlx)
{
	int		i;
	int		count;
	int		loop;

	count = 1;
	i = mlx->start_looking;
	loop = 1;
	if (mlx->ray_touch_sprite != NULL)
		free(mlx->ray_touch_sprite);
	mlx->ray_touch_sprite = NULL;
	while (loop)
	{
		if (ft_y_move(sin(mlx->direction), count))
		{
			if (ft_x_move(cos(mlx->direction), count))
				rc(mlx, &i, &loop);
			else
				rc_a(mlx, &i, &loop);
		}
		else if (ft_x_move(cos(mlx->direction), count++))
			rc_b(mlx, &i, &loop);
	}
	ft_reset_ft();
	return (i);
}
