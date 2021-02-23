/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:12:41 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 19:17:54 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_press_key(int key, t_mlx *mlx)
{
	if (key == 119)
		mlx->hero.forward = 1;
	else if (key == 115)
		mlx->hero.back = 1;
	else if (key == 97)
		mlx->hero.right = 1;
	else if (key == 100)
		mlx->hero.left = 1;
	else if (key == 65363)
		mlx->hero.r_left = 1;
	else if (key == 65361)
		mlx->hero.r_right = 1;
	else if (key == 65307)
		ft_exit(mlx);
	return (1);
}

int		ft_release_key(int key, t_mlx *mlx)
{
	if (key == 119)
		mlx->hero.forward = 0;
	else if (key == 115)
		mlx->hero.back = 0;
	else if (key == 97)
		mlx->hero.right = 0;
	else if (key == 100)
		mlx->hero.left = 0;
	else if (key == 65363)
		mlx->hero.r_left = 0;
	else if (key == 65361)
		mlx->hero.r_right = 0;
	return (0);
}
