/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:27:56 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:12:11 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	init_color_fc(t_mlx mlx)
{
	int runner;

	runner = 0;
	while (runner < mlx.win_width * mlx.win_height / 2)
		mlx.game.data[runner++] = mlx.ceil_color;
	while (runner < mlx.win_width * mlx.win_height)
		mlx.game.data[runner++] = mlx.floor_color;
}
