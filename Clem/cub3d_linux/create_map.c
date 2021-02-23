/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 02:53:16 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/23 00:03:00 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_map(char *map, t_mlx *mlx)
{
	int i;

	i = 0;
	if (!map)
		return (0);
	if (map[i] == ' ' || map[i] == '1')
	{
		while (map[i])
		{
			if (map[i] != ' ' && map[i] != '0' && map[i] != '1'
				&& map[i] != '2' && map[i] != 'N' && map[i] != 'S'
				&& map[i] != 'E' && map[i] != 'W')
			{
				if (mlx->inmap == 1)
					mlx->wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_copy_map(char *map, t_mlx *mlx)
{
	static int	i = 0;
	int			j;

	j = 0;
	mlx->card[i] = NULL;
	if (!(mlx->card[i] = malloc(sizeof(char) * (mlx->sizeline + 1))))
		return (0);
	while (map[j])
	{
		mlx->card[i][j] = map[j];
		j++;
	}
	while (j <= mlx->sizeline)
		mlx->card[i][j++] = '\0';
	i++;
	return (0);
}
