/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:20:11 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:15:02 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		deal_key(int key, t_mlx *mlx)
{
	if (key == 13 || (key >= 0 && key <= 2))
		*mlx = hero_new_pos(key, *mlx);
	else if (key <= 126 && key >= 123)
		*mlx = hero_turn(key, *mlx);
	else if (key == 53)
		exit_game(mlx);
	ft_refresh_sprite(mlx);
	frame(*mlx);
	return (0);
}
