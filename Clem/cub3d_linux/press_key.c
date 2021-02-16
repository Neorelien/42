/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:20:11 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/16 21:37:48 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		deal_key(int key, t_mlx *mlx)
{
	if (key == 122 || key == 115 || key == 113 || key == 100)
		*mlx = hero_new_pos(key, *mlx);
	else if (key == 65361 || key == 65363)
		*mlx = hero_turn(key, *mlx);
	else if (key == 65307)
		exit_game(mlx);
	else
			return (0);
	ft_refresh_sprite(mlx);
	frame(*mlx);
	return (0);
}
