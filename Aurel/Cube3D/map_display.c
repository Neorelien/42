/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:44:16 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/18 14:27:34 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3D_utils.h"

int	ft_init_mlx(t_data *mlx)
{
	if ((mlx->mlx_ptr = mlx_init()) == NULL)
		return (1);
	if ((mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
					mlx->element.x, mlx->element.y, "Cube3D")) == NULL)
		return (1);
	return (0);
}

int	ft_put_map(t_data *mlx)
{
	int y;
	int x;
	int ratio;
	int	county;
	int countx;

	ratio = 50;
	x = 0;
	y = 0;
	while (mlx->map[y]!= NULL)
	{
		while (mlx->map[y][x] == '1')
		{
			countx = (x + 1) * ratio;
			county = (y + 1) * ratio;
			while (countx - (x * ratio) >= 0)
			{
				while (county - (y * ratio) >= 0)
				{
					mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, countx, county, 0255255000);
					county--;
				}
				countx--;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int ft_map_display(t_data *mlx)
{
	if (ft_init_mlx(mlx))
		return (1);
	if (ft_put_map(mlx))
		return (1);
	return (0);
}

