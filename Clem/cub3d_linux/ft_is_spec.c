/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:59:05 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 02:22:09 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_ismap(char c)
{
	if (c == '2' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ')
		return (1);
	return (0);
}

int		ft_ispos(char c, t_mlx *mlx)
{
	if (c == 'N')
	{
		mlx->ray.dir_y = -1;
		mlx->ray.plan_x = 0.66;
	}
	else if (c == 'E')
	{
		mlx->ray.dir_x = 1;
		mlx->ray.plan_y = 0.66;
	}
	else if (c == 'W')
	{
		mlx->ray.dir_x = -1;
		mlx->ray.plan_y = -0.66;
	}
	else if (c == 'S')
	{
		mlx->ray.dir_y = 1;
		mlx->ray.plan_x = -0.66;
	}
	else
		return (0);
	return (1);
}
