/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 03:43:50 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/23 00:22:53 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window_second(t_mlx *mlx)
{
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->max_width, &mlx->max_height);
	if (mlx->max_width < mlx->win_width || mlx->super_width == 1)
		mlx->win_width = mlx->max_width;
	if (mlx->max_height < mlx->win_height || mlx->super_height == 1)
		mlx->win_height = mlx->max_height;
	if (mlx->win_width < 100)
		mlx->win_width = 100;
	if (mlx->win_height < 100)
		mlx->win_height = 100;
}

int		window(t_mlx *mlx, int count, char *res)
{
	while (!ft_isnum(res[count]) && res[count])
		if (mlx->win_width == 0)
			while (ft_isnum(res[++count]) && res[count])
			{
				if (mlx->win_width > 100000)
					mlx->super_width = 1;
				mlx->win_width = mlx->win_width * 10 + res[count] - 48;
			}
		else if (mlx->win_height == 0)
			while (ft_isnum(res[++count]) && res[count])
			{
				if (mlx->win_height > 100000)
					mlx->super_height = 1;
				mlx->win_height = mlx->win_height * 10 + res[count] - 48;
			}
		else
		{
			mlx->error = ERROR_IN_PARS;
			break ;
		}
	return (1);
}
