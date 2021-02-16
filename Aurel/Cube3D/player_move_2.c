/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:23:46 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/12 19:27:10 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

static int	ft_research(int i, t_data *mlx)
{
	int count;

	count = 0;
	while (count < mlx->nb_sprite)
	{
		if (mlx->sprite_pos[count][5] == mlx->data[i])
			return (0);
		count++;
	}
	return (1);
}

int			write_pixel_move(t_data *mlx, int *i, int move_x, int move_y)
{
	*i = pos(mlx, ft_x(*i, mlx) + move_x, ft_y(*i, mlx) + move_y);
	if (mlx->data[*i] != mlx->rgb_wall && ft_research(*i, mlx))
		mlx->start_looking = *i;
	else
		return (0);
	return (1);
}

void		ft_del_ray(t_data *mlx)
{
	int i;

	i = 0;
	while (i < (mlx->x * mlx->y))
	{
		if (mlx->data[i] != mlx->rgb_floor && mlx->data[i] != mlx->rgb_wall
				&& mlx->data[i] != ft_rgb(0, 0, 0))
			mlx->data[i] = mlx->rgb_floor;
		i++;
	}
}
