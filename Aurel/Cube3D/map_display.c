/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:44:16 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/18 16:23:24 by awery            ###   ########.fr       */
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
	y = 0;
	while (mlx->map[y]!= NULL)
	{
	x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == '1')
			{
				countx = (x + 1) * ratio;
				while (countx - (x * ratio) >= 0)
				{
					county = (y + 1) * ratio;
					while (county - (y * ratio) >= 0)
					{
						mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, countx, county, 0255255000);
						county--;
					}
					countx--;
				}
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
	void *image;
	image = mlx_new_image(mlx->mlx_ptr, mlx->element.x, mlx->element.y);
	void *newin;
	newin = mlx_new_window(mlx->mlx_ptr, mlx->element.x, mlx->element.y, "cubetest");
	mlx_put_image_to_window(mlx->mlx_ptr, newin, image, mlx->element.x, mlx->element.y);
	return (0);
}

