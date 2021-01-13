/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:12:11 by awery             #+#    #+#             */
/*   Updated: 2021/01/13 11:49:05 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>

int main()
{
	void	*mlx;
	void	*windows_identifier;

	mlx = mlx_init();
	
	windows_identifier =  mlx_new_window(mlx, 500, 500, "bonjour");
	mlx_pixel_put(mlx, windows_identifier, 0, 0, 1000);
	mlx_loop (mlx);
}
