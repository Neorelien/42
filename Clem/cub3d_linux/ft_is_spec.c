/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:59:05 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:13:56 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		ft_ispos(char c, t_mlx *mlx)
{
	if (c == 'N')
		mlx->hero.pos_a = RAD * 0;
	else if (c == 'E')
		mlx->hero.pos_a = RAD * 270;
	else if (c == 'W')
		mlx->hero.pos_a = RAD * 90;
	else if (c == 'S')
		mlx->hero.pos_a = RAD * 180;
	else
		return (0);
	return (1);
}

int		ft_issprite(t_mlx mlx)
{
	if (mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x] == 0xFF00FF)
		return (0);
	return (1);
}

int		ft_iswall(t_mlx mlx)
{
	if (mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x] == 0xFFFFFF)
		return (0);
	if (mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x] == 0xFFFF00)
		return (0);
	if (mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x] == 0x00FF00)
		return (0);
	if (mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x] == 0x00FFFF)
		return (0);
	return (1);
}

char	ft_isangle(t_mlx mlx, t_ray ray)
{
	if ((mlx.img.data[(mlx.map.y + 1) * mlx.map.size_width + mlx.map.x]
		== 0x000000 || mlx.img.data[(mlx.map.y + 1) * mlx.map.size_width
		+ mlx.map.x] == 0x0000FF) && mlx.img.data[mlx.map.y
		* mlx.map.size_width + mlx.map.x] == 0xFFFFFF)
		ray.angle = 's';
	else if ((mlx.img.data[(mlx.map.y - 1) * mlx.map.size_width + mlx.map.x]
		== 0x000000 || mlx.img.data[(mlx.map.y - 1) * mlx.map.size_width
		+ mlx.map.x] == 0x0000FF) && mlx.img.data[mlx.map.y
		* mlx.map.size_width + mlx.map.x] == 0xFFFFFF)
		ray.angle = 'w';
	else if ((mlx.img.data[(mlx.map.y + 1) * mlx.map.size_width + mlx.map.x]
		== 0x000000 || mlx.img.data[(mlx.map.y + 1)
		* mlx.map.size_width + mlx.map.x] == 0x0000FF)
		&& mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x]
		== 0x00FF00)
		ray.angle = 'a';
	else if ((mlx.img.data[(mlx.map.y - 1) * mlx.map.size_width + mlx.map.x]
		== 0x000000 || mlx.img.data[(mlx.map.y - 1)
		* mlx.map.size_width + mlx.map.x] == 0x0000FF)
		&& mlx.img.data[mlx.map.y * mlx.map.size_width + mlx.map.x]
		== 0x00FF00)
		ray.angle = 'q';
	else
		return (0);
	return (ray.angle);
}

int		ft_ismap(char c)
{
	if (c == '2' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ')
		return (1);
	return (0);
}
