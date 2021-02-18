/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:44:16 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/17 22:40:49 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int	pos(t_data *mlx, int x, int y)
{
	return ((y * mlx->x) + x);
}

int	pos_td(t_data *mlx, int x, int y)
{
	return ((y * mlx->x_td) + x);
}

int	ft_mlx_init(t_data *mlx)
{
	int b_p;
	int end;
	int s_l;

	if ((mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->x, mlx->y)) == NULL)
		return (1);
	if ((mlx->data = (int*)mlx_get_data_addr(mlx->img_ptr,
					&b_p, &s_l, &end)) == NULL)
		return (1);
	return (0);
}

int	loading_init(t_data *mlx)
{
	if (mlx->x < mlx->x_dd * mlx->ratio_map)
		mlx->x = mlx->x_dd * mlx->ratio_map;
	if (mlx->y < mlx->y_dd * mlx->ratio_map)
		mlx->y = mlx->y_dd * mlx->ratio_map;
	if (ft_mlx_init(mlx))
		return (clean_exit("init mlx", mlx));
	if (ft_display_cub(mlx))
		return (clean_exit("init 2D", mlx));
	if (ft_3d_win_init(mlx))
		return (clean_exit("init 3D", mlx));
	if (ft_init_xmp(mlx))
		return (clean_exit("xmp file", mlx));
	if (ft_init_direction(mlx))
		return (clean_exit("raycasting error", mlx));
	if (mlx->save_pic)
		save_to_bmp(mlx);
	if ((mlx->td_win_ptr = mlx_new_window(mlx->mlx_ptr,
					mlx->x_td, mlx->y_td, "Cube3D")) == NULL)
		return (1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->td_win_ptr,
			mlx->td_img_ptr, 0, 0);
	return (0);
}

int	ft_display_init(t_data *mlx)
{
	int	x_max;
	int	y_max;

	mlx->ratio_map = 64;
	mlx->rgb_wall = ft_rgb(252, 207, 147);
	mlx->rgb_ray = ft_rgb(47, 61, 127);
	if ((mlx->mlx_ptr = mlx_init()) == NULL)
		return (1);
	mlx_get_screen_size(mlx->mlx_ptr, &x_max, &y_max);
	if (x_max < mlx->x)
	{
		mlx->x_td = x_max;
		mlx->x = x_max;
	}
	else
		mlx->x_td = mlx->x;
	if (y_max < mlx->y)
	{
		mlx->y_td = y_max;
		mlx->y = y_max;
	}
	else
		mlx->y_td = mlx->y;
	loading_init(mlx);
	return (0);
}
